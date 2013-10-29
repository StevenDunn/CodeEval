// Pile of Bricks solutio in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ostringstream;
using std::replace;
using std::string;
using std::vector;

const int Z_MAX = 200;
const int MIN_LINE_LENGTH = 20;

struct Brick
{
  int x;
  int y;
  int z;
  int id;
  Brick(int x, int y, int z, int id = 0)
  {
    this->x = x;
    this->y = y;
    this->z = z;
    this->id = id;
  }
};

Brick parseHole(string&);
Brick parseBrick(string&);
void printBricksThatFit(Brick, vector<Brick>);
bool fit(Brick, Brick);
Brick rotate(Brick, int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
//      cout << line << endl;
      Brick hole = parseHole(line);

      vector<Brick> bricks;
      while(line.size() >= MIN_LINE_LENGTH)
      {
        bricks.push_back(parseBrick(line));
      }
      printBricksThatFit(hole, bricks);
    }
    inputFile.close();
  }
  return 0;
}

Brick parseHole(string& line)
{
  int barPos = line.find("|");
  string holeCoords = line.substr(0, barPos);
  line = line.substr(barPos + 1);

  replace(holeCoords.begin(), holeCoords.end(), ',' , ' ');

  string coord1Str = holeCoords.substr(holeCoords.find('[') + 1, holeCoords.find(']') - 1); 
  holeCoords = holeCoords.substr(holeCoords.find(']') + 2);
  string coord2Str = holeCoords.substr(holeCoords.find('[') + 1, holeCoords.find(']') - 1); 
  
  int x1 = atoi(coord1Str.substr(0, coord1Str.find(' ')).c_str());
  int y1 = atoi(coord1Str.substr(coord1Str.find(' ')).c_str());
  
  int x2 = atoi(coord2Str.substr(0, coord2Str.find(' ')).c_str());
  int y2 = atoi(coord2Str.substr(coord2Str.find(' ')).c_str());

  int x = abs(x1 - x2);
  int y = abs(y1 - y2);

  Brick hole(x, y, Z_MAX);
  return hole;
}

Brick parseBrick(string& line)
{
  string brickStr = line.substr(line.find('(') + 1, line.find(')') - 1);
  line = line.substr(line.find(')') + 1);

  int brickId = atoi(brickStr.substr(0, brickStr.find(' ')).c_str());

  brickStr = brickStr.substr(brickStr.find(' ') + 1);

  string coord1Str = brickStr.substr(brickStr.find('[') + 1, brickStr.find(']') - 1); 
  brickStr = brickStr.substr(brickStr.find(']') + 2);
  string coord2Str = brickStr.substr(brickStr.find('[') + 1, brickStr.find(']') - 1); 

  int x1 = atoi(coord1Str.substr(0, coord1Str.find(',')).c_str());
  coord1Str = coord1Str.substr(coord1Str.find(',') + 1);
  int y1 = atoi(coord1Str.substr(0, coord1Str.find(',')).c_str());
  coord1Str = coord1Str.substr(coord1Str.find(',') + 1);
  int z1 = atoi(coord1Str.c_str());
  
  int x2 = atoi(coord2Str.substr(0, coord2Str.find(',')).c_str());
  coord2Str = coord2Str.substr(coord2Str.find(',') + 1);
  int y2 = atoi(coord2Str.substr(0, coord2Str.find(',')).c_str());
  coord2Str = coord2Str.substr(coord2Str.find(',') + 1);
  int z2 = atoi(coord2Str.c_str());

  int x = abs(x1 - x2);
  int y = abs(y1 - y2);
  int z = abs(z1 - z2);

  Brick brick(x, y, z, brickId);
  return brick;
}

void printBricksThatFit(Brick hole, vector<Brick> bricks)
{
  ostringstream oss("");
  bool fitFound = false;
  for(int i = 0; i < bricks.size(); ++i)
  {
    Brick b = bricks[i];
    Brick rotatedBrick = b;
    for(int rotationIdx = 0; rotationIdx < 6; ++rotationIdx)
    {
      if(fit(hole, rotatedBrick))
      {
        fitFound = true;
        oss << b.id << ","; 
        break;
      } 
      else
        rotatedBrick = rotate(b, rotationIdx);
    }
  }

  if(!fitFound)
    cout << "-" << endl;
  else
  {
    oss.seekp(0, std::ios::end);
    int offset = oss.tellp();
    oss.seekp(offset - 1);
    oss << endl;
    cout << oss.str();
  }
}

bool fit(Brick hole, Brick brick)
{
  if(brick.x <= hole.x && brick.y <= hole.y && brick.z <= hole.z)
    return true;

  return false;
}

Brick rotate(Brick brick, int rotationIdx)
{
  int x = brick.x;
  int y = brick.y;
  int z = brick.z;

  switch(rotationIdx)
  {
    case 0: 
      brick.y = z;
      brick.z = y;
      break; 
    case 1:
      brick.x = y;
      brick.y = x;
      break;
    case 2:
      brick.x = y;
      brick.y = z;
      brick.z = x;
      break;
    case 3:
      brick.x = z;
      brick.z = x;
      break;
    case 4:
      brick.x = z;
      brick.y = x;
      brick.z = y;
      break;
    default:
      break;
  }
  return brick;
}
