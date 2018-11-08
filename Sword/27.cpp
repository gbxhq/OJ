/*题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向*/
#include <iostream>
#include "../Header/Tree.h"

using namespace std;

TreeNode* Convert(TreeNode* pRootOfTree){
        
}

int main(int argc, char const *argv[])
{
    int a[7] = {1,2,3,4,5,6,7};

    TreeNode *root = initBTree(a,7);

    vector <int> vt;

    preOrder(root,vt);

    traverse(vt);

    return 0;
}


