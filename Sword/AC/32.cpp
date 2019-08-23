//题目描述
////求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
//// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
//// 但是对于后面问题他就没辙了。
//// ACMer希望你们帮帮他,并把问题更加普遍化
//// ,可以很快的求出任意非负整数区间中1出现的次数
//// （从1 到 n 中1出现的次数
#include <iostream>

using namespace std;

int NumberOf1Between1AndN_Solution(int x){
    int ans = 0;
    int weight = 0; //本轮的个位数
    int round = 0;  //出现次数
    int times = 1; //本轮倍数
    int last = 0; //存已经处理过的位数
    while (x){
        round = x/10;
        ans += round*times;
        weight = x%10;
        if(weight>1)
            ans += 1*times;
        if(weight==1)
            ans += last+1;
        last += weight*times; //上一位存在last[错] 是上一位weight*times
        times *= 10;
        x = x/10;
    }
    return ans;
}

int main(){
    cout<<NumberOf1Between1AndN_Solution(21345);
    return 0;
}