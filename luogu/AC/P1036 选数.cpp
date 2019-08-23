#include <iostream>

using namespace std;

int a[20];
int n,k,cnt = 0;

bool isP(int x){
    if(x==2 || x==3)
        return true;
    if(x%6==5 || x%6==1){
        for (int i = 2; i*i <= x ; ++i) {
            if(x%i==0)
                return false;
        }
        return true;
    } else
        return false;
}

void dfs(int i,int n,int k,int sum){
    if(k==0){
        if(isP(sum)){
            cnt++;
        }
        return;
    }
    if(i>=n)
        return;
    dfs(i+1,n,k,sum);
    dfs(i+1,n,k-1,sum+a[i]);
}

int main(){

    cin>>n>>k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dfs(0,n,k,0);
    cout<<cnt;

    return 0;
}