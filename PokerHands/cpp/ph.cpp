// poker hands cpp soln for code eval by steven a dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::copy;
using std::count;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::max_element;
using std::pair;
using std::sort;
using std::string;
using std::vector;

typedef vector<pair<int, int>> Hand;

vector<string> tokenize(string);
Hand make_numeric(vector<string>);
int rank(Hand);
string compare(int, int, Hand, Hand);
int convert(char);
bool is_royal_flush(Hand);
vector<int> get_vals(Hand);
bool is_same_suit(Hand);
bool is_straight_flush(Hand);
bool are_consecutive_vals(vector<int>);
bool is_four_of_a_kind(Hand);
vector<int> get_counts(Hand);
bool is_full_house(Hand);
bool is_three_of_a_kind(Hand);
bool is_one_pair(Hand);
bool is_flush(Hand);
bool is_straight(Hand);
bool is_two_pairs(Hand);
int high_card(Hand);

int main (int argc, char* const argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
        {
            vector<string> hands = tokenize(line);

            vector<string> left(5);
            copy(hands.begin(), hands.begin() + 5, left.begin());

            vector<string> right(5);
            copy(hands.begin()+5, hands.end(), right.begin());

            Hand left_hand = make_numeric(left);
            Hand right_hand = make_numeric(right);

            int left_rank = rank(left_hand);
            int right_rank = rank(right_hand);

            cout << compare(left_rank, right_rank, left_hand, right_hand) << endl;
        }
        input_file.close();
    }
    return 0;
}

vector<string> tokenize(string line)
{
    vector<string> tokens;
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' '))
        tokens.push_back(token);
    return tokens;
}

Hand make_numeric(vector<string> hand)
{
    Hand numeric_hand;
    for (int i = 0; i < hand.size(); ++i)
    {
        string card = hand[i];
        pair<int, int> converted_card(convert(card[0]), card[1]);
        numeric_hand.push_back(converted_card);
    }
    return numeric_hand;
}

int rank(Hand numeric_hand)
{
    if (is_royal_flush(numeric_hand)) return 23;
    else if (is_straight_flush(numeric_hand)) return 22;
    else if (is_four_of_a_kind(numeric_hand)) return 21;
    else if (is_full_house(numeric_hand)) return 20;
    else if (is_flush(numeric_hand)) return 19;
    else if (is_straight(numeric_hand)) return 18;
    else if (is_three_of_a_kind(numeric_hand)) return 17;
    else if (is_two_pairs(numeric_hand)) return 16;
    else if (is_one_pair(numeric_hand)) return 15;
    else return high_card(numeric_hand);
}

string compare(int left_rank, int right_rank, Hand left_hand, Hand right_hand)
{
    if (left_rank > right_rank)
        return "left";
    else if (right_rank > left_rank)
        return "right";
    else
    {
        sort(left_hand.begin(), left_hand.end());
        sort(right_hand.begin(), right_hand.end());

        while (left_hand.size() > 0 || right_hand.size() > 0)
        {
            int left_high = high_card(left_hand);
            int right_high = high_card(right_hand);

            if (left_high > right_high)
                return "left";
            if (right_high > left_high)
                return "right";

            left_hand.pop_back();
            right_hand.pop_back();
        }
        return "none";
    }
}

int convert(char val)
{
    if (val == 'T') return 10;
    else if (val == 'J') return 11;
    else if (val == 'Q') return 12;
    else if (val == 'K') return 13;
    else if (val == 'A') return 14;
    else return val - '0';
}

bool is_royal_flush(Hand hand)
{
    if (is_same_suit(hand))
    {
        vector<int> vals = get_vals(hand);
        int expected_val = 10;
        for (int i = 0; i < vals.size(); ++i)
        {
            if (vals[i] != expected_val)
                return false;
            expected_val++;
        }
        return true;
    }
    return false;
}

vector<int> get_vals(Hand hand)
{
    vector<int> vals;
    for (int i = 0; i < hand.size(); ++i)
        vals.push_back(hand[i].first);
    sort(vals.begin(), vals.end());
    return vals;
}

bool is_same_suit(Hand hand)
{
    int suit = hand[0].second;
    for (int i = 1; i < hand.size(); ++i)
        if (hand[i].second != suit)
            return false;
    return true;
}

bool is_straight_flush(Hand hand)
{
    if (is_same_suit(hand))
    {
        vector<int> vals = get_vals(hand);
        if (are_consecutive_vals(vals))
            return true;
    }
    return false;
}

bool are_consecutive_vals(vector<int> vals)
{
    int val = vals[0];
    for (int i = 1; i < vals.size(); ++i)
    {
        if (vals[i] - 1 != val)
            return false;
        val = vals[i];
    }
    return true;
}

bool is_four_of_a_kind(Hand hand)
{
    vector<int> counts = get_counts(hand);
    for (int i = 0; i < counts.size(); ++i)
    {
        if (counts[i] == 4)
            return true;
    }
    return false;
}

vector<int> get_counts(Hand hand)
{
    vector<int> vals = get_vals(hand);
    vector<int> counts;
    for (int i = 0; i < vals.size(); ++i)
        counts.push_back(count(vals.begin(), vals.end(), vals[i]));
    return counts;
}

bool is_full_house(Hand hand)
{
    if (is_three_of_a_kind(hand) && is_one_pair(hand))
        return true;
    return false;
}

bool is_three_of_a_kind(Hand hand)
{
    vector<int> counts = get_counts(hand);
    for (int i = 0; i < counts.size(); ++i)
        if (counts[i] == 3)
            return true;
    return false;
}

bool is_one_pair(Hand hand)
{
    vector<int> counts = get_counts(hand);
    int pair_count = 0;
    for (int i = 0; i < counts.size(); ++i)
        if (counts[i] == 2)
            pair_count++;
    if (pair_count == 2)
        return true;
    return false;
}

bool is_flush(Hand hand)
{
    if (is_same_suit(hand))
        return true;
    return false;
}

bool is_straight(Hand hand)
{
    if (are_consecutive_vals(get_vals(hand)))
        return true;
    return false;
}

bool is_two_pairs(Hand hand)
{
    vector<int> counts = get_counts(hand);
    int pair_count = 0;
    for (int i = 0; i < counts.size(); ++i)
        if (counts[i] == 2)
            pair_count++;
    if (pair_count == 4)
        return true;
    return false;
}

int high_card(Hand hand)
{
    vector<int> vals = get_vals(hand);
    return *(max_element(vals.begin(), vals.end()));
}