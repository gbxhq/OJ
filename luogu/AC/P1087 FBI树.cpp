#include <iostream>

using namespace std;

int N;
string str;

struct treeNode{
    char val;
    treeNode *left;
    treeNode *right;
    treeNode(char a):val(a),left(nullptr),right(nullptr){}
};

char classify(int i,int j){
    int id=0;
    for (int k = i; k <= j; ++k) {
        id+=str[k]-'0';
    }
    if(id==0)
        return 'B';
    if(id==(j-i+1))
        return 'I';
    return 'F';
}

treeNode* build(int i,int j){
    treeNode *head=new treeNode(classify(i,j));
    if(i<j){
        head->left=build(i,(i+j)/2);
        head->right=build((i+j)/2+1,j);
    }
    return head;
}

void vist(treeNode *head){
    if(head->left)
        vist(head->left);
    if(head->right)
        vist(head->right);
    cout<<head->val;
}

int main(){
    cin>>N>>str;
    treeNode *tree = build(0,str.size()-1);
    vist(tree);
    return 0;
}