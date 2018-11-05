// # 18 判断是不是树的子结构
#include <iostream>
#include "Tree.h"

using namespace std;
bool isSame(TreeNode* p1, TreeNode* p2){
    if(p2==nullptr)
        return true;
    if(p1==nullptr&&p2!=nullptr)
        return false;
    if(p1->val!=p2->val)
        return false;
    if(p2->left||p2->right)
        return isSame(p1->left,p2->left)&&isSame(p1->right,p2->right);
    return true;
}

bool HasSubtree(TreeNode* p1, TreeNode* p2){
    if(p1==nullptr||p2==nullptr)
        return false;
    if(p1->val==p2->val)
        return isSame(p1,p2);
    if(p1->left||p1->right){
        return HasSubtree(p1->left,p2)
            || HasSubtree(p1->right,p2);
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int a[5] = {1,8,7,9,2};
    int b[3] = {8,9,2};
    TreeNode *Tree1 = initBTree(a,5);
    TreeNode* Tree2 = initBTree(b,3);

    cout << HasSubtree(Tree1,Tree2)<<"\n";
    // vector<int> show ;
    // preOrder(Tree1,show);
    // traverse(show);

    return 0;
}
