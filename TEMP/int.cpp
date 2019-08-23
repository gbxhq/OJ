# include <iostream>
# include <vector>
#include <math.h>

using namespace std;

int trailingZeroes(int n) {
    if(n==0)
        return 0;
    int ans = n/5;
    
    for(int i=2;pow(5,i)<=n;i++){
        int tmp = n;
        while(tmp>=pow(5,i)){
            ans ++;
            tmp -= pow(5,i);
        }
        cout<<i<<endl;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code 
    1808548329
    */
   int x  = pow(5,13);
   cout<< x <<endl;
    return 0;
}
