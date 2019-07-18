//从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
#include "../../Tree.h"
#include "../../Vt.h"

void cg(TreeNode* pNode, vector<vector<int> > &vt,int i){
    if(vt.size()<=i){
        vector<int> vt0;
        vt.push_back(vt0);
    }
    vt[i].push_back(pNode->val);

    if(!pNode->left&&!pNode->right)
        return;
    if(pNode->left)
        cg(pNode->left,vt,i+1);
    if(pNode->right)
        cg(pNode->right,vt,i+1);
}

vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int > > ans;
    if(!pRoot)
        return ans;
    if(ans.size()<=1){
        vector<int> vt0;
        ans.push_back(vt0);
    }
    ans[0].push_back(pRoot->val);
    if(pRoot->left)
        cg(pRoot->left,ans,1);
    if(pRoot->right)
        cg(pRoot->right,ans,1);
    return ans;
}

int main(){
    int a[7] = {1,2,3,4,5,6,7};
    TreeNode *root = initBTree(a,7);

    vector<vector<int > > ans = Print(root);
    showVtvt(ans);

    return 0;
}