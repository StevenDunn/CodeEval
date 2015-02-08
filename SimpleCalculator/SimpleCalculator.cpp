// Simple Calculator solution in C++ for CodeEval.com by Steven A. Dunn

#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ostringstream;
using std::string;
using std::vector;

void printLine(string);
double evaluate(string);
string parseNextToken(string&);
bool isOperator(char);
bool isLeftParen(char);
bool isRightParen(char);
string getSubExpr(string&);
double updateResult(vector<string>&, vector<string>&);
char getHighestPrecedenceOperator(vector<string>, int&);
bool greaterOp(char, char);
double apply(char, vector<string>, int);
void updateState(vector<string>&, vector<string>&, int);
string parse(string);

template<typename T>
void printVector(vector<T> vec);

// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;

	if(inputFile)
	{
		while(getline(inputFile, line))
      		printLine(line);
		inputFile.close();
	}
	return 0;
}

void printLine(string line)
{
  	ostringstream s;
	s.setf(ios::fixed);
	s.precision(5);
	s << evaluate(line);
	cout << "###########final result: " << parse(s.str()) << endl;
}

double evaluate(string line)
{
	cout << "line is: " << line << endl;
	string token;
	string op;

	double result = 0.0;

	vector<string> operands;
	vector<string> operators;

	while(line != "")
	{
		line = trim(line);
		cout <<  "updated line is: " << line << endl;
		token = parseNextToken(line);
		cout << "token: " << token << " of length: " << token.size() << endl;
		if(isOperator(token[0]))
		{
			if(token[0] == '-' && (operands.size() < operators.size() + 1))
				token = "@";

			operators.push_back(token);
		}
		else if(isLeftParen(token[0]))
		{
			getSubExpr(line);
      		continue;
		}
		else if(token != "")
		{
			operands.push_back(token);
		}
		if (token.size() > 0)
    		line = line.substr(token.size());
    	else
    		line = line.substr(1);
	}

	return updateResult(operands, operators);
}

string parseNextToken(string& line)
{
	int idx = 0;
	while(!isOperator(line[idx]) && !isLeftParen(line[idx]) && idx < line.size())
		++idx;

	if(idx == 0)
		++idx;

	string result = line.substr(0, idx);
	result = trim(result);
	return result;
}

bool isOperator(char c)
{
	if(c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
		return true;
	return false;
}

bool isLeftParen(char c)
{
	if(c == '(')
		return true;
	return false;
}

bool isRightParen(char c)
{
	if(c == ')')
		return true;
	return false;
}

string getSubExpr(string& line)
{
	int leftParen = 0;
	int rightParen = 0;

	for(int i = 0; i < line.size(); ++i)
	{
		if (isLeftParen(line[i]))
			leftParen = i;
		if (isRightParen(line[i]))
		{
			rightParen = i;
			string subexpr = line.substr(leftParen + 1, rightParen - leftParen - 1);
			ostringstream s;
			s << evaluate(subexpr);
			line.replace(leftParen, rightParen - leftParen + 1, s.str());
			continue;
		}
	}

	return line;
}

double updateResult(vector<string>& operands, vector<string>& operators)
{
	double result = 0.0;

	for(int i = 0; i < operators.size(); ++i)
	{
		if(operators[i] == "@")
		{
			operators.erase(operators.begin() + i);
			string opnd = operands[i];
			ostringstream s;
			s << "-" << opnd;
			operands[i] = s.str();
		}
	}

	cout << "operands: ";
	printVector(operands);

	cout << "operators: ";
	printVector(operators);

	while(operators.size() > 0)
	{
		int idx = 0;
		char firstOperator = getHighestPrecedenceOperator(operators, idx);
		result = apply(firstOperator, operands, idx);
		updateState(operands, operators, idx);
		if(operands.size() > 0)
		{
			ostringstream s;
			s << result;
			operands.insert(operands.begin() + idx, s.str());
		}
	}

	if(operands.size() == 1)
		result = atof(operands[0].c_str());

	return result;
}

char getHighestPrecedenceOperator(vector<string> operators, int& idx)
{
	char op = operators[0][0];
	for(int i = 1; i < operators.size(); ++i)
	{
		char curOp = operators[i][0];
		if(!greaterOp(op, curOp))
		{
			op = curOp;
			idx = i;
		}
	}

	return op;
}

bool greaterOp(char op1, char op2)
{
	bool isOp1Greater;

	switch(op1)
	{
		case '^':
			(op2 != '^') ? isOp1Greater = true : isOp1Greater = false;
			break;

		case '*':
		case '/':
			(op2 != '^' || op2 != '*' || op2 != '/') ? isOp1Greater = true : isOp1Greater = false;
			break;

		case '+':
		case '-':
			(op2 == '+' || op2 == '-' ) ? isOp1Greater = true : isOp1Greater = false;
			break;

		default:
			isOp1Greater = false;
			break;
	}
	return isOp1Greater;
}

double apply(char firstOperator, vector<string> operands, int idx)
{
	double x = atof(operands[idx].c_str());
	double y = atof(operands[idx + 1].c_str());

	double result = 0.0;

	switch(firstOperator)
	{
		case '^':
			result = pow(x, y);
			break;
		case '*':
			result = x * y;
			break;
		case '/':
			result = x / y;
			break;
		case '+':
			result = x + y;
			break;
		case '-':
			result = x - y;
			break;
	}
	return result;
}

void updateState(vector<string>& operands, vector<string>& operators, int idx)
{
	operands.erase(operands.begin() + idx, operands.begin() + idx + 2);
	operators.erase(operators.begin() + idx);
}

string parse(string line)
{
	int idx = line.size() - 1;
	while (idx >= 0 && line[idx] == '0')
		idx--;
	if (line[idx] == '.')
		idx -= 1;
	return line.substr(0, idx + 1);
}

template<typename T>
void printVector(vector<T> vec)
{
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << ",";
	cout << endl;
}

