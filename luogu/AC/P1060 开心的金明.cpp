#include <iostream>

using namespace std;

int main(){
    int m,n;
    int v[30],w[30],ans[300000];
    cin>>m>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>w[i]>>v[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; w[i] <= j ; --j) {//重量从m递减
            ans[j]=max(ans[j],ans[j-w[i]]+w[i]*v[i]);
        }
    }
    cout<<ans[m];
    return 0;
}