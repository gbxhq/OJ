//给定一个数组A[0,1,...,n-1],
// 请构建一个数组B[0,1,...,n-1],
// 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
// 不能使用除法。
#include "../Vt.h"
#define lson (rt<<1)
#define rson (rt<<1|1)
vector<int> tree(10000,1);

void pushUp(int rt){
    tree[rt] = tree[lson]*tree[rson];
}
int i=0;
void build(int l,int r,int rt,vector<int> vt){
    if(l==r){
        tree[rt] = vt[i++];//注意这里一定要写tree的下标rt。不能写l
        return;
    }
    int m = (l+r)>>1;
    build(l,m,lson,vt);
    build(m+1,r,rson,vt);
    pushUp(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return tree[rt];
    }
    int m = (l+r)>>1;
    int tmp = 1;
    if(L<=m){
        tmp *= query(L,R,l,m,lson);
    }
    if(R>=m+1){
        tmp *= query(L,R,m+1,r,rson);
    }
    return tmp;
}

vector<int> multiply(const vector<int>& A) {
    int n = A.size();
    build(1,n,1,A);
//    cout<<"\n Show Tree\n";
//    for(int j=0;j<15;j++)
//        cout<<tree[j]<<' ';
//    cout<<'\n'<<query(3,5,1,n,1);
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int x=1;
        if(i-1>=1)
            x *= query(1,i-1,1,n,1);
        if(i+1<=n)
            x *= query(i+1,n,1,n,1);
        ans.push_back(x);
    }
    return ans;
}

int main(){
    vector<int> vt{1,2,3,4};
    vector<int> ans = multiply(vt);
    showVt(ans);
    return 0;
}