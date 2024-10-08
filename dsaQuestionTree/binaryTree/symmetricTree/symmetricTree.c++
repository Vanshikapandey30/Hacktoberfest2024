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
bool symentricTree(Node *leftRoot, Node *rightRoot)
{
  if (leftRoot == NULL and rightRoot == NULL)
  {
    return true;
  }
  if (leftRoot != NULL and rightRoot != NULL)
  {
    bool leftCheck = symentricTree(leftRoot->left, rightRoot->right);
    bool rightCheck = symentricTree(leftRoot->right, rightRoot->left);
    if ((leftRoot->val == rightRoot->val) && leftCheck && rightCheck)
    {
      return true;
    }
    else
      return false;
  }
  else
    return false;
}
int main()
{
  Node *rootNode = new Node(1);
  rootNode->left = new Node(2);
  rootNode->right = new Node(2);
  rootNode->left->left = new Node(3);
  rootNode->left->right = new Node(4);
  rootNode->right->left = new Node(4);
  rootNode->right->right = new Node(3);
  if (rootNode == NULL)
  {
    cout << true;
  }
  cout << symentricTree(rootNode->left, rootNode->right);
  return 0;
}