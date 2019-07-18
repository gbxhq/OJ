#include <iostream>

using namespace std;
int t,m;
int v[10005],w[10005],ans[100005];

int main(){
    cin>>t>>m;
    for (int i = 1; i <= m ; ++i) {
        cin>>v[i]>>w[i];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= t; ++j) {
            if(v[i]<=j)
                ans[j]=max(ans[j],ans[j-v[i]]+w[i]);
        }
    }
    cout<<ans[t];
    return 0;
}