//丑数
//把只包含质因子2、3和5的数称作丑数（Ugly Number）。
// 例如6、8都是丑数，但14不是，因为它包含质因子7。
// 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
#include <iostream>
#include <vector>
using namespace std;


int min(int a,int b,int c){
    return a<=b&&a<=c? a : b<=c? b: c;
}

int GetUglyNumber_Solutio(int index) {
    if(index<=0)
        return 0;
    vector<int> vt{1,2,3,4,5};
    if(index<=5)
        return vt[index-1];
    int nowMax = 5;
    int m2 = 0,m3 = 0,m5 = 0;
    int t2 = 2,t3 = 1, t5 = 1;
    for(int i=4; i<=index-1; ++i){
//        cout<<"第"<<i<<":";
        while (m2<=nowMax){
            m2 = vt[t2]*2;
            t2++;
        }
//        cout<<"m2:"<<m2<<" ";
        while (m3<=nowMax){
            m3 = vt[t3]*3;
            t3++;
        }
//        cout<<"m3:"<<m3<<" ";
        while (m5<=nowMax){
            m5 = vt[t5]*5;
            t5++;
        }
//        cout<<"m5:"<<m5<<" ";
        int tmp = min(m2,m3,m5);
        vt.push_back(tmp);
//        cout<<"存入："<<tmp<<"\n";
        nowMax = tmp;
    }
    return vt[index-1];
}


int main(){

    cout <<GetUglyNumber_Solutio(1500)<< "\n";

    return 0;
}