//每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
// HF作为牛客的资深元老,自然也准备了一些小游戏。// 其中,有个游戏是这样的:
// 首先,让小朋友们围成一个大圈。
// 然后,他随机指定一个数m,让编号为0的小朋友开始报数。
// 每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,
// 并且不再回到圈中,
// 从他的下一个小朋友开始,继续0...m-1报数....这样下去....
// 直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
// 请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

#include <iostream>
#include "../Vt.h"
using namespace std;

int LastRemaining_Solution1(int n, int m)
{
    if(n==0||m==0)
        return -1;
    vector<int> vt(n,1);
    showVt(vt);
    int sur = n,j=0;
    while (sur>1){
        int tmp = m%sur;
        if(tmp==0)  tmp = sur;
        int i=1;//i是计数器。j是遍历坐标
        //找到第tmp个0的数
        while (i<=tmp){
            if(j==n)
                j=0;
            if(i==tmp&&vt[j]){
                vt[j]=0;
                break;
            }
            if(vt[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        showVt(vt);
        sur--;
    }
    int i=0;//计数
    for(int x:vt)
        if(x==1){
            return i;
        } else
            i++;
}

int LastRemaining_Solution(int n,int m){
    if(n==1)
        return 0;
    return (LastRemaining_Solution(n-1,m)+m)%n;
}

int main(){

    cout<<LastRemaining_Solution1(52,5);

    cout << "\n公式法：\n" <<LastRemaining_Solution(52,5);

    return 0;
}