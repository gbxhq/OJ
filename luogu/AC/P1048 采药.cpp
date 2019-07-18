#include <iostream>

using namespace std;

int m,n;
int v[105],w[105],ans1[1005],ans2[1005];

int main(){
    cin>>m>>n;
    for (int i = 1 ; i <=n ; ++i) {
        cin>>v[i]>>w[i];
    }
    cout<<"0-1背包\n";
    for (int i = 1; i <= n; ++i) {
        cout<<"前"<<i<<"个物品 容量从"<<m<<"到0\n";
        for (int j = m; j > 0 ; --j) {
            if(j>=v[i])
                ans1[j]=max(ans1[j],ans1[j-v[i]]+w[i]);
            cout<<ans1[j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"完全背包\n";
    for (int i = 1; i <= n; ++i) {
        cout<<"前"<<i<<"个物品 容量从0到"<<m<<"\n";
        for (int j = v[i]; j <= m ; ++j) {
                ans2[j]=max(ans2[j],ans2[j-v[i]]+w[i]);
            cout<<ans2[j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}