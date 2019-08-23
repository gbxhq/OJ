#include <iostream>
#include <string>
using namespace std;

int main(){
    int k=2;
    cin>>k;
    // - 的几种情况
    string heng1(k,'-');
    heng1=' '+heng1+"  ";
    string heng2(k,' ');
    heng2=' '+heng2+"  ";
    string HENG1[10]={heng1,"  ",heng1,heng1,heng2,heng1,heng1,heng1,heng1,heng1};
    string HENG2[10]={heng2,"  ",heng1,heng1,heng1,heng1,heng1,heng2,heng1,heng1};
    string HENG3[10]={heng1,"  ",heng1,heng1,heng2,heng1,heng1,heng2,heng1,heng1};
    // | 的几种情况
    string shu(k,' ');
    string shu1='|'+shu+"| ";
    string shu2='|'+shu+"  ";
    string shu3=' '+shu+"| ";
    string SHU1[10]={shu1,"| ",shu3,shu3,shu1,shu2,shu2,shu3,shu1,shu1};
    string SHU2[10]={shu1,"| ",shu2,shu3,shu3,shu3,shu1,shu3,shu1,shu3};
    string s[k*2+3];
    string input="1234567890";
    cin>>input;
    for(int i=0;i<input.length();i++){
        //填充横
        s[0]+=HENG1[input[i]-'0'];
        s[k+1]+=HENG2[input[i]-'0'];
        s[k*2+2]+=HENG3[input[i]-'0'];

        //填充竖
        int j=1;
        while (j<=k){
            s[j++]+=SHU1[input[i]-'0'];
        }
        j=k+2;
        while (j<=k*2+1){
            s[j++]+=SHU2[input[i]-'0'];
        }
    }
    for(string x:s){
        cout<<x<<'\n';
    }
    //截止到上面输出是完美的。
    //奈何洛谷OJ过不了下载了out发现要求连续空格要化成一个
    //故,我选择放弃
    return 0;
}