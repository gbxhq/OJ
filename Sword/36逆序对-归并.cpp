#include <iostream>
#include <vector>
using namespace std;

int ans=0;

void merge(vector<int> &data,int i1,int j1,int i2,int j2){
    vector<int > tmp;
    int i=i1;
    while (i1<=j1&&i2<=j2){
        if(data[i1]<=data[i2])
        {
            tmp.push_back(data[i1]);
            i1++;
        } else{
            tmp.push_back(data[i2]);
            i2++;
            ans+=(j1-i1+1);//这里就是和归并排序唯一不同的地方
            ans%=1000000007;
        }
    }//其中有一个存完了
    while (i1<=j1){
        tmp.push_back(data[i1]);
        i1++;
    }
    while (i2<=j2){
        tmp.push_back(data[i2]);
        i2++;
    }//把剩余的存起来就好了。因为剩余的肯定不存在逆序。故不需要处理ans
    for(int x:tmp){
        data[i++]=x;
    }
}

void split(vector<int> &data,int i,int j){
    if(i<j){
        int mid=(i+j)>>1;
        split(data,i,mid);
        split(data,mid+1,j);
        if(i<=mid&&mid+1<=j)
            merge(data,i,mid,mid+1,j);
    }
}

int InversePairs(vector<int> data) {
    int n=data.size();
    split(data,0,n-1);
    return ans;
}

int main(){
    vector<int > vt={1,2,3,4,5,6,7,0};
    cout<<InversePairs(vt);
    return 0;
}