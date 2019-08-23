//请实现一个函数用来找出字符流中第一个只出现一次的字符。
// 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
// 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
//Insert one char from stringstream

#include <string>
#include <map>

using namespace std;

string str;
map<char,int> map1;

void Insert(char ch)
{
    str += ch;
    map1[ch]++;
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    for(char x:str)
        if(map1[x]==1)
            return x;
    return '#';
}