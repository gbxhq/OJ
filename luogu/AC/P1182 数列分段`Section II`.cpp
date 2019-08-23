#include <iostream>

using namespace std;

int n,m,a[100005];

bool judge(int x){
    int group=1,sum=0;
    for (int i = 0; i < n; ++i) {
        if(sum+a[i]>x){
            sum=a[i];
            group++;
            if(group>m)
                break;
        } else{
            sum+=a[i];
        }
    }
    return group<=m;//说明分的组数可以再m之内
}

int main(){
    cin>>n>>m;
    int l=0,r=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        r+=a[i];
        if(a[i]>l)
            l=a[i];
    }
    //答案区间：[l,r]即[max,sum]
    int ans=0;
    while (l<=r){
        int m=(l+r)>>1;
        if(judge(m)){//分m组能分成功
            ans=m;
            r=m-1;
        } else{//分不成功
            l=m+1;
        }
    }
    cout<<ans;
    return 0;
}