//一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
#include <iostream>
#include <map>
#include "../Vt.h"

/*容易想到的map方法。没技术含量
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    map<int,int> m;
    for(int x:data){
        m[x]++;
    }
    int flag=1;
    auto x = m.begin();
    while (x!=m.end()){
        if(x->second==1){
            if(flag)
            {
                *num1 = x->first;
                flag = 0;
            }
            else
            {
                *num2 = x->first;
                break;
            }
        }
        x++;
    }
}*/
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int all=0;
    for(int x:data)
        all ^= x;//all就是全部异或的结果
//    cout << all << "\n";
    //找到x第一个是1的位（这个位就是 num1和num2 在此位不同所致
    int i=0;
    while (!(all&1)){// &1 就是只保留这个数的最后一位
        all = all>>1;
//        cout << all << "\n";
        i++;
    }
//    cout << i << "\n";
    for(int x:data){
        if((x>>i)&1)
            *num1 ^= x;
        else
            *num2 ^= x;
    }
}

int main(){
    vector<int> vt{2,4,3,6,3,2,5,5};
    int a,b;
    FindNumsAppearOnce(vt,&a,&b);
    cout << a<< " "<<b;
    return 0;
}