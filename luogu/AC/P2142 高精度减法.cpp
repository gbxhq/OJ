#include <iostream>
#include <string>

using namespace std;

int a[15000],b[15000],c[15000];

void sub(int *a,int *b,int maxL){
    int temp=0;
    for (int i = 0; i < maxL; ++i) {
        c[i]=a[i]-b[i]-temp;
        if(c[i]>=0)
            temp=0;
        if(c[i]<0)
        {
            c[i]+=10;
            temp=1;
        }
    }
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int la=s1.size(),lb=s2.size();
    int maxLen=la>lb?la:lb;

    for (int i = 0; i < la; ++i) {
        a[la-i-1]=s1[i]-'0';
    }
    for (int i = 0; i < lb; ++i) {
        b[lb-i-1]=s2[i]-'0';
    }

    if(la>lb){
        sub(a,b,maxLen);
    }
    else if(la<lb){
        cout<<'-';
        sub(b,a,maxLen);
    }
    else if(s1>=s2){//注意要>= 不然相等的情况也会输出负号
        sub(a,b,maxLen);
    } else{
        cout<<'-';
        sub(b,a,maxLen);
    }

    while (c[maxLen]==0&&maxLen>=0)
        maxLen--;
    if(maxLen<0) maxLen=0;
    for (int i = maxLen; i >= 0 ; --i) {
        cout<<c[i];
    }

    return 0;
}