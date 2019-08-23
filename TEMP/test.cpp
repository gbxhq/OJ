#include <iostream>
#include <limits.h>
using namespace std;

int n=7;
int data[200001],ans[200001];

void dpFind(int i){
    //以i为结尾的串最大和
    //有两种情况
    int x=ans[i-1]+data[i];//以i-1为结尾的串的最大和，
    // 加上data[i]组成更大的
    int y=data[i];//还不如不加前面的大
    ans[i]=x>y?x:y;
    return;
}

int main(){
    cin>>n;
    
    for (int i = 0; i < n; ++i) {
        cin>>data[i];
    }
    int max=data[0];
    ans[0]=data[0];
    for (int j = 1; j < n; ++j) {
        dpFind(j);
        cout<<"ans."<<j<<"="<<ans[j]<<'\n';
        if(ans[j]>max)
            max=ans[j];
    }
//    for (int k = 0; k < n; ++k) {
//        cout<<ans[k]<<' ';
//    }
    cout<<max;
    return 0;
}