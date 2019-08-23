#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int ans[21][21][21];

int w(int a,int b,int c){
    if(a<=0||b<=0||c<=0)
        return 1;
    else if(a>20||b>20||c>20)
        return ans[20][20][20];//Mark 这个值可求得直接输出
    else if(ans[a][b][c])
        return ans[a][b][c];
    else if(a<b&&b<c)
    {
        ans[a][b][c]=pow(2,a);
        return ans[a][b][c];
    }
    else
    {
        ans[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
        return ans[a][b][c];
    }
}

int main(){
    ans[0][0][0]=1;
    ans[20][20][20]=1048576;

    long long a,b,c;
    while (cin >> a >>b >>c)
    {
        if(a==-1&&b==-1&&c==-1)
            break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
        if(a<=0||b<=0||c<=0)
        {
            a=0;b=0;c=0;
        }
        else if(a>20||b>20||c>20)
        {
            a=20;b=20;c=20;
        }
        cout<<w(a,b,c)<<endl;
    }

    return 0;
}