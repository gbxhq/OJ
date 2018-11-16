/* 题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 */
#include<iostream>

using  namespace std;

int  NumberOf1(int n) {
    int flag = 1,ans = 0;
    while(flag){
        if(n&flag)
            ans ++;
        flag = flag << 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << NumberOf1(-1);
    return 0;
}
