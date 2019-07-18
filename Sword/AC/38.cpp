//统计一个数字在排序数组中出现的次数。
#include <iostream>
#include "../Vt.h"

using namespace std;

void biSearch(vector<int> vt,int l,int r,int key,int &cnt){
    if(l>r)
        return;
    if(vt[l]>key||vt[r]<key)//肯定找不到，也不用往下二分查了
        return;
    if(vt[l]==key&&vt[r]==key)
        cnt+=r-l+1;
    else if(l<r){
        int mid = (r+l)>>1;
        if(vt[mid]>=key)
            biSearch(vt,l,mid,key,cnt);
        if(vt[mid]<=key)
            biSearch(vt,mid+1,r,key,cnt);
    }
}


int GetNumberOfK(vector<int> data ,int k) {
    int ans = 0;
    biSearch(data,0,data.size()-1,k,ans);
    return ans;
}

int main(){
    vector<int> vt{1,1,2,2,3,3,5};
    cout << GetNumberOfK(vt,0);
    return 0;
}