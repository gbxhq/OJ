#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n=3,m=5,ans[31][31];

void go(int i,int j){
    if(j==0)
        return;
    ans[i][j]=ans[(i-1+n-1)%n+1][j-1]+ans[(i+1-1)%n+1][j-1];
}

int main(){
    cin>>n>>m;
    memset(ans,0, sizeof(ans));
    ans[1][0]=1;
    ans[2][1]=1;
    ans[m][1]=1;
    //n个人传m次的情况 先看传1次 再看传2次…
    for (int j = 1; j <= m ; ++j) {
        for (int i = 1; i <= n ; ++i) {
            go(i,j);
        }
    }
    cout<<ans[1][m];
//    for (int i = 1; i < 6; ++i) {
//        cout<<"第"<<i<<"个人: ";
//        for (int j = 1; j < 5; ++j) {
//            cout<<ans[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
    return 0;
}