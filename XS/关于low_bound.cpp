#include <iostream>
#include "../Vt.h"
#include <algorithm>
using namespace std;

int main(){
    vector<int> vt = {1,2,2,2,3,4,5,6,7};
    auto p1 = lower_bound(vt.begin(),vt.end(),2)-vt.begin();
    auto p2 = upper_bound(vt.begin(),vt.end(),2)-vt.begin();
    cout<<p1<<endl;//1 第一个2
    cout<<p2<<endl;//4 3的位置
    //下面vt改成降序
    vt = {7,6,6,6,5,4,3,2,1};
    //最后传入的比较函数应改成greater<int>()
    auto p3 = lower_bound(vt.begin(),vt.end(),6,greater<int>())-vt.begin();
    auto p4 = upper_bound(vt.begin(),vt.end(),6,greater<int>())-vt.begin();
    cout<<p3<<endl;//1 第一个6
    cout<<p4<<endl;//4
    return 0;
}