#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1==nullptr||pHead2==nullptr)
        return pHead1==nullptr? pHead2 : pHead1;
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;
    ListNode *ansHead = nullptr;

    if(p1->val <= p2->val){
        ansHead = pHead1;
        p1 = p1->next;
    }
    else{
        ansHead = p2;
        p2 = p2->next;
    }

    ListNode *cur = ansHead;
    while(p1!=nullptr&&p2!=nullptr){
        if(p1->val <= p2->val){
            cur->next = p1;
            cur = p1;
            p1 = p1->next;
            while(p1!=nullptr&&p1->val<=p2->val)
            {
                cur = p1;
                p1 = p1->next;
            }   
        }    
        else{
            cur->next = p2;
            cur = p2;
            p2 = p2->next;
            while(p2!=nullptr&&p2->val<=p1->val)
            {
                cur = p2;
                p2 = p2->next;
            }
        }
    }

    if(p1!=nullptr){
        cur->next = p1;
    }
    if(p2!=nullptr){
        cur->next = p2;
    }
    return ansHead;
}


int main(int argc, char const *argv[])

{
    ListNode *list1 = createList();
    ListNode *list2 = createList();

    int a[] = {1,3,5};
    list1 = initList(list1,a,3);
    int b[] = {2,4,6};
    list2 = initList(list2,b,3);

    list1 = Merge(list1,list2);

    showList(list1);

    cout << " " << endl;
    return 0;
}
