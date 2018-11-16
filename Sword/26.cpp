/*输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）*/
#include<iostream>
#include<map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

RandomListNode* Clone(RandomListNode* pHead)
{
    RandomListNode *ans = new RandomListNode(-1);
    RandomListNode *cur = ans;

    map<RandomListNode *,RandomListNode *> map;

    while(pHead!=nullptr){

        if(map.find(pHead)!=map.end()){//如果有就不new了
            cur->next = map[pHead];
            cur = cur->next;
        }else{//没有就new了 并存到map里
            RandomListNode *tmp = new RandomListNode(pHead->label);
            map[pHead] = tmp;
            cur->next = tmp;
            cur = cur->next;
        }

        if(pHead->random){//之前没有套着一层if，导致有的节点是没有random指针的，这时候取空指针的label就会报错
            //寻找 map 中有没有 pHead的random
            if(map.find(pHead->random)!=map.end()){//如果有就指向
                cur->random = map[pHead->random];
            }else{//没有就new了并存到map里
                RandomListNode *tmp = new RandomListNode(pHead->random->label);
                map[pHead->random] = tmp;
                cur->random = tmp;
            }
        }

        pHead = pHead->next;

    }

    return ans->next;
}

int main(int argc, char const *argv[])
{
    RandomListNode *A = new RandomListNode(1);
    RandomListNode *B = new RandomListNode(2);
    RandomListNode *C = new RandomListNode(3);
    RandomListNode *D = new RandomListNode(4);
    A->next = B;
    B->next = C;
    C->next = D;

    A->random = C;
    B->random = C;
    C->random = A;
    D->random = C;

    RandomListNode *AA = Clone(A);
    RandomListNode *BB = AA->next;
    RandomListNode *CC = BB->next;
    RandomListNode *DD = CC->next;

    cout<<AA->label<<" "<<BB->label<<" "<<CC->label<<" "<<DD->label<<"\n";
    cout<<AA->random->label<<" "<<BB->random->label<<" "<<CC->random->label<<" "<<DD->random->label<<"\n";

    return 0;
}
