#include <iostream>
#include <unordered_map>
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
int pathSumHelper(Node *root, int targetSum, long int currSum, unordered_map<long int, int> pathCount)
{
  if (root == NULL)
  {
    return 0;
  }
  currSum += root->val;
  int ansCount = pathCount[currSum - targetSum];
  pathCount[currSum]++;
  ansCount += pathSumHelper(root->left, targetSum, currSum, pathCount) + pathSumHelper(root->right, targetSum, currSum, pathCount);
  pathCount[currSum]--;
  return ansCount;
}

int main()
{
  Node *rootNode = new Node(10);
  rootNode->left = new Node(5);
  rootNode->right = new Node(-3);
  rootNode->left->left = new Node(3);
  rootNode->left->right = new Node(2);
  rootNode->left->right->left = new Node(3);
  rootNode->left->right->right = new Node(1);
  rootNode->right->right = new Node(11);
  unordered_map<long int, int> pathCount;
  int targetSum = 8;
  pathCount[0] = 1;
  int ans = pathSumHelper(rootNode, targetSum, 0, pathCount);
  cout << ans;
  return 0;
}