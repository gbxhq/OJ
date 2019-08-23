#include <iostream>
#define ll long long
#define MOD 1000000007

using namespace std;

ll n,m,a;
ll b[101];

ll power(ll a,ll b){
    ll ans=1;
    while (b){
        if(b&1){
            ans*=a;
            ans%=MOD;
        }
        a*=a;
        b>>=1;
    }
    return ans%MOD;
}

ll f(ll x){
    ll sum=0;
    for (ll i = 0; i <= m ; ++i) {
        sum+=(b[i]%MOD)*(power(x,i)%MOD);
        sum%=MOD;
    }
    return sum%MOD;
}

ll s(ll n){
    ll sum=0;
    for (ll k = 0; k <= n ; ++k) {
        sum+=(power(a,k)%MOD)*f(k);
        sum%=MOD;
    }
    return sum%MOD;
}

int main(){

    cin>>n>>m>>a;
    for (ll i = 0; i <= m; ++i) {
        cin>>b[i];
    }

    cout<<s(n);

    return 0;
}