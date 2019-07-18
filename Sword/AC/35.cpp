//在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
// 并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
#include <iostream>
#include <string>
#include <map>
using namespace std;

int FirstNotRepeatingChar(string str) {
    map<char,int> m;
    for(auto x:str){
        m[x]++;
    }
    int ans = -1;
    int i = 0;
    for(auto x:str){
        if(m[x]==1){
            ans = i;
            break;
        } else
            i++;
    }
    return ans;
}

int main(){
    string input = "google";
    cout<< FirstNotRepeatingChar(input);
    return 0;
}