//上楼梯高级版

#include<iostream>

using namespace std;

int jumpFloorII(int number) {
    if(number==0)
        return 0;
    if(number==1)
        return 1;
    if(number==2)
        return 2;
    int ans = 1;
    for(int i=1;i<=number-1;i++)
        ans += jumpFloorII(i);
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << jumpFloorII(4) << endl;
    return 0;
}
