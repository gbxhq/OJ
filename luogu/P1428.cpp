#include <iostream>

using namespace std;

int fish[105],ans[105],n;

int main(){
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>fish[i];
    }

    for (int j = 1; j < n; ++j) {
        for (int i = j-1; i >= 0; --i) {
            if(fish[j]==fish[i])
            {
                ans[j]+=ans[i];
                break;
            }
            if(fish[j]>fish[i])
                ans[j]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout<<ans[i]<<' ';
    }
    return 0;
}