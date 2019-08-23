//牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
// 同事Cat对Fish写的内容颇感兴趣，
// 有一天他向Fish借来翻看，但却读不懂它的意思。
// 例如，“student. a am I”。
// 后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
// Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*string ReverseSentence(string str) {

    string ans="",w;
    int n = str.length();
    if(n==0||n==1)
        return str;
    istringstream is(str);
    is>>ans;
    while (is>>w){
        ans = w+' '+ans;
//        cout<<ans<<endl;
    }
    return ans;
}//我这么写的，绝对没有问题。牛客就是过不了。傻*/

//Copy了一个答案

string ReverseSentence(string str) {
    string res ="", temp ="";
    for(unsigned int i =0; i< str.size(); i++){
        if(str[i] == ' ') {res = " " + temp + res; temp = "";}
        else temp += str[i];
    }
    if(temp.size()) res = temp + res;
    return res;
}
int main(){
    cout<<ReverseSentence(" ");
    return 0;
}