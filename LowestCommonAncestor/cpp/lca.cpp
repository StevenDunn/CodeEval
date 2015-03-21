// Lowest Common Ancestor solution in C++ for CodeEval.com by Steven A. Dunn

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

typedef struct Node
{
	Node* left;
	Node* right;
	int val;
} Node;

Node* createTree();
int findLCA(Node*, int, int);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;

	if (inputFile)
	{
		Node* node = createTree();
		while (getline(inputFile, line))
		{
			int spacePos = line.find(" ");
			vector<int> nodeVals(2, 0);
			nodeVals[0] = atoi(line.substr(0, spacePos).c_str());
			nodeVals[1] = atoi(line.substr(spacePos).c_str());

			int left = nodeVals[0];
			int right = nodeVals[1];

			if (left > right)
			{
				int tmp = left;
				left = right;
				right = tmp;
			}

			int LCA = findLCA(node, left, right);
			cout << LCA << endl;
		}
		inputFile.close();
	}
	return 0;
}

Node* createTree()
{
	Node* node = new Node();
	node->val = 30;

	node->left = new Node();
		node->left->val = 8;
		node->left->left = new Node();
			node->left->left->val = 3;
			node->left->left->left = NULL;
			node->left->left->left = NULL;
		node->left->right = new Node();
			node->left->right->val = 20;
			node->left->right->left = new Node();
			node->left->right->left->val = 10;
				node->left->right->left->left = NULL;
				node->left->right->left->right = NULL;
			node->left->right->right = new Node();
			node->left->right->right->val = 29;
				node->left->right->right->left = NULL;
				node->left->right->right->right = NULL;
	node->right = new Node();
		node->right->val = 52;
		node->right->left = NULL;
		node->right->right = NULL;

	return node;
}

int findLCA(Node* node, int val1, int val2)
{
	int nodeVal = node->val;
	if (nodeVal == val1 || nodeVal == val2)
		return nodeVal;
	if (val1 < nodeVal && val2 > nodeVal)
		return nodeVal;
	else if (val1 > nodeVal)
		return findLCA(node->right, val1, val2);
	else
		return findLCA(node->left, val1, val2);
}