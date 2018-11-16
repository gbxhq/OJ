#include <iostream>
#include "Tree.h"

using namespace std;

TreeNode* constructTree(vector<int> pre,int p1,int p2,vector<int> vin,int v1,int v2){

    if(p1>p2||v1>v2)
        return nullptr;

    TreeNode *node = new TreeNode(pre[p1]);

    if(p1==p2||v1==v2){
        return node;
    }
    
    //在vin中找 pre[p1] 其坐标为i；
    int i;
    for(i=v1;i<=v2;i++){
        if(vin[i]==pre[p1])
        {
            break;
        }
    }
    //左子树的节点个数 m
    int m = i - 1 - v1;

    node->left = constructTree(pre,p1+1,p1+1+m,vin,v1,i-1);

    node->right = constructTree(pre,p1+1+m+1,p2,vin,i+1,v2);

    return node;
}

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.size()==0||vin.size()==0)
        return nullptr;

    TreeNode *ans =  constructTree(pre,0,pre.size()-1,vin,0,vin.size()-1);
    return ans;
}

int main(int argc, char const *argv[])
{
    int a[4] = {1,2,4,7};
    vector<int> pre(a,a+4);
    int b[4] = {4,7,2,1};
    vector<int> vin(b,b+4);

    TreeNode *head = reConstructBinaryTree(pre,vin);

    //前序遍历
    vector<int> result;
    inOrder(head,result);
    traverse(result);

    return 0;
}
