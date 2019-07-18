#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int ans=0,sum=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int avg = sum/n;
    for (int j = 0; j < n; ++j) {
        a[j]-=avg;
    }
    int temp = 0;
    for (int k = 0; k < n; ++k) {
        a[k]-=temp;
        if(a[k]==0)
        {
            temp=0;
            continue;
        }
        temp = 0 - a[k];
        ans++;
    }
    cout<<ans;
    return 0;
}