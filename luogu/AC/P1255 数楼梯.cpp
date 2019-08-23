#include <iostream>

using namespace std;

int ans[5050][1500];

void getAns(int n){
    int la=1499,lb=1499;
    while (ans[n-1][la]==0&&la>0)
        la--;
    while (ans[n-2][lb]==0&&lb>0)
        lb--;

    int maxLen=la>lb?la:lb,temp=0,i=0;
    for (; i <= maxLen; ++i) {
        ans[n][i]=ans[n-1][i]+ans[n-2][i]+temp;
        temp=ans[n][i]/10;
        ans[n][i]%=10;
    }
    ans[n][i]=temp;
}

int main(){
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<0;
        return 0;
    }

    ans[0][0]=1;
    ans[1][0]=1;

    for (int i = 2; i <= n; ++i)
        getAns(i);

    int l=1499;
    while (ans[n][l]==0 && l>0)
        l--;
    for (int i = l; i >=0 ; --i) {
        cout<<ans[n][i];
    }

    return 0;
}