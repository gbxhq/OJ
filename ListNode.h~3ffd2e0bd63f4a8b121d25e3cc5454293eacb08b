#include<iostream>
#include<set>

using namespace std;
typedef struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){} 

}ListNode;
ListNode *createList() //创建头，申请一个ListNode空间
{
    ListNode *prehead = new ListNode(-1);
    return prehead;
}
ListNode *initList(ListNode *preheadInit, int *a, int n) //用数组初始化链表，传入一个数组名和大小即可。数组名本身就是首字符的地址，因此不用加&
{
    ListNode *cur,*head;
    cur = preheadInit;
    for(int i = 0;i < n;i++)
    {
        ListNode *p = new ListNode(a[i]);
        cur->next = p;
        cur = cur->next;
    }
    head = preheadInit;
    return head->next; 
}

void showList(ListNode *head)
{
    while(head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "Null\n";
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode *> set;
    ListNode *curA = headA;
    while(curA){
        set.insert(curA);
        curA = curA -> next;
    }
    while(headB){
        if(set.find(headB)==set.end())
        {
            headB = headB->next;
            continue;
        }    
        else
            break;
    }
    return headB;
}

// int main()
// {
//     ListNode *prehead = createList();
//     ListNode *head = initList(prehead);
//     ListNode *prehead2 = createList();
//     ListNode *head2 = initList2(prehead);
//     ListNode *prehead3 = createList();
//     ListNode *head3 = initList3(prehead);

//     ListNode *cur = head;
//     while(cur->next)
//         cur = cur->next;
//     cur->next = head3;

//     ListNode *cur2 = head2;
//     while(cur2->next)
//         cur2 = cur2->next;
//     cur2->next = head3;
        
//     showList(head);
//     printf("\n");

//     ListNode *ans = getIntersectionNode(head,head2);
//     showList(ans);

//     printf("\n");

//     return 0;
// }