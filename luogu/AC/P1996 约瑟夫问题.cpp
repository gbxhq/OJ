#include <iostream>

using namespace std;
int n=10,m=3;

int ans[101];

struct listNode{
    int x;
    listNode *next;
    listNode *last;
    listNode(int a):x(a),next(nullptr),last(nullptr){
    }
};

listNode* build(int n){
    listNode *head = new listNode(1);
    listNode *cur=head;
    for (int i = 2; i <= n; ++i) {
        listNode *temp = new listNode(i);
        cur->next=temp;
        temp->last=cur;
        cur=temp;
    }
    cur->next=head;
    head->last=cur;
    return head;
}

bool isOnly(listNode *head){
    if (head==head->next)
        return true;
    return false;
}

int main(){

    cin>>n>>m;

    if(n<=0)
        return 0;

    listNode *head = build(n),*cur=head;

    while (!isOnly(cur)){
        for (int i = 1; i < m; ++i) {
            cur=cur->next;
        }
        cout<<cur->x<<' ';
        cur->last->next=cur->next;
        cur->next->last=cur->last;
        cur=cur->next;
    }
    cout<<cur->x;

    return 0;
}