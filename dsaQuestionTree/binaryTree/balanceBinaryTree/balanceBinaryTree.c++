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

// Function to check if the tree is balanced
int isBlanced(Node *root)
{
  if (root == NULL)
    return 0;
  int leftHeight = isBlanced(root->left);
  int rightHeight = isBlanced(root->right);
  if (leftHeight == -1 || rightHeight == -1 || abs(rightHeight - leftHeight) > 1)
    return -1;
  return max(leftHeight, rightHeight) + 1;
}

int main()
{
  // Creating the tree
  Node *rootNode = new Node(10);
  rootNode->left = new Node(5);
  rootNode->right = new Node(-3);
  rootNode->left->left = new Node(3);
  rootNode->left->right = new Node(2);
  rootNode->left->right->left = new Node(3);

  // Check if the tree is balanced
  if (isBlanced(rootNode) != -1)
  {
    cout << true << endl;
  }
  else
  {
    cout << false << endl;
  }
  return 0;
}
