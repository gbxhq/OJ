/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序
列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）*/
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;


int main(int argc, char const *argv[])
{
    int a[10] = {1,2,3,4,5,4,5,3,2,1};
    vector<int> vt1 (a,a+5);
    vector<int> vt2 (a+5,a+10);

    cout << IsPopOrder(vt1,vt2);   
    return 0;
}
