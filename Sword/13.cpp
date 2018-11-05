// O(1)时间内删除链表节点


# include<iostream>
# include"ListNode.h"

using namespace std;

void DeleteNode(ListNode * pHead, ListNode *pToBeDeleted){
    if(pToBeDeleted->next != nullptr){
        pToBeDeleted -> val = pToBeDeleted -> next -> val;
        // 太简单了不写了！
    }
}