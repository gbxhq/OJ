#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[100005],ans1[100005],ans2[100005];

int main(){
    int i=0;
    while (cin>>a[i]){
        i++;
    }
    int n=i;
    int len1=1,len2=1;
    ans1[1]=a[0];
    ans2[1]=a[0];
    for (i = 1; i < n; ++i) {
        if(a[i]<=ans1[len1])
            ans1[++len1]=a[i];
        else{
            auto p = upper_bound(ans1+1,ans1+1+len1,a[i],greater<int>())-ans1;
            ans1[p] = a[i];
        }
        if(a[i]>ans2[len2])
            ans2[++len2]=a[i];
        else{
            auto p = lower_bound(ans2+1,ans2+1+len2,a[i])-ans2;
            ans2[p] = a[i];
        }
//        for (int j = 1; j <= len2; ++j) {
//            cout<<ans2[j]<<' ';
//        }cout<<'\n';
    }
    cout << len1 <<'\n'<< len2;
    return 0;
}