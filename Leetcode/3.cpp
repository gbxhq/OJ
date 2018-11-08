#include <iostream>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    map<char,int> map;
    int count = 0;
    int max = -99999;
    int start = -9999;
    for(int i=0;i<n;i++){
        if(map.find(s[i])!=map.end()&&map[s[i]]>=start){//存在  //记得排除map里s[i]之前的字母 &&map[s[i]]>=start
            if(count>max)
                max = count;
            count = i-map[s[i]];        
            start = map[s[i]]+1; //字母的开始坐标变成 i+1 。
            map[s[i]] = i; //更新新的 s[i]坐标
        }else{ //不存在则存入
            count++;
            map[s[i]] = i;
        }
    }
    if(count>max)
        max = count;
    return max;
}

int main(int argc, char const *argv[])
{
    string a = "abcabcbb";
    cout<<lengthOfLongestSubstring(a)<<"\n";
 
    return 0;
}
