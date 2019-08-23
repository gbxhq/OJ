//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
// 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
    }
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if(pNode->right){
        TreeLinkNode *p = pNode->right;
        while (p->left)
            p = p ->left;
        return p;
    } else if(pNode->next && pNode->next->left == pNode) //是左儿子
        return pNode->next;
    else if(pNode->next && pNode->next->right == pNode) //是右儿子
        if(pNode->next->next)//看有没有爷爷
            if(pNode->next->next->left == pNode->next) //爸爸是爷爷的左儿子
                return pNode->next->next;
    return nullptr;
}