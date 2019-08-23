//给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
// 例如，
// 如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
// 那么一共存在6个滑动窗口，
// 他们的最大值分别为{4,4,6,6,6,5}；
// 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
// {[2,3,4],2,6,2,5,1}，
// {2,[3,4,2],6,2,5,1}，
// {2,3,[4,2,6],2,5,1}，
// {2,3,4,[2,6,2],5,1}，
// {2,3,4,2,[6,2,5],1}，
// {2,3,4,2,6,[2,5,1]}。

#include "../../Vt.h"
#include <list>
int findMax(list<int> stk){
    int max = INT_MIN;
    for(int x:stk)
        if(x>max)
            max = x;
    return max;
}
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    int i=0 , n = num.size(), max = INT_MIN;
    vector<int> ans;
    if(size>n||n==0)
        return ans;
    list<int > stk;
    for(;i<size;i++){
        stk.push_back(num[i]);
    }
    ans.push_back(findMax(stk));
    for(;i<n;i++){
        stk.push_back(num[i]);
        stk.pop_front();
        ans.push_back(findMax(stk));
    }
    return ans;
}

int main(){

    return 0;
}