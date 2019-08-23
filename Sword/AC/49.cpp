//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
// 但是string不符合数字要求时返回0)，
// 要求不能使用字符串转换整数的库函数。
// 数值为0或者字符串不是一个合法的数值则返回0。
//输入描述:
//输入一个字符串,包括数字字母符号,可以为空
//        输出描述:
//如果是合法的数值表达则返回该数字，否则返回0
//输入
//+2147483647
//1a33
//
//输出
//2147483647
//0
#include <iostream>
#include <string>
using namespace std;

int StrToInt(string str) {

    int i=0,n = str.length();
    if(n==0)
        return 0;
    while (str[i]==' ')
        i++;
    int sign = 1;
    if(str[i]=='+')
        i++;
    if(str[i]=='-')
    {
        sign = -1;
        i++;
    }
    //检测越界
    string tmp = str.substr(i);

    if(tmp>"2147483648")
        return 0;
    if(tmp=="2147483648")
        if(sign==-1)
            return -2147483648;
        else
            return 0;

    int ans = 0;
    while (i<n){
        if(str[i]>'9'||str[i]<'0')
            return 0;
        else
            ans = ans*10+(str[i]-'0');
        i++;
    }
    return ans*sign;
}

int main (){
    cout << StrToInt("   +2147483647");
    return 0;
}