#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;
   
class TreeNode{
public:
    TreeNode(long x):x(x){}
        
    long x;
    TreeNode *l;
    TreeNode *r;

    void print_dfs(){
        stack<pair<TreeNode*,int> > mystack; // TreeNode, Level
        mystack.push(make_pair(this,0));
        while(!mystack.empty()){
            pair<TreeNode*,long> topitem = mystack.top();
            mystack.pop();
            long level = topitem.second;
            cout<<"value = "<<topitem.first->x<<" level = "<<level<<endl;
            TreeNode *tree=topitem.first;
            if(tree->l != NULL){
                cout<<topitem.first->x<<" has left child "<<tree->l->x<<endl;
                mystack.push(make_pair(tree->l,level+1));
            }
            if(tree->r != NULL){
                cout<<topitem.first->x<<" has righ child "<<tree->r->x<<endl;
                mystack.push(make_pair(tree->r,level+1));
            }
        }
    }

    long countVisibleNodesIter(){
        TreeNode *root=this;
        if(root==NULL)
            return 0;
        
        int countVisible=0;
        long maxSoFar=0;
        //pair<TreeNode*,int> myrootstack;
        stack<pair<TreeNode*,int> > mystack; // TreeNode, Level
        mystack.push(make_pair(root,root->x));        
        while(!mystack.empty()){
            pair<TreeNode*,int> topitem = mystack.top();          
            mystack.pop();
            if(topitem.first->x >= topitem.second){
                countVisible++;
                cout<<"this is a visible node "<<topitem.first->x<<endl;
            }
              
            long currentMax=topitem.second;
            TreeNode *tree=topitem.first;

            maxSoFar = max(tree->x,currentMax);
            if(tree->l != NULL)
                mystack.push(make_pair(tree->l,maxSoFar));
            if(tree->r != NULL)
                mystack.push(make_pair(tree->r,maxSoFar));
            
        }
        return countVisible;
    }
    
};
