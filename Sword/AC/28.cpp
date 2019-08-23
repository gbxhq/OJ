/*题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 例如输入字符串abc,
 则打印出由字符a,b,c所能排列出来的所有字符串
 abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

set<string> ansSet;

void save(string abc,int i,int n){
    if(i==n) {
        ansSet.insert(abc);
        return;
    }
    if(i>n)
        return;
    //第i个数分别取一遍
    for(int j=i;j<n;j++){
        string tmp = abc;
        char a = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = a;
        save(tmp,i+1,n);
    }
}

vector<string> Permutation(string str) {
    vector<string> ans;
    int strSize = str.size();
    if(strSize==0)
        return  ans;
    multiset<char> s;
    for(int i=0;i<strSize;i++){
        s.insert(str[i]);
    }
    int n = s.size();
    string abc(n,' ');
    int i = 0;
    for(auto it = s.begin();it!=s.end();it++)
        abc[i++]=*it;
    save(abc,0,n);


    for( auto s: ansSet)
        ans.push_back(s);
    return  ans;
}

int main(){
    vector<string> vt = Permutation("avve");

    for(auto str: vt){
        cout<< str << " ";
    }
}
