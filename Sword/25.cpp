//二叉树中和为某一值的路径
//输入一颗二叉树的跟节点和一个整数，
// 打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
// (注意: 在返回值的list中，数组长度大的数组靠前)

#include <iostream>
#include <stack>
#include "Tree.h"

using namespace std;

vector<vector<int> > ans;
vector<int> vt;

void shenDu(TreeNode *root, vector<int> &vt, int target, int sum){
    sum += root->val;
    vt.push_back(root->val);

    if(root->left==nullptr&&root->right==nullptr){//是叶子
        if(sum==target){
            ans.push_back(vt);
        }
    }
    if(root->left)
        shenDu(root->left,vt,target,sum);
    if(root->right)
        shenDu(root->right,vt,target,sum);

    vt.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    
    if(root==nullptr)
        return ans;
    
    shenDu(root,vt,expectNumber,0);
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
