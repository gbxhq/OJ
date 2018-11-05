#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

int trailingZeroes(int n) {
    int ans = n/5;
    while(n>=25){
        ans++;
        n = n-25;
    }
    return ans;
}


int main(int argc, const char * argv[]) {

    cout<<trailingZeroes(0)<<endl;

    return 0;
}