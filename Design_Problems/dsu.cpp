#include<bits/stdc++.h>    
using namespace std;

// property of parent is parent[i]=i 
class dsu{
    public:
    vector<int>parent;
    vector<int>rank;
    dsu(int n){
        for(int i=0;i<n+1;i++){
            parent.push_back(i);
            if(i<n){
                rank.push_back(1);
            }
        }
    }
    int findParent(int val){
        int p=parent[val];
        //intially all the parents and indexes will be same which means they are at the top of tree
        while(p!=parent[val]){
            p=parent[parent[val]];
        }
        return p;
    }
    void unionFunc(int val1,int val2){
        int p1 = findParent(val1);
        int p2 = findParent(val2);
        if(p1==p2){
            //this means val1 and val2 are from the same tree.
            cout<<"both values have same parent "<<p1<<endl;
            cout<<"cant add link as there is a cycle between "+to_string(val1)+" and "+to_string(val2)<<endl;
            return;
        }
        if(rank[p1]>=rank[p2]){
            //merging 
            rank[p1]+=rank[p2];
            parent[p2] = parent[p1];
        }else{
            rank[p2]+=rank[p1];
            parent[p1] = parent[p2];
        }
    }
};

int main(){
    dsu* dsutemp = new dsu(3);
    dsutemp->unionFunc(1,2);
    dsutemp->unionFunc(2,3);
    dsutemp->unionFunc(1,3);
}