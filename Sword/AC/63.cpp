//给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
#include "../../Tree.h"
int i=0,j=9999;
vector<TreeNode*> ans;
void midOrder(TreeNode* pRoot){
    if(!pRoot)
        return;
    if(pRoot->left)
        midOrder(pRoot->left);
    ans.push_back(pRoot);
    i++;
    if(i>=j)
        return;
    if(pRoot->right)
        midOrder(pRoot->right);
}
TreeNode* KthNode(TreeNode* pRoot, int k)
{
    TreeNode *tmp= nullptr;
    if(k<=0)
        return tmp;
    j=k;
    midOrder(pRoot);
    if(i<k)
    {
//        cout <<i<<' ' <<k << "ERROR";
        return tmp;
    }
    return ans[k-1];
}

int main(){
    int a[7] = {5,3,7,2,4,6,8};
    TreeNode *root = initBTree(a,7);

    TreeNode *ans = KthNode(root,7);
    if(ans)
        cout<<ans->val;
    return 0;
}
