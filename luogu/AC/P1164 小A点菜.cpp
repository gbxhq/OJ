//更新：一维数组优化：
#include <iostream>

using namespace std;

int N,M,a[105],ans[10005];

int main(){

//    memset(ans,-1, sizeof(ans));

    cin>>N>>M;

    for (int i = 1; i <= N ; ++i) {
        cin>>a[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M ; ++j) {
            if(j==a[i])
                ans[j]++;
            else
                ans[j]=ans[j]+ans[j-a[i]];
//            cout<<ans[j]<<' ';
        }
//        cout<<endl;
    }
//    for (int i = 0; i <= N ; ++i) {
//        for (int j = 0; j <= M ; ++j) {
//            cout<<ans[i][j]<<' ';
//        }cout<<endl;
//    }
    cout<<ans[M];
    return 0;
}
//#include <iostream>
//
//using namespace std;
//int w[105];
//int ans[105][1005];
//int main(){
//    int n,m;
//    cin>>n>>m;
//    for (int i = 1; i <= n; ++i) {
//        cin>>w[i];
//    }
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            if(j==w[i])//钱刚好能买这个菜
//                ans[i][j]=ans[i-1][j]+1;//没有这个菜时的方法数+1
//            if(j>w[i])
//                ans[i][j]=ans[i-1][j]+ans[i-1][j-w[i]];//j元买i种菜的方法数=不买这个菜的方法数+买了这个菜的方法数
//            if(j<w[i])
//                ans[i][j]=ans[i-1][j];//
//        }
//    }
//
//    cout<<ans[n][m];
//
//    return 0;
//}