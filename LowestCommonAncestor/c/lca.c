// Lowest Common Ancestor solution in C for CodeEval.com by Steven A. Dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node
{
    Node* left;
    Node* right;
    int val;
};

Node* createTree();
int findLCA(Node*, int, int);

int main(int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        Node* node = createTree();
        char line[32];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, " ");
            int left = atoi(token);
            token = strtok(NULL, " ");
            int right = atoi(token);

            if (left > right)
            {
                int tmp = left;
                left = right;
                right = tmp;
            }

            int LCA = findLCA(node, left, right);
            printf("%d\n", LCA);
        }
        fclose(fp);
    }
    return 0;
}

Node* createTree()
{
    Node* node = malloc(sizeof(Node));
    node->val = 30;

    node->left = malloc(sizeof(Node));
        node->left->val = 8;
        node->left->left = malloc(sizeof(Node));
            node->left->left->val = 3;
            node->left->left->left = NULL;
            node->left->left->left = NULL;
        node->left->right = malloc(sizeof(Node));
            node->left->right->val = 20;
            node->left->right->left = malloc(sizeof(Node));
            node->left->right->left->val = 10;
                node->left->right->left->left = NULL;
                node->left->right->left->right = NULL;
            node->left->right->right = malloc(sizeof(Node));
            node->left->right->right->val = 29;
                node->left->right->right->left = NULL;
                node->left->right->right->right = NULL;
    node->right = malloc(sizeof(Node));
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