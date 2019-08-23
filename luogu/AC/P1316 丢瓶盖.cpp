#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n,m,a[100005];

bool judge(int x){
    int group=1,head=0,next=0;
    for (int i = 1; i < n; ++i) {
        if(a[i]-a[head]>=x){
            group++;
            if(group>m)
                break;
            head=i;
        }
    }
    return group>=m;
}

int main(){
    cin>>n>>m;

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a,a+n);
    int minInterval=INT_MAX;
    for (int i = 1; i < n; ++i) {
        if(a[i]-a[i-1]<minInterval)
            minInterval=a[i]-a[i-1];
    }
    int l=minInterval,r=a[n-1]-a[0],maxInterval=0;
    while (l<=r){
        int m=(l+r)>>1;
        if(judge(m)){
            maxInterval=m;
            l=m+1;
        } else{
            r=m-1;
        }
    }
    cout<<maxInterval;
    return 0;
}