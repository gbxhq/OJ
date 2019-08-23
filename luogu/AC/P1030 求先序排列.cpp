#include <iostream>

using namespace std;

string midSeq,backSeq;

struct treeNode{
    char val;
    treeNode *left;
    treeNode *right;
    treeNode(char a):val(a),left(nullptr),right(nullptr){}
};

treeNode* build(int i1,int j1,int i2,int j2){
    char root=backSeq[j2];
    treeNode *node = new treeNode(root);
    int i=i1;
    while (midSeq[i]!=root)
        i++;
    if(i-1>=i1)
        node->left=build(i1,i-1,i2,i-i1+i2-1);
    if(i+1<=j1)
        node->right=build(i+1,j1,j2-j1+i,j2-1);
    return node;
}

void vist(treeNode *head){
    cout<<head->val;
    if(head->left)
        vist(head->left);
    if(head->right)
        vist(head->right);
}

int main(){

    cin>>midSeq>>backSeq;
    int n=midSeq.length();
    treeNode *head = build(0,n-1,0,n-1);

    vist(head);

    return 0;
}