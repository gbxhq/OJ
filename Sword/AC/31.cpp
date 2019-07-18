//给一个数组，返回它的最大连续子序列的和
// 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
#include <iostream>
#include <vector>

using namespace std;
/*
void maxSum(vector<int> vt,int i,int n,int &nowMax){
    int sum = 0;
    int ii=i;
    if(i>=n)
        return;
    for(;i<n;i++){
        sum+=vt[i];
        if(sum>nowMax){
            nowMax=sum;
        }
    }
    maxSum(vt,ii+1,n,nowMax);
}
int FindGreatestSumOfSubArray(vector<int> array){
    int ans=-999;
    int n = array.size();
    maxSum(array,0,n,ans);
    return ans;
}
这是用的暴力的方法*/

int dpFind(vector<int> vt,int i,int &finalAns){
    int nowMax=-999,lastMax = -999;
    if(i-1>=0)
        lastMax = dpFind(vt,i-1,finalAns);
    if(lastMax>0)
        nowMax = lastMax+vt[i];
    else
        nowMax = vt[i];
    if(nowMax>finalAns)
        finalAns = nowMax;
    return nowMax;
}

int FindGreatestSumOfSubArray(vector<int> array){
    int n = array.size();
    int ans = -999;
    dpFind(array,n-1,ans);//开始没传最后一个参数。返回的结果是从最后一个开始的最大子串。应该用变量存下整个递归过程的最大参数。
    return ans;
}

int main(){
    vector<int> vt{1,-2,3,10,-4,7,2,-5};
    cout<< FindGreatestSumOfSubArray(vt);
    return 0;
}