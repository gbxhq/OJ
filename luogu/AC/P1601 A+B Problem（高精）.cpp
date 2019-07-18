#include <iostream>

using namespace std;

int a[1000],b[1000],ans[1000];

void sum(int bit){
    //传入a和b的最大位数
    int temp=0,i=0;
    for (; i < bit; ++i) {
        ans[i]=a[i]+b[i]+temp;
        temp=ans[i]/10;
        ans[i]%=10;
    }
    if(temp)
        ans[i]=temp;
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    int la=str1.size(),lb=str2.size();

    for (int i = 0; i < la; ++i) {
        a[i]=str1[la-i-1]-'0';
    }
    for (int i = 0; i < lb ; ++i) {
        b[i]=str2[lb-i-1]-'0';
    }

    int maxLen=la>lb?la:lb;
    sum(maxLen);

    maxLen++;
    while (ans[maxLen]==0&&maxLen>=0)
        maxLen--;
    if(maxLen<0)
        maxLen=0;
    for (int i = maxLen; i >= 0 ; --i) {
        cout<<ans[i];
    }

    return 0;
}