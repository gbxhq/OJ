#include <iostream>
#include <deque>
#include <vector>
#include "Tree.h"

using namespace std;


vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> ans;
    deque<TreeNode *> Dui;
    if(root!=nullptr)
        Dui.push_back(root);
    else
        return ans;
    while(!Dui.empty()){
        TreeNode *tmp = Dui.front();
        if(tmp!=nullptr)
            ans.push_back(tmp->val);
        if(tmp->left!=nullptr)
            Dui.push_back(tmp->left);
        if(tmp->right!=nullptr)
            Dui.push_back(tmp->right);
        if(tmp!=nullptr)
            Dui.pop_front();
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int a[8] = {1,2,3,4,5,6,7};
    TreeNode *root = initBTree(a,7);

    vector<int> Vt = PrintFromTopToBottom(root);
    // preOrder(root,preVt);

    traverse(Vt);

    return 0;
}
