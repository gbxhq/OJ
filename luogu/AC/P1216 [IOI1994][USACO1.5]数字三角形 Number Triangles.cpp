#include <iostream>

using namespace std;

int R,a[1005][1005],ans[1005][1005];

int main(){
    cin>>R;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= i ; ++j) {
            cin>>a[i][j];
        }
    }
    int maxValue=0;
    for (int i = 1; i <= R ; ++i) {
        for (int j = 1; j <= i; ++j) {
            ans[i][j]=max(ans[i-1][j-1],ans[i-1][j])+a[i][j];
            if(ans[i][j]>maxValue)
                maxValue=ans[i][j];
        }
    }
    cout<<maxValue;
    return 0;
}