#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m;
    cin>>m;

    for(int x=(int)sqrt(2*m);x>=1;x--){
        if(2*m%x==0){
            int y=2*m/x;
            if((x&1)^(y&1)){
                //一奇一偶
//                if((y-x+1)/2!=((x+y-1)/2))
                cout<<(y-x+1)/2<<' '<<(x+y-1)/2<<'\n';
            }
        }
    }
    return 0;
}

//下面尺取法
//#include <iostream>
//
//using namespace std;
//
//int main(){
//    int m;
//    cin>>m;
//    for (int i = 1,j=2,sum=3; i <=m/2;) {
//        if(sum==m){
//            cout<<i<<' '<<j<<"\n";
//            sum-=i;
//            i++;
//        }
//        if(sum<m){
//            j++;
//            sum+=j;
//        }
//        if(sum>m){
//            sum-=i;
//            i++;
//        }
//    }
//    return 0;
//}