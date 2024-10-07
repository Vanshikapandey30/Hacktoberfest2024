class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int count = 0;
            for(int i=0;i<size;i++){
                Node* ele = q.front();
                q.pop();

                if(!q.empty() && count<size-1){
                    ele->next = q.front();
                    count++;
                }

                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
            }
        }

        return root;
    }
};