#include <iostream>
#include "ListNode.h"
#include <stack>

using namespace std;
//用stack真low
ListNode* ReverseList1(ListNode* pHead) {
    if(pHead==nullptr || pHead->next == nullptr)
        return pHead;
    ListNode *cur = pHead;
    stack<ListNode *> stack;
    while(cur->next != nullptr){
        stack.push(cur);
        cur = cur -> next;
    }
    ListNode *ans = cur;
    while(!stack.empty()){
        cur->next = stack.top();
        cur = cur->next;
        stack.pop();
    }
    cur ->next = nullptr;
    return ans;
}
//这个也很快就搞定啦。
ListNode* ReverseList2(ListNode* pHead) {
    if(pHead==nullptr || pHead->next == nullptr)
        return pHead;
    ListNode *cur = pHead;
    ListNode *tmp1 = cur->next;
    ListNode *tmp2 = cur->next->next;
    while(tmp2 != nullptr){  
        tmp1 ->next = cur;
        cur = tmp1;
        tmp1 = tmp2;
        tmp2 = tmp2->next;
    }
    tmp1 ->next = cur;
    pHead->next = nullptr;
    return tmp1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
