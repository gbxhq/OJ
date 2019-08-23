#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

int n,x,ans;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x,q.push(x);
    while(q.size()>=2){
        int a=q.top(); q.pop();
        int b=q.top(); q.pop();
        ans+=a+b;
        q.push(a+b);
    }
    cout<<ans<<endl;
    return 0;
}

//int n=0,ans=0;
//void merge(int *a){
//    int minIndex=0;
//    int minValue=a[0];
//    for (int i = 0; i < n; ++i) {
//        if(a[i]&&a[i]<minValue){
//            minIndex=i;
//            minValue=a[i];
//        }
//    }
//    int secondIndex=0;
//    int secondValue=INT_MAX;
//    for (int j = 0; j < n; ++j) {
//        if(a[j]&&a[j]<secondValue&&j!=minIndex){
//            secondIndex=j;
//            secondValue=a[j];
//        }
//    }
//    a[minIndex]=a[minIndex]+a[secondIndex];
//    ans+=a[minIndex];
//    a[secondIndex]=INT_MAX;
//}
//
//int main(){
//
//    cin>>n;
//    int a[n];
//    for (int i = 0; i < n; ++i) {
//        cin>>a[i];
//    }
//
//    if(n==1)
//        cout<<a[0];
//    else{
//        for (int i = 0; i < n-1; ++i) {
//            merge(a);
//        }
//    }
//    cout<<ans;
//    return 0;
//}