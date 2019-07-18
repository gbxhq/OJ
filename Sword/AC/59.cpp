//判断是不是对称二叉树

struct TreeNode {

    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

bool isSymm(TreeNode *l, TreeNode *r){
    if(!l&&!r)
        return true;
    if(!l||!r)
        return false;
    if(l->val!=r->val)
        return false;
    //至此， l、r都有值 且相同
    return isSymm(l->left,r->right) && isSymm(l->right,r->left);
}

bool isSymmetrical(TreeNode* pRoot)
{
    if(!pRoot)
        return true; //空树竟然是对称的
    return isSymm(pRoot->left,pRoot->right);
}







