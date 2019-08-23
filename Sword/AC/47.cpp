//不用+-*做加法/
#include <iostream>
using namespace std;
int Add(int num1, int num2)
{
    int a = num1^num2; //第一步异或

    int b = num1&num2;
    b = b << 1;  //第二步进位

    if(b==0)
        return a^b;
    else
        return Add(a,b);
    //最后证实，不加return 连结果都会错。为什么呢？
}

int main(){

    cout<< Add(11,10);

    return 0;
}