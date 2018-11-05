#include <iostream>
#include <stack>
#include "ListNode.h"

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1;
    stack<int> s2;

    ListNode *p1 = l1, *p2 = l2;

    ListNode *ans = new ListNode(-1);
    ListNode *cur = ans;

    int flag=0;

    while(p1&&p2){
        int sum = p1->val+p2->val+flag;
        if(sum>=10){
            flag = 1;
            sum -= 10;
        }else
            flag = 0;

        ListNode *tmp = new ListNode(sum);
        cur->next = tmp;
        cur = tmp;

        p1 = p1->next;
        p2 = p2->next;
    }
    if(p1);
    if(p2)
        p1 = p2;
    while(p1){
        int sum = p1->val+flag;
        if(sum>=10){
            flag = 1;
            sum -= 10;
        }else
            flag = 0;

        ListNode *tmp = new ListNode(sum);
        cur->next = tmp;
        cur = tmp;

        p1 = p1->next;
    }
    if(flag){
        ListNode *tmp = new ListNode(1);
        cur->next = tmp;
        cur = tmp;
    }

    return ans->next;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
