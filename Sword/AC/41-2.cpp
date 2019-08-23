//输入一个递增排序的数组和一个数字S，
// 在数组中查找两个数，使得他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的。
#include "../Vt.h"

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    int n = array.size();
    vector<int > ans;
    if(n<=1)
        return ans;
    int i=0,j=n-1;
    while (i<j){
        int s = array[i]+array[j];
        if(s==sum)
        {
            ans.push_back(array[i]);
            ans.push_back(array[j]);
            break;
        }
        if(s<sum)
            i++;
        if(s>sum)
            j--;
    }
    return ans;
}

int main(){

    return 0;
}