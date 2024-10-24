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

int minDepthHelper(Node *root)
{
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;
  if (root->left == NULL)
    return minDepthHelper(root->right) + 1;
  if (root->right == NULL)
    return minDepthHelper(root->left) + 1;
  int leftDepth = minDepthHelper(root->left);
  int rightDepth = minDepthHelper(root->right);
  return min(leftDepth, rightDepth) + 1;
}
int main()
{
  Node *rootNode = new Node(10);
  rootNode->left = new Node(5);
  rootNode->right = new Node(-3);
  rootNode->left->left = new Node(3);
  rootNode->left->right = new Node(2);
  rootNode->left->right->left = new Node(3);
  cout<<minDepthHelper(rootNode);
  return 0;
}