//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
#include <iostream>
#include "../Tree.h"

using namespace std;
/*
int depth(TreeNode* rt){
    if(!rt)
        return 0;
    int leftDepth = depth(rt->left)+1;
    int rightDepth = depth(rt->right)+1;
    return max(leftDepth,rightDepth);
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    if(!pRoot)
        return true;
    int x = depth(pRoot->left)-depth(pRoot->right);
    if(x>1||x<-1)
        return false;
    return pRoot->left&&pRoot->right;
}*///辣鸡法

bool backOrder(TreeNode* rt,int &depth){
    if(!rt)
    {
        depth = 0;
        return true;
    }
    int leftDepth,rightDepth;
    if(backOrder(rt->left,leftDepth)&&backOrder(rt->right,rightDepth)) {
        depth = max(leftDepth, rightDepth) + 1;
        int x = leftDepth - rightDepth;
        if (x<=1&&x>=-1)
            return true;//这样在这里就能提前判断出false的情况返回了
    }
    return false;
}
bool IsBalanced_Solution(TreeNode* pRoot) {
    int temp;
    return backOrder(pRoot,temp);
}

int main(){
    TreeNode* rt = new TreeNode(1);
    cout  << IsBalanced_Solution(rt);
    return 0;
}