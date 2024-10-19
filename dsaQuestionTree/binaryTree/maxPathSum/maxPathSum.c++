#include<iostream>
using namespace std;

class Node {
public:
  int val;
  Node *right, *left;
  
  Node(int v) {
    val = v;
    right = left = NULL;
  }
};

int maxPathSum(Node* rootNode, int &maxSum) {
  if (rootNode == NULL) {
    return 0;
  }

  int leftPathSum = max(0, maxPathSum(rootNode->left, maxSum));
  int rightPathSum = max(0, maxPathSum(rootNode->right, maxSum));

  // Update maxSum considering the current node as the root of the path
  maxSum = max(maxSum, rootNode->val + leftPathSum + rightPathSum);

  // Return the maximum path sum including the current node and one of its subtrees
  return rootNode->val + max(leftPathSum, rightPathSum);
}

int main() {
  Node* rootNode = new Node(1);
  rootNode->left = new Node(2);
  rootNode->right = new Node(3);

  int maxSum = INT_MIN;  // Initialize to a very small value
  maxPathSum(rootNode, maxSum);

  cout << "Maximum Path Sum: " << maxSum;
  return 0;
}
