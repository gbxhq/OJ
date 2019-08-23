#include <iostream>

using namespace std;

int main(){
//    cout<<28800/-16<<' '<<28800%-16<<'\n';
//    cout<<-1800/-16<<' '<<-1800%-16<<'\n';//商112余-8
//    cout<<113*-16<<'\n';
//    cout<<113/-16<<' '<<113%-16<<'\n';
    int n=-25000,r=-16;
    cin>>n>>r;
    int backup=n;
    string ans="";
    while (n){
        int m=n%r;
        n/=r;
        if(m<0)
        {
            m-=r;
            n++;
        }
        if(m>=10)
            ans=(char)('A'+m-10)+ans;
        else
            ans=(char)('0'+m)+ans;
    }
    cout<<backup<<"="<<ans<<"(base"<<r<<')';
    return 0;
}