//求立方
#include <iostream>
#include <vector>

using namespace std;

vector<int> a,b,ans;

void multiply(vector<int> a,vector<int> b){
    int la=a.size(),lb=b.size();
    vector<int> c(la+lb);
    for (int i = 0; i < la; ++i) {
        for (int j = 0; j < lb; ++j) {
            c[i+j]+=a[i]*b[j];
        }
    }
    for (int k = 0; k < la+lb; ++k) {
        c[k+1]+=c[k]/10;
        c[k]%=10;
    }
    ans=c;
}

int main(){
    char input[21];
    cin>>input;
    int l=strlen(input);

    int sign=0;
    if(input[0]=='-')
        sign=1;//负数标志
    int i=sign?1:0;
    if(i)
        cout<<'-';
    for (; i < l; ++i) {
        a.push_back(input[i]-'0');
    }
    reverse(a.begin(),a.end());
//    for (int x :a) {
//        cout<<x;
//    }cout<<"\n";

    multiply(a,a);
    multiply(a,ans);

    int flag=0;
    for (int j = ans.size(); j >= 0 ; --j) {
        if(ans[j]==0)
        {
            if(flag)
                cout<<ans[j];
        } else
        {
            flag=1;
            cout<<ans[j];
        }
    }cout<<'\n';
    return 0;
}