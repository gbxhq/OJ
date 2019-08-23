#include <iostream>
#include <cmath>
using namespace std;
int number[1001]={2},p,ans[1001]={1},temp[1001];
//底数，幂，答案，计算底数平方时存结果的临时数temp

void timesOne(){//结果*底数
    memset(temp,0, sizeof(temp));
    for (int i = 0; i < 501; ++i) {
        for (int j = 0; j < 501; ++j) {
            temp[i+j]+=number[i]*ans[j];
        }
    }
    for (int k = 0; k < 501; ++k) {
        temp[k+1]+=temp[k]/10;
        temp[k]%=10;
    }
    memcpy(ans,temp,sizeof(temp));
}

void pow(){//底数平方
    memset(temp,0, sizeof(temp));
    for (int i = 0; i < 501; ++i) {
        for (int j = 0; j < 501; ++j) {
            temp[i+j]+=number[i]*number[j];
        }
    }
    for (int k = 0; k < 501; ++k) {
        temp[k+1]+=temp[k]/10;
        temp[k]%=10;
    }
    memcpy(number,temp,sizeof(temp));
}

int main(){
    cin>>p;
    cout<<(int)(p*log10(2))+1<<endl;
    while (p){
        if(p&1)
            timesOne();
        pow();
        p>>=1;
    }
    ans[0]--;
    for (int i = 499,j=1; i >=0 ; --i,++j) {
        cout<<ans[i];
        if(j==50){
            cout<<'\n';
            j=0;
        }
    }
    return 0;
}