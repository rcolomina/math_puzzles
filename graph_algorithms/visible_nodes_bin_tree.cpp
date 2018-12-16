
#include <iostream>
#include <stack>
#include <utility>
#include <list>

#include "binary_tree.h"

using namespace std;

TreeNode* create_tree_test_1(){

    TreeNode *root = new TreeNode(5);

    TreeNode *tl = new TreeNode(8);
    TreeNode *tr = new TreeNode(3);

    root->l = tl;
    root->r = tr;

    TreeNode *tll = new TreeNode(12);
    TreeNode *trl = new TreeNode(53);
    TreeNode *trr = new TreeNode(3); 
    
    tl->l = tll;
    tr->l = trl;
    tr->r = trr;
    //cout<<tree->x<<endl;
    return root;    
}

TreeNode* create_tree_test_2(){

    TreeNode *root = new TreeNode(5);

    TreeNode *tl = new TreeNode(80);
    TreeNode *tr = new TreeNode(3);

    root->l = tl;
    root->r = tr;

    TreeNode *tll = new TreeNode(12);
    TreeNode *tlr = new TreeNode(14);
    
    TreeNode *trl = new TreeNode(53);
    TreeNode *trr = new TreeNode(23); 
    
    tl->l = tll;
    tr->l = trl;
    tr->r = trr;
    //cout<<tree->x<<endl;
    return root;    
}


TreeNode* createTreeExpression(list<int> exp){

    stack<TreeNode*> mynodes;

    for(list<int>::iterator it=exp.begin();
        it!=exp.end();
        ++it)
    {
        
        cout<<*it<<endl;

        if(*it == -1)
            mynodes.push(new TreeNode(-1));
        if(*it != -1)
        {
            TreeNode *ti = mynodes.top();
            mynodes.pop();
            TreeNode *tr = mynodes.top();
            mynodes.pop();
            int val=*it;
            TreeNode *tree=new TreeNode(val);
            if(ti->x != -1)
                tree->l=ti;
            if(tr->x != -1)
                tree->r=tr;
            mynodes.push(tree); 
        }
    }
    return mynodes.top();
}


int main(){

    list<int> myexp = {-1,-1,73,-1,33,-1,-1,43,125};
    
    TreeNode *nodeGen=createTreeExpression(myexp);
    nodeGen->print_dfs();
    
    //TreeNode *root1 = create_tree_test_1();
    // root1->print_dfs();
    //   cout<<"Visible nodes:"<<root1->countVisibleNodesIter()<<endl;

//    TreeNode *root2 = create_tree_test_2();
//    root2->print_dfs();
//    cout<<"Visible nodes:"<<root2->countVisibleNodesIter()<<endl;

}
