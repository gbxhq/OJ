#include <iostream>

using namespace std;

int V,n;
int v[31],ans[20001];

int main(){
    cin>>V>>n;
    for (int i = 1; i <= n ; ++i) {
        cin>>v[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= v[i] ; --j) {
            ans[j]=max(ans[j],ans[j-v[i]]+v[i]);
        }
    }
    cout<<V-ans[V];
    return 0;
}