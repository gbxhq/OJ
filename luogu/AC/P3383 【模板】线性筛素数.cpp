#include <iostream>

using namespace std;

int a[6]={0,0,1,1,0,1};

bool isPrime(int x){
    //传进来的数一定是6i+/-1形式的
    //故从5开始判断奇数是不是因子即可
    for (int i = 5; i*i <= x ; i+=6) {
        if(x%i==0||x%(i+2)==0)
            return false;
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;

    int q;
    while (m--){
        scanf("%d",&q);
        if(q<=5){
            if(a[q])
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }
        if(q%6!=1&&q%6!=5)
            printf("No\n");
        else
        {
            if(isPrime(q))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}