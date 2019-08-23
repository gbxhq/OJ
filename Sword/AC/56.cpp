//给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

#include "../../ListNode.h"
#include <set>
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode *p1 = pHead;
    ListNode *p2 = pHead;

    if(!p2->next)
        return nullptr;

    while (p1&&p2->next){
        p1 = p1->next;
        p2 = p2->next->next;

        if(p1==p2)
            break;
    }
    if(!(p1&&p2))
        return nullptr;

    p2 = p2->next;
    int n = 1;
    while (p2 != p1){
        n++;
        p2 = p2->next;
    }

    p1 = pHead;
    p2 = pHead;

    for(int i=1;i<=n;i++)
        p2 = p2->next;

    while (p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}