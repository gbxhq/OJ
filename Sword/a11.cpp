#include <iostream>

using namespace std;

double Power(double base, int exponent) {
    double ans=base;
    if(exponent == 0)
        // ans = 1; 为什么这么写就跑不通呢？？？
        return 1;
    if(exponent < 0){
        int x = exponent * -1;
        while(x!=1){
            ans *= base;
            x --;
        }
        ans = 1/ans;
    }
    else{
        int x = exponent;
        while(x!=1){
            ans *= base;
            x --;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << Power(3.1,0) ;
    return 0;
}
