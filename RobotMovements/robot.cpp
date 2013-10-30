// Robot Movements solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

struct Node
{
  Node() : 
    visited(false), 
    isEnd(false), 
    id(0), 
    link1(NULL), 
    link2(NULL), 
    link3(NULL), 
    link4(NULL) {}
  bool visited;
  bool isEnd;
  int id;
  Node* link1;
  Node* link2;
  Node* link3;
  Node* link4;
} n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;

int paths = 0;

Node* createGrid();
void findPaths(Node*);

int main(int argc, char* argv[])
{
  Node* start = createGrid();

  findPaths(start); 

  cout << paths << endl;

  return 0;
}

Node* createGrid()
{
  n1.link1 = &n2;
  n1.link2 = &n5;
  n1.id = 1;

  n2.link1 = &n3;
  n2.link2 = &n6;
  n2.link3 = &n1;

  n3.link1 = &n4;
  n3.link2 = &n7;
  n3.link3 = &n2;

  n4.link2 = &n8;
  n4.link3 = &n3;

  n5.link1 = &n6;
  n5.link2 = &n9;
  n5.link4 = &n1;

  n6.link1 = &n7;
  n6.link2 = &n10;
  n6.link3 = &n5;
  n6.link4 = &n2;

  n7.link1 = &n8;
  n7.link2 = &n11;
  n7.link3 = &n6;
  n7.link4 = &n3;

  n8.link2 = &n12;
  n8.link3 = &n7;
  n8.link4 = &n4;

  n9.link1 = &n10;
  n9.link2 = &n13;
  n9.link4 = &n5;

  n10.link1 = &n11;
  n10.link2 = &n14;
  n10.link3 = &n9;
  n10.link4 = &n6;

  n11.link1 = &n12;
  n11.link2 = &n15;
  n11.link3 = &n10;
  n11.link4 = &n7;
  
  n12.link2 = &n16;
  n12.link3 = &n11;
  n12.link4 = &n8;

  n13.link1 = &n14;
  n13.link4 = &n9;

  n14.link1 = &n15;
  n14.link3 = &n13;
  n14.link4 = &n10;

  n15.link1 = &n16;
  n15.link3 = &n14;
  n15.link4 = &n11;

  n16.link3 = &n15;
  n16.link4 = &n12;
  n16.isEnd = true;

  Node* start = &n1;
  return start; 

}

void findPaths(Node* node)
{
  if(node->isEnd == true)
  {
    ++paths;
    return;
  }
  if(node->visited == true)
    return;
  
  node->visited = true;

  if(node->link1 != NULL)
    findPaths(node->link1);
  if(node->link2 != NULL)
    findPaths(node->link2);
  if(node->link3 != NULL)
    findPaths(node->link3);
  if(node->link4 != NULL)
    findPaths(node->link4);

   node->visited = false;
   return;
}
