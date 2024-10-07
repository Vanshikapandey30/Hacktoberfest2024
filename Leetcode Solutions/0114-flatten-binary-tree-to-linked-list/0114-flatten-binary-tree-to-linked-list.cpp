// Approach - 1 -> Using Extra Space without creating new tree


// class Solution {

// private: 
//     void dfs(TreeNode* root, vector<int> &arr){
//         if(!root) return;

//         arr.push_back(root->val);
//         dfs(root->left,arr);
//         dfs(root->right,arr);
//     }


// public:
//     void flatten(TreeNode* root) {

//         if(!root) return;
    
//         vector<int> preorder;
//         dfs(root,preorder);

//         if(preorder.size()==1) return;

//         if(root->left){
//             root->left = NULL;
//         } 
//         TreeNode* curr = root;

//         for(int i=1;i<preorder.size();i++){
//             TreeNode* node = new TreeNode(preorder[i]);
//             curr->right = node;
//             curr = node;
//         }

//     }
// };




// Approach - 2  Using reverse postorder 


// class Solution {

// private: 
//     void dfs(TreeNode* &root, TreeNode* &prev){
//         if(!root) return;

//         dfs(root->right,prev);
//         dfs(root->left,prev);

//         root->left = NULL;
//         root->right = prev;
//         prev = root;
//     }


// public:
//     void flatten(TreeNode* root) {
//         TreeNode* prev = NULL;
//         dfs(root,prev);
//     }
// };


// Approach - 3 : O(1) space -> Morris Traversal


class Solution {

public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left=NULL;
            }

            curr=curr->right; 
        }
    }
};


