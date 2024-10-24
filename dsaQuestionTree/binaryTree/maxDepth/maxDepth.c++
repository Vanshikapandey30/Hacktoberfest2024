#include <iostream>
using namespace std;
class Node

{
public:
  int val;
  Node *right;
  Node *left;
  Node(int v)
  {
    val = v;
    right = left = NULL;
  }
};
int maxDepth(Node *rootNode)
{
  if (rootNode == NULL)
  {
    return 0;
  }
  int leftDepth = maxDepth(rootNode->left);
  int rightDepth = maxDepth(rootNode->right);
  return max(1 + leftDepth, 1 + rightDepth);
}
int main()
{
  Node *rootNode = new Node(10);
  rootNode->left = new Node(5);
  rootNode->right = new Node(-3);
  rootNode->left->left = new Node(3);
  rootNode->left->right = new Node(2);
  rootNode->left->right->left = new Node(3);
  cout << maxDepth(rootNode);
  return 0;
}