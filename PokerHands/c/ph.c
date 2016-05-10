// poker hands c soln for code eval by steven a dunn

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int num;
    char suit;
} Card;

typedef struct {
    Card *array;
    size_t used;
    size_t size;
} Array;

typedef struct {
    int *array;
    size_t used;
    size_t size;
} IntArray;

void init(Array*, size_t);
void insert(Array*, Card);
void sort(Array*);

void init_int(IntArray*, size_t);
void insert_int(IntArray*, int);

Card make_card(char*);
int convert(char);
int rank(Array*);
int is_royal_flush(Array*);
int is_same_suit(Array*);
void get_vals(Array*, Array*);
int is_straight_flush(Array*);
int are_consecutive_vals(Array*);
int is_four_of_a_kind(Array*);





/*
string compare(int, int, Hand, Hand);
vector<int> get_counts(Hand);
bool is_full_house(Hand);
bool is_three_of_a_kind(Hand);
bool is_one_pair(Hand);
bool is_flush(Hand);
bool is_straight(Hand);
bool is_two_pairs(Hand);
int high_card(Hand);
*/




int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp)
    {
        char line[32];
        while (fgets(line, sizeof(line), fp))
        {
            Array hand1, hand2;
            int i, rank_1, rank_2;

            init(&hand1, 1);
            init(&hand2, 1);

            for(i = 0; i < 5; ++i)
            {
                token = strtok(NULL, " ");
                insert(&hand1, make_card(token));
            }

            for(i = 0; i < 5; ++i)
            {
                token = strtok(NULL, " ");
                insert(&hand2, make_card(token));
            }

            rank_1 = rank(hand1);
            rank_2 = rank(hand2);

            printf("%s \n", compare(rank_1, rank_2, hand1, hand2));
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (Card*)malloc(initSize * sizeof(Card));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array* arr, Card element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (Card*)realloc(arr->array, arr->size * sizeof(Card));
    }
    arr->array[arr->used++] = element;
}

void sort(Array* arr)
{
    for (int i = 1; i < arr->used; ++i)
        for (int j = 0; j < i; ++j)
            if (arr->array[i] < arr->array[j])
            {
                int temp = arr->array[i];
                arr->array[i] = arr->array[j];
                arr->array[j] = temp;
            }
}

void init_int(IntArray* arr, size_t initSize)
{
    arr->array = (int*)malloc(initSize * sizeof(int));
    arr->used = 0;
    arr->size = initSize;
}

void insert_int(Array* arr, int element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (int*)realloc(arr->array, arr->size * sizeof(int));
    }
    arr->array[arr->used++] = element;
}

Card make_card(char* token)
{
    Card card;
    card.num = convert(token[0]);
    card.suit = token[1];
    return card;
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

int rank(Array* hand)
{
    if (is_royal_flush(hand)) return 23;
    else if (is_straight_flush(hand)) return 22;
    else if (is_four_of_a_kind(hand)) return 21;
    else if (is_full_house(hand)) return 20;
    else if (is_flush(hand)) return 19;
    else if (is_straight(hand)) return 18;
    else if (is_three_of_a_kind(hand)) return 17;
    else if (is_two_pairs(hand)) return 16;
    else if (is_one_pair(hand)) return 15;
    else return high_card(hand);
}

int is_royal_flush(Array* hand)
{
    if (is_same_suit(hand))
    {
        int i, expected_val;
        Array vals;
        init(&vals, 1);

        get_vals(&vals, &hand);
        expected_val = 10;
        for (i = 0; i < vals.size; ++i)
        {
            if (vals.array[i] != expected_val)
                return 0;
            ++expected_val;
        }
        return 1;
    }
    return 0;
}

int is_same_suit(Array* hand)
{
    int suit, i;
    suit = hand.array[0].suit;
    for (i = 1; i < hand.size; ++i)
        if (hand.array[i].suit != suit)
            return 0;
    return 1;
}

void get_vals(Array* vals, Array* hand)
{
    int i;
    for (i = 0; i < hand.size; ++i)
        insert(&vals, hand.array[i].num);
    sort(&vals);
}

int is_straight_flush(Array* hand)
{
    if (is_same_suit(hand))
    {
        Array vals;
        init(&vals, 1)
        get_vals(&vals, &hand);
        if (are_consecutive_vals(&vals))
            return 1;
    }
    return 0;
}

int are_consecutive_vals(Array* vals)
{
    int val, i;

    val = vals.array[0];
    for (i = 1; i < vals.size; ++i)
    {
        if (vals.array[i] - 1 != val)
            return 0;
        val = vals.array[i];
    }
    return 1;
}

int is_four_of_a_kind(Array* hand)
{
    int i;
    IntArray counts;
    init_int(&count, 1);

    get_counts(&hand, &counts);
    for (i = 0; i < counts.size; ++i)
    {
        if (counts.array[i] == 4)
            return 1;
    }
    return 0;
}

void get_counts(Array* hand, IntArray* counts)
{
    int i;
    Array vals;
    init(&vals, 1)
    get_vals(&vals, &hand);
    for (i = 0; i < vals.size; ++i)
        insert_int(&counts, count(&vals, vals[i]));
    return counts;
}

int count(Array* vals, Card val)

/*
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
*/