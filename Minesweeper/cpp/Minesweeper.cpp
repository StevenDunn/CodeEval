// Minesweeper solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

void fillBoard(string, vector<int>&);
void findMines(vector<int>, int);
int numMines(int, int, vector<int>);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      int semiColPos = line.find(";");

      string dims = line.substr(0, semiColPos);

      int commaPos = line.find(",");
      int M = atoi(dims.substr(0, commaPos).c_str());
      int N = atoi(dims.substr(commaPos+1).c_str());

      string input = line.substr(semiColPos+1);
      vector<int> board(M * N);
      fillBoard(input, board);

      findMines(board, N);
    }
    inputFile.close();
  }
  return 0;
}

void fillBoard(string input, vector<int>& board)
{
  for (int i = 0; i < board.size(); ++i)
  {
    if (input[i] == '*')
      board[i] = 1;
    else
      board[i] = 0;
  }
}

void findMines(vector<int> board, int N)
{
  for (int i = 0; i < board.size(); ++i)
  {
    int mineCount = numMines(i, N, board);
    if (mineCount == -1)
      cout << '*';
    else
      cout << mineCount;
  }
  cout << endl;
}

int numMines(int i, int N, vector<int> board)
{
  int mineCount = 0;

  if (board[i] == 1)
    mineCount = -1;
  else
  {
    bool xLeft = (i % N != 0);
    bool xRight = ((i + 1) % N != 0);
    bool yTop = (i >= N);
    bool yBottom = (i + N <= board.size() - 1);

    if ( xLeft && (board[i-1] == 1) )
      ++mineCount;
    if ( xRight && (board[i+1] == 1) )
      ++mineCount;
    if ( yTop && (board[i-N] == 1) )
      ++mineCount;
    if ( yBottom && (board[i+N] == 1) )
      ++mineCount;
    if ( xLeft && yTop && (board[i-1-N] == 1) )
      ++mineCount;
    if ( xLeft && yBottom && (board[i-1+N] == 1) )
      ++mineCount;
    if ( xRight && yTop && (board[i+1-N] == 1) )
      ++mineCount;
    if ( xRight && yBottom && (board[i+1+N] == 1) )
      ++mineCount;
  }

  return mineCount;
}
