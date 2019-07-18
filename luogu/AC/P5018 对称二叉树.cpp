#include <iostream>

using namespace std;

struct treeNode{
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int a):val(a),left(nullptr),right(nullptr){}
};
treeNode* data[1000001];

bool checkSon(treeNode *l,treeNode *r){
    if(!l&&!r)
        return true;
    if(!l||!r)
        return false;
    return  l->val==r->val
            && checkSon(l->left,r->right)
            && checkSon(l->right,r->left);
}

int cnt(treeNode *rt){
    if(!rt)
        return 0;
    return 1+cnt(rt->left)+cnt(rt->right);
}

int main(){
    int n;
    cin>>n;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin>>temp;
        data[i]=new treeNode(temp);
    }//建节点
    for (int i = 0; i < n; ++i) {
        cin>>temp;
        if(temp!=-1)
            data[i]->left=data[temp-1];
        cin>>temp;
        if(temp!=-1)
            data[i]->right=data[temp-1];
    }//根据孩子信息建树

    int ans=0;
    for (int i = 0; i < n; ++i) {
        if(checkSon(data[i]->left,data[i]->right))
            ans=max(ans,cnt(data[i]));
    }
    cout<<ans;

    return 0;
}