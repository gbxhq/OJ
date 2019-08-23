#include <iostream>

using namespace std;

int a[2500],b[2500],ans[2500];

int main(){
    int bit;
    cin>>bit;
    string str1,str2;
    cin>>str1>>str2;

    int la=str1.size(),lb=str2.size(),maxLen=la>lb?la:lb;
    for (int i = 0; i < la; ++i) {
        if(str1[i]>='A')
            a[la-i-1]=str1[i]-'A'+10;
        else
            a[la-i-1]=str1[i]-'0';
    }
    for (int i = 0; i < lb; ++i) {
        if(str2[i]>='A')
            b[lb-i-1]=str2[i]-'A'+10;
        else
            b[lb-i-1]=str2[i]-'0';
    }

    int temp=0,i=0;
    for (; i < maxLen; ++i) {
        ans[i]=a[i]+b[i]+temp;
        if(ans[i]>=bit){
            temp=1;
            ans[i]-=bit;
        } else
            temp=0;
    }
    ans[i]=temp;

    i=maxLen+1;
    while (ans[i]==0&&i>0)
        i--;
    for (; i >= 0 ; --i) {
        if(ans[i]>=10)
            cout<<(char)('A'+ans[i]-10);
        else
            cout<<ans[i];
    }

    return 0;
}