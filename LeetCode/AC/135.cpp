#include <iostream>
#include "../../Vt.h"
#include <numeric>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> ans(n,1);
    for(int i=1; i<n; i++){
        if(ratings[i]>ratings[i-1])
            ans[i]=ans[i-1]+1;
    }
    showVt(ans);
    for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]&&ans[i]<=ans[i+1])
            ans[i]=ans[i+1]+1;
    }
    showVt(ans);
    return accumulate(ans.begin(),ans.end(),0);
}

int main(){

    vector<int> vt={1,0,2};

    cout<<candy(vt);

    return 0;
}