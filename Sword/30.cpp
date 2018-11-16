/*输入n个整数，找出其中最小的K个数*/
#include <vector>
#include "Vt.h"
using namespace std;

class Solution {
public:
    
void partition(vector<int> &vt,int i,int j, int k){
    int ii=i,jj=j;//backup
    if(i>=j)
        return;
    int x = vt[i];
    while (i<j){
        while (i<j&&vt[j]>x){
            j--;
        }
        if(i<j){
            vt[i]=vt[j];
            i++;
        }
        while (i<j&&vt[i]<x){
            i++;
        }
        if(i<j){
            vt[j]=vt[i];
            j--;
        }
    }
    //此时vt[i]就是第i个数
    vt[i]=x;
    if(i==k)
        return;
    if (i<k){
        partition(vt,i+1,jj,k-i);
    }else
        partition(vt,ii,i-1,k);
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> ans;
    int n = input.size();
    if(k>n)
        return ans;
    //先在0位置插入一个垃圾数占空
    input.insert(input.begin(),999);
    partition(input,1,n,k); //此时vt[1-k]就是答案
    for(int i=1;i<=k;i++){
        ans.push_back(input[i]);
    }
    return ans;
}
};

// //最垃圾的写法。冒泡都不如。别看
// vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//     int n = input.size();
//     vector<int> a;
//     if(k<=0||k>n)
//         return a;

//     for(int i=0; i<k; i++){//注意，我这个写法相当低级。我还以为这是冒泡排序。
//         for(int j=i+1; j<n; j++){
//             if(input[i]>input[j])
//                 swap(input[i],input[j]);
//         }
//     }
//     vector<int> ans(k);
//     copy(input.begin(),input.begin()+k,ans.begin());
//     return ans;
// }

int main(){

    vector<int> input{9,4,2,4,5,6,2};

    vector<int> ans = GetLeastNumbers_Solution(input,3);

    showVt(ans);

    return  0;
}