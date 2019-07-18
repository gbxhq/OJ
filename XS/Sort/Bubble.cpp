//冒泡
#include <iostream>
#include <vector>
#include "../Vt.h"

using namespace std;

void bubbleSort(vector<int> &vt){
    int n=vt.size();
    for (int i = 0; i < n; ++i) {//第i轮起泡
        int maxIndex=0;//本轮最大值先设为vt0
        int flag=1;//是否交换标记
        for (int j = 1; j < n-i; ++j) {//要与其他n-i个数比较
            if(vt[maxIndex]>vt[j]){
                swap(vt[maxIndex],vt[j]);
                maxIndex=j;
                flag=0;
            } else{
                maxIndex=j;
            }
        }
        cout<<"第"<<i<<"轮起泡：";
        showVt(vt);
        if(flag){
            cout<<"本轮没有交换 排序终止";
            return;
        }
    }
}

int main(){
    vector<int > data={1,2,3,4,5,6,7,8};
    bubbleSort(data);
    showVt(data);
    return 0;
}