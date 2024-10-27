#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left,*right;

    TreeNode(int val){
        data=val;
        left=right=NULL;
    }
};

//finding position of the node
int Position(int in[], int start, int end,int val){
    for(int i=start;i<=end;i++){
        if(in[i]==val) return i;
    }
    return -1;
}

//building tree
TreeNode *tree(int in[], int pre[], int start, int end, int index){
    if(start>end) return NULL;
    TreeNode *root=new TreeNode(pre[index]);
    int pos=Position(in,start,end,pre[index]);
    root->left=tree(in,pre,start,pos-1,index+1);
    root->right=tree(in,pre,pos+1,end,index+(pos-start)+1);
    return root;
}
int main(){
    //Creating binary tree using inorder and postorder
    int pre[]={1,2,4,5,8,9,3,6,7,10};
    int in[]={4,2,8,5,9,1,6,3,7,10};
    int n=sizeof(pre)/sizeof(pre[0]);
    int start=0,end=n-1,index=0;
    TreeNode *root=tree(in,pre,start,end,index);


    //level order traversal of binary tree
    vector<int>level_order;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            TreeNode* temp=q.front();
            q.pop();
            level_order.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    for (int i = 0; i < level_order.size(); i++)
    {
        cout<<level_order[i]<<" ";
    }
    
}
