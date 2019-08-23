#include <iostream>

using namespace std;

int a[2500],b[2500],ans[5000];

void multiply(int n,int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i+j]+=a[i]*b[j];
        }
        for (int k = 0; k < m+n; ++k) {
            ans[k+1]+=ans[k]/10;
            ans[k]%=10;
        }
    }
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    int sign=0;
    if(s1[0]=='-')
    {
        sign++;
        s1.erase(0,1);
    }
    if(s2[0]=='-')
    {
        sign++;
        s2.erase(0,1);
    }
    if(sign==1)
        cout<<'-';

    int la=s1.size(),lb=s2.size();
    for (int i = 0; i < la; ++i) {
        a[la-i-1]=s1[i]-'0';
    }
    for (int i = 0; i < lb; ++i) {
        b[lb-i-1]=s2[i]-'0';
    }

    multiply(la,lb);

    //倒序输出
    int maxLen=la+lb;
    while (ans[maxLen]==0&&maxLen>0)//注意控制maxLen最小减成0
        maxLen--;
    for (int i = maxLen; i >= 0 ; --i) {
        cout<<ans[i];
    }

    return 0;
}