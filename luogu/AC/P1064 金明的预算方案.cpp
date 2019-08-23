#include <iostream>

using namespace std;

int n,m;
int c[61][4],w[61][4],no[61];//no用于映射编号
int ans[32001];
int check[61][32001];

int main(){
    cin>>n>>m;

    int v,p,q,k=1;//k表示当前有k-1个主件
    for (int i = 1; i <= m; ++i) {
        cin>>v>>p>>q;
        if(q==0){
            c[k][0]=v;
            w[k][0]=p*v;
            no[i]=k;//用于映射商品总编号和编号k
            k++;//每存入一个主件 k++
        } else{
            q=no[q];
            if(c[q][1]==0){//还没有附件
                c[q][1]=c[q][0]+v;//买主件+附件1
                w[q][1]=w[q][0]+p*v;
            } else{//第二个附件加入
                c[q][2]=c[q][0]+v;//买主件+附件2
                c[q][3]=c[q][1]+v;//买主件+2个附件
                w[q][2]=w[q][0]+p*v;
                w[q][3]=w[q][1]+p*v;
            }//存入附件 k不变
        }
    }//输入完成一共k-1组（k-1个主件）

    //分组背包
    for (int i = 1; i < k ; ++i) {
        for (int j = n; j >= c[i][0] ; j-=10) {
            for (int l = 0; l<4 && c[i][l] ; ++l) {
                if(j>=c[i][l])
                    if(ans[j]<ans[j-c[i][l]]+w[i][l]){
                        ans[j]=ans[j-c[i][l]]+w[i][l];
//                        cout<<"买"<<i<<'-'<<l<<'\n';
                    }
            }
        }
    }
    cout<<ans[n];
    return 0;
}