#include <iostream>
#include <string.h>
#include <map>
#include <set>

using namespace std;

bool isIsomorphic(string s, string t) {
    map<char,int> map1,map2;
    map<char,int> no1,no2; //用来存这个字母是第几次出现。
    int n = s.length(),x=0,y=0,j=0;
    for (int i = 0; i < n; ++i) {
        x=map1[s[i]]++;
        y=map2[t[i]]++;
        if(x!=y)
            return false;
        if(x==1){
            no1[s[i]]=j;
            no2[t[i]]=j;
            j++;
        }
    }
    for (int j = 0; j < n; ++j) {
        if(map1[s[j]]!=map2[t[j]]||no1[s[j]]!=no2[t[j]])
            return false;
    }
    return true;
}

int main(){
    cout<<isIsomorphic("abba","abab");
    return 0;
}