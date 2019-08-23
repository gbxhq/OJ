#include <iostream>

using namespace std;

int n,k;
int ans[100001]={1,1};

void go(int x){
    for (int i=1;i<=k&&x-i>=0;i++){
        ans[x]+=ans[x-i];
        ans[x]%=100003;
    }
}

int main(){
    cin>>n>>k;
    for(int i=2;i<=n;i++)
        go(i);

//    for(int i=2;i<=n;i++)
//        cout<<ans[i]<<' ';
//    cout<<endl;
    cout<<ans[n];
    return 0;
}