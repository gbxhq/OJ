#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

void show(vector<char> vt){
    for(auto c:vt){
        cout<<c<<" ";
    }
}

int compress(vector<char>& s) {
    int n = s.size();
    for (int i=0; i<n-2 ;i++){
        if(s[i]!=s[i+1])
            i++;
        else{
            int m = 2;
            int tmp = i+1;
            while(++tmp!=n&&s[tmp]==s[i]){
                m++;
            }
            //到此统计出m个字符 tmp存了不是s[i]的第一个位置
            
            if(m<10){
                s[++i]='0'+m;
            }else if(m<100){
                int a = m/10;
                s[++i]='0'+a;
                a = m - a*10;
                s[++i]='0'+a;
            }else if(m<1000){
                int a = m/100;
                s[++i]='0'+a;
                a = m - a*100;
                int b = a/10;
                s[++i]='0'+b;
                a = a - b*10;
                s[++i]='0'+a;
            }else{
                s[++i]='1';
                s[++i]='0';
                s[++i]='0';
                s[++i]='0';
            }
            //开始往前移
            while((tmp<n){
                s[i++] = s[tmp++]; 
            }
            s.pop_back;
        }
    }
    
    show(s);
    return s.size();
}

int main(int argc, const char * argv[]) {

    vector<char> vt;
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');
    vt.push_back('a');

    cout<<compress(vt);
    return 0;
}