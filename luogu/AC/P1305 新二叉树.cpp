#include <iostream>
#include <map>
using namespace std;

struct treeNode{
    char val;
    treeNode *left;
    treeNode *right;
    treeNode(char a):val(a),left(nullptr),right(nullptr){}
};

void preVist(treeNode *head){
    cout<<head->val;
    if(head->left)
        preVist(head->left);
    if(head->right)
        preVist(head->right);
}

int main(){
    int n;
    cin>>n;
    string str;

    map<char,treeNode*> m;
    treeNode *Tree= nullptr;
    while (n--){
        cin>>str;
        if(m.find(str[0])==m.end())//树的根节点
        {
            treeNode *node= new treeNode(str[0]);
            m[str[0]]=node;
            Tree=node;
        }
        if(str[1]!='*'){
            treeNode *node= new treeNode(str[1]);
            m[str[0]]->left=node;
            m[str[1]]=node;
        }
        if(str[2]!='*'){
            treeNode *node= new treeNode(str[2]);
            m[str[0]]->right=node;
            m[str[2]]=node;
        }
    }

    preVist(Tree);

    return 0;
}