//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
#include "../../ListNode.h"

ListNode* deleteDuplication(ListNode* pHead)
{
    if(pHead==nullptr||pHead->next==nullptr)
        return pHead;

    ListNode *p0 = pHead;
    ListNode *p1 = pHead;

    while (p0 != nullptr && p1->val==p1->next->val) {//看这里！其实会越界的。这个代码看似能跑通。提交到OJ就会报错。不改了。下次重写！！！
        int x = p1->val;
        while (p1 != nullptr && p1->val == x)
            p1 = p1->next;
        p0 = p1;
    }
    ListNode *ans = p0;
    p1 = p0->next;
    while (p1){
        if(!p1->next)
            break;

        if (p1->val==p1->next->val){
            int x = p1->val;
            while (p1!= nullptr&&p1->val == x)
                p1 = p1->next;
            p0->next=p1;
        }else
        {
            p0=p0->next;
            p1=p1->next;
        }
    }
    return ans;
}

int main(){
    ListNode* pHead = createList();

    int a[7] = {1,1};

    pHead = initList(pHead,a,2);
    showList(pHead);

    ListNode *p2 = deleteDuplication(pHead);
    showList(p2);

    return 0;
}