//输入两个链表，找出它们的第一个公共结点。
#include <iostream>
#include "../ListNode.h"

using namespace std;

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {

    ListNode* p1 = pHead1, *p2 = pHead2;
//    ListNode* p2 = pHead2;//备份两个头
    if(p1==nullptr||p2==nullptr)
        return nullptr;
    while (p1!=p2){
        if(p1->next==nullptr)
            p1 = pHead1;
        else
            p1 = p1->next;
        if(p2->next==nullptr)
            p2 = pHead2;
        else
            p2 = p2->next;
    }
    return p1;
}


int main(){
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);
    ListNode *p7 = new ListNode(7);

    p1->next = p2; p2->next = p3; p3->next = p6;
    p4->next = p5; p5->next = p6;
    p6->next = p7;

    cout<<FindFirstCommonNode(p1,p4)->val;

    return 0;
}