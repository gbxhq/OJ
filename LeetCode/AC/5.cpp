/* 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb" */
#include<iostream>

using namespace std;

int getLength(string s,int i, int j,int n){//i和j是相同字符的下标。n是s长度
    int length = i+1==j? 0 : 1;
    while(i>=0&&j<n){
        if(s[i]!=s[j])
            break;
        if(s[i]==s[j])
            length += 2;
        i--;j++;
    }
    return length;
}

string longestPalindrome(string s) {
    int n = s.size();
    if(n==1)
        return s;
    if(n==2){
        if(s[0]==s[1])
            return s;
        else
            return s.substr(0,1);
    }
    int max = 1;//长度
    int max_start = 0;//开始坐标
    //寻找偶数长度的串
    for(int i=0; i<n-1; i++){
        if(i+max/2>n+1)
            break;
        if(s[i]==s[i+1]) {
            int tmp =getLength(s, i, i + 1, n);
            if (tmp > max) {
                max = tmp;
                max_start = i - max/2 + 1;
            }
        }
    }
    //寻找奇数长度的串
    for(int i=1; i<n-1; i++){
        if(i+max/2>n+1)
            break;
        if(s[i-1]==s[i+1]){
            int tmp = getLength(s,i-1,i+1,n);
            if(tmp > max) {
                max = tmp;
                max_start = i - (max-1)/2 ;
            }
        }
    }
    return s.substr(max_start,max);
}

int main(int argc, char const *argv[])
{
    string a = longestPalindrome("babadada");

    cout << a << "\n";

    return 0;
}









//后记：在一个地方看到的：除去标程中的分类讨论外，其实有另一种方法，就是在任意两个字符之间插入一个通用字符，使得所有回文串的长度都变成奇数，来简化讨论，当然在最后输出答案的时候需要将这些通用字符去除