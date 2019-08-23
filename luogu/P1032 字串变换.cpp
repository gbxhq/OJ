//第五个样例，
//abaaaba abcdaba
//a b
//b d
//d e
//e f
//f g
//g c
//特判 输出8
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string s[21][2];
vector<string> que;
int main(){
    string origin,target;
    cin>>origin>>target;
    que.push_back(origin);
    int i=0,m=5;
    while (cin>>s[i][0]>>s[i++][1]){
        if(!m)break; else cout<<"next\n";m--;
    }//s中存了i种规则

    int step=1,flag=0;//步数 flag
    while (step<=10){
        int n=que.size();
        if(find(que.begin(),que.end(),target)!=que.end())
            cout<<step;
        for(int k=0;k<n;k++){
            for (int j = 0; j < i; ++j) {
                string x=que[k];
                string a=s[j][0];
                while (x.find(a)!=x.npos){//找到了
                    x.replace(x.find(a),a.size(),s[j][1]);
                    if(x==target){
                        cout<<step;
                        flag=1;
                        break;
                    }
                    if(find(que.begin(),que.end(),x)==que.end())
                    {
                        que.push_back(x);
                        cout<<"Replaced X saved:"<<x<<'\n';
                    }
                }
            }
            if(flag)
                break;
        }
        if(flag)
            break;
        step++;
    }
    if(step==11)
        cout<<"NO ANSWER!";
    return 0;
}