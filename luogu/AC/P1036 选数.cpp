//排列组合求和

#include <iostream>
#include <math.h>
using namespace std;

bool check(int x){
    for (int i = 2; i <= sqrt(x); ++i) {
        if(x%i==0)
            return false;
    }
    return true;
}

int a[20];
int ans = 0;

void solution(int i,int n,int k,int sum){
    if(i>=n)
        return;
    sum += a[i];
//    cout <<"+"<<a[i];
    if(k==1){
        ans += check(sum);
//        cout << "=" << sum <<", ANS+"<< ans<<endl;
        solution(i+1,n,1,sum-a[i]);
        return;
    } else{
        solution(i+1,n,k-1,sum);
    }
    solution(i+1,n,k,sum-a[i]);
}

int main(){
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solution(0,n,k,0);
    cout << ans;
}


