//是不是后序遍历
#include<iostream>
#include<vector>
using namespace std;

bool yesOrNo(vector<int> vt, int start, int end){
    if(start>=end)
        return true;
    //取出最后一个元素做比较
    int x = vt[end];
    
    int i = start;
    while(i<end){
        if(vt[i]>x)
            break;
        else
            i++;
    }//i的位置应该是第一个大于x的数。
    int j = i-1; //j是最后一个小于x的数
    while(i<end){
        if(vt[i]<x)
            return false;
        else
            i++;
    }
    return yesOrNo(vt,start,j) &&
        yesOrNo(vt,j+1,end-1);
    return true;
}

bool VerifySquenceOfBST(vector<int> sequence) {
    int n = sequence.size();
    if(n==0)
        return false;
    return yesOrNo(sequence, 0, n-1);
}

int main(int argc, char const *argv[])
{
    int a[5] = {1,6,3,4,5};
    vector<int> vt (a,a+5);

    cout << VerifySquenceOfBST(vt);
    return 0;
}
