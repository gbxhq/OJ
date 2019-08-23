#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int k,n;
    scanf("%d",&k);
    n = 1;
    double s = 0.00000;
    while (s<k*1.0){
        s += 1.0/n;
        n++;
    }
    printf("%d",n-1);
    return 0;
}