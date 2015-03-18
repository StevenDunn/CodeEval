// simple calc soln in cpp for code eval by steven a dunn


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

bool replace(string&, const string&, const string&);
float evaluate(string);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
            cout << evaluate(line) << endl;
        input_file.close();
    }

    return 0;
}

bool replace(string& line, const string& from, const string& to)
{
    cout << from << " | " << to << endl;
    size_t start_pos = line.find(from);
    //cout << "start pos: " << start_pos << endl;
    if (start_pos == string::npos)
        return false;
    line.replace(start_pos, from.length(), to);
    return true;
}

float evaluate(string line)
{
    vector<string> calc_stack;
    while (replace(line, "-(", "0 - (")) {}
    cout << line << endl;
    while (replace(line, "(", " ( ")) {}
    //while (replace(line, ")", " ) ")) {}
    //while (replace(line, "^", " ^ ")) {}
    //while (replace(line, "/", " / ")) {}
    //cout << line << endl;
    return 0.0;
}

/*

def evaluate(line):

    calc_stack = []

    # various replacements to munge the input
    line = line.replace("-(", "0 - (")
    line = line.replace("(", " ( ")
    line = line.replace(")", " ) ")
    line = line.replace("^", " ^ ")
    line = line.replace("/", " / ")

    line = line.split()

    i = 0
    while i < len(line):
        if line[i] == "(":
            paren_expr, final_paren = find_paren_expr(i, line)
            calc_stack.append(evaluate(paren_expr))
            i = final_paren
        elif line[i] != ")":
            calc_stack.append(line[i])
        i += 1

    return compute(calc_stack)


FIVE_PLACES = decimal.Decimal(10) ** -5

def find_paren_expr(i, line):
    paren_count = 1
    paren_idx = i
    for x in range(i+1, len(line)):
        if line[x] == "(":
            paren_count += 1
        if line[x] == ")":
            paren_count = paren_count - 1
            if paren_count == 0:
                return [" ".join(line[paren_idx+1:x]), x]

def compute(calc_stack):
    if len(calc_stack) == 1:
        return "".join(str(calc_stack[0]))
    else:
        while "^" in calc_stack:
            op_idx = calc_stack.index("^")
            operand1 = decimal.Decimal(calc_stack[op_idx-1])
            operand2 = decimal.Decimal(calc_stack[op_idx+1])
            result = operand1 ** operand2
            updated_sublist = []
            updated_sublist.append(result)
            calc_stack[op_idx-1:op_idx+2] = updated_sublist

        while "*" in calc_stack or "/" in calc_stack:
            op_idx1, op_idx2 = [1000, 1000]
            if "*" in calc_stack:
                op_idx1 = calc_stack.index("*")
            if "/" in calc_stack:
                op_idx2 = calc_stack.index("/")

            if op_idx1 < op_idx2:
                op_idx = op_idx1
            else:
                op_idx = op_idx2

            operand1 = decimal.Decimal(calc_stack[op_idx-1])
            operand2 = decimal.Decimal(calc_stack[op_idx+1])

            if calc_stack[op_idx] == "*":
                result = operand1 * operand2
            else:
                result = operand1 / operand2

            updated_sublist = []
            updated_sublist.append(result)
            calc_stack[op_idx-1:op_idx+2] = updated_sublist

        while "+" in calc_stack or "-" in calc_stack:
            op_idx1, op_idx2 = [1000, 1000]
            if "+" in calc_stack:
                op_idx1 = calc_stack.index("+")
            if "-" in calc_stack:
                op_idx2 = calc_stack.index("-")

            if op_idx1 < op_idx2:
                op_idx = op_idx1
            else:
                op_idx = op_idx2

            operand1 = decimal.Decimal(calc_stack[op_idx-1])
            operand2 = decimal.Decimal(calc_stack[op_idx+1])

            if calc_stack[op_idx] == "+":
                result = operand1 + operand2
            else:
                result = operand1 - operand2

            updated_sublist = []
            updated_sublist.append(result)
            calc_stack[op_idx-1:op_idx+2] = updated_sublist

        return calc_stack[0].quantize(FIVE_PLACES)



def format(number):
    num_as_str = str(number)
    zero_idx = -1
    for i in range(len(num_as_str)-1, 0, -1):
        if num_as_str[i] == "0":
            zero_idx = i
        if num_as_str[i] != "0":
            break
    if zero_idx > 0:
        if num_as_str[zero_idx-1] == ".":
            zero_idx -= 1
        if num_as_str[0:zero_idx] == "-0":
            return "0";
        return num_as_str[0:zero_idx]
    return num_as_str

f = open(sys.argv[1], 'r')

for line in f:
    print format(evaluate(line))
f.close()

*/