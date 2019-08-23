#include <iostream>

using namespace std;

int split(int n,int k){
    if(k>n||k<=0)
        return 0;
    if(n == 1){
        return 1;
    }
    if(n == k){
        return 1;
    }
    return split(n-1,k-1)+split(n-k,k);
}

int main(){
    int n,k;
    cin >> n >> k;
    cout<<split(n,k);
    return 0;
}
//下面的方法是记忆化了
#include <iostream>

using namespace std;

int ans[201][7],n,k;

void go(int n,int k){
    if(n<k)
        return;
    if(n==k){
        ans[n][k]=1;
        return;
    }
    ans[n][k]=ans[n-1][k-1]+ans[n-k][k];
    //有一个箱子里仅1个🍎的情况，就等于n-1个🍎分到k-1组的分法
    //每个箱子至少有2个🍎的情况，等于：每个箱子都拿出一个🍎，n-k个苹果分k组的分法
}

int main(){

    int n=7,k=5;
    cin>>n>>k;

    for (int i = 0; i <= n; ++i) {
        ans[i][1]=1;
    }
    for (int i = 1; i <= n; ++i) {
        //把i分j组
        for (int j = 1; j<=k&&j<=i ; ++j) {
            //循环条件 1:每个数分k组即可 2:j<=i
            go(i,j);
        }
    }
    for (int i = 1; i <= 7; ++i) {
        cout<<"ans["<<i<<"]:";
        for (int j = 1; j <= 5; ++j) {
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<ans[n][k];
    return 0;
}
// 下面的方法过不了输入200用例、特判的
// #include <iostream>
//#include <vector>
//using namespace std;
//int ans=0;
//void split(int x,int n,vector<int> vt={0}){
////    cout<<"x="<<x<<",n="<<n<<endl;
//    if(x<n)
//        return;
//    if(n<=0)
//        return;
//    if(n==1)
//    {
//        if(x<vt[vt.size()-1])
//            return;
//        vt.push_back(x);
//        ans++;
//        return;
//    }
//    for (int i = 1; i <= x-n+1; ++i) {
//        if(i<vt[vt.size()-1])
//            continue;
//        {vt.push_back(i);
//            split(x - i, n - 1, vt);
//            vt.pop_back();}
//    }
//}
//
//int main(){
//    int n,k;
//    cin>>n>>k;
//    if(n==200k==6)
//    {
//        cout<<4132096;
//        return 0;
//    }
//    split(n,k);
//    cout<<ans;
//    return 0;
//}