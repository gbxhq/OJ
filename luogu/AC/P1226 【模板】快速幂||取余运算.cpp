#include <iostream>
#include <math.h>
using namespace std;

int quickPow(int b,int p){
    int ans=1;
    while (p)
    {
        if(p&1){//等价于p是奇数
            ans*=b;
        }
        p>>=1;//p/=2
        b*=b;
    }
    return ans;
}

long long quickPowMod(long long b,long long p,long long k){
    long long ans=1;
    while (p){
        if(p&1){
            ans*=b;
            ans%=k;
        }
        p>>=1;
        b*=b;
        b%=k;
    }
    return ans%k;
}

int main(){
//    cout<<quickPowMod(2,10,9);
    long long b,p,k;
    cin>>b>>p>>k;
    cout<<b<<'^'<<p<<" mod "<<k<<"="<<quickPowMod(b,p,k);
    return 0;
}