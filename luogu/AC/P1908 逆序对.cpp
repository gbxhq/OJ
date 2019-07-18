#include <iostream>
#include <vector>

using namespace std;

long long ans=0;

void merge(vector<int> &data,int i1,int j1,int i2,int j2){
    vector<int > tmp;
    int i=i1;
    while (i1<=j1&&i2<=j2){
        if(data[i1]<=data[i2]){
            tmp.push_back(data[i1]);
            i1++;
        } else{
            tmp.push_back(data[i2]);
            i2++;
            ans+=j1-i1+1;
        }
    }
    while (i1<=j1){
        tmp.push_back(data[i1]);
        i1++;
    }
    while (i2<=j2){
        tmp.push_back(data[i2]);
        i2++;
    }
    for(int x:tmp){
        data[i++]=x;
    }
    return;
}

void nixu(vector<int> &data,int i,int j){
    if(i<j) {
        int mid = (i + j) >> 1;
        nixu(data, i, mid);
        nixu(data, mid + 1, j);
        if (i <= mid && mid + 1 <= j)
            merge(data, i, mid, mid + 1, j);
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    nixu(a,0,n-1);
    printf("%lld",ans);
    return 0;
}