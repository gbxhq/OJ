#include <iostream>
#include <vector>
using namespace std;

void Mi(int x){
    vector<int> vt;
    int i=0;
    while (x){
        if(x&1)
            vt.push_back(i);
        i++;
        x>>=1;
    }
//    for(int i:vt){
//        cout<<i;
//    }
    int n=vt.size();
    for(int i=n-1;i>=0;i--){
        cout<<2;
        if(vt[i]!=1){//如果是2的1次方
            cout<<'(';
            if(vt[i]<2)
                cout<<vt[i];
            else{
                Mi(vt[i]);
            }
            cout<<')';
        }
        if(i!=0)
            cout<<'+';
    }
}

int main(){
//    Mi(1315);
    int n;
    cin>>n;
    Mi(n);
    return 0;
}