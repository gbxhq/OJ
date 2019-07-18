// 输入一个链表，输出该链表中倒数第k个结点。
#include <iostream>
#include "ListNode.h"

#include <stack>

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    stack<ListNode *> stack;
    ListNode *cur = pListHead;
    while(cur != nullptr){
        stack.push(cur);
        cur = cur -> next;
    }

    unsigned int n = stack.size();

    if(k<=n){
        for(unsigned int i = 1;i<k;i++){
            stack.pop();
        }
    }
    else
        return nullptr;
    return stack.top();

}

int main(int argc, char const *argv[])
{
    
    return 0;
}
