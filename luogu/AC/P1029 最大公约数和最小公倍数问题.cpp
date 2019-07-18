#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(){
    int x=3,y=60;
    cin>>x>>y;
    int ans=0;
    for (int i = 1; i*x <= y; ++i) {
        if(y%i==0){
            if(gcd(x*i,y/i)==x)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}