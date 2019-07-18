//二叉树的深度

#include <iostream>
#include "../Tree.h"
using namespace std;

void TreeDepth(TreeNode* rt,int depth,int &max){
    if(rt)
        depth++;
    else//防止rt为空还继续往下走。走到rt->left肯定出事
        return;
    if(depth>max)
        max = depth;
    if(rt->left)
        TreeDepth(rt->left,depth,max);
    if(rt->right)
        TreeDepth(rt->right,depth,max);
}

int TreeDepth(TreeNode* pRoot)
{
    int ans =0;
    TreeDepth(pRoot,0,ans);
    return ans;
}

int main(){

    return 0;
}