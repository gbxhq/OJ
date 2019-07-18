//线段树 求解区间最值问题
#include <iostream>
#include <vector>
#include "../Vt.h"
//rt:root
#define lson rt<<1
#define rson rt<<1|1

using namespace std;

vector<int> vt{6,9,5,6,8,2,0};
int i = 0;
vector<int> tree(16);

void pushUp(int rt){
    tree[rt] = max(tree[lson],tree[rson]);
}

void build(int l,int r,int rt){
    if(l==r)//是叶节点，存数
    {
        tree[rt] = vt[i++];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,lson);
    build(m+1,r,rson);
    pushUp(rt);
}

void update(int index,int newVal,int l,int r,int rt){//单点更新，只需要一个坐标即可
    cout<<__func__<<l<<','<<r<<','<<rt<<'\n';
    if(l==r){
        tree[rt]=newVal;
        return;
    }
    int m = (l+r)>>1;
    if(index<=m)
        update(index,newVal,l,m,lson);
    else
        update(index,newVal,m+1,r,rson);
    pushUp(rt);
}

int query(int L,int R,int l,int r, int rt){//[L,R]是要查询的区间
    cout<<__func__<<" ["<<L<<','<<R<<"] ("<<l<<','<<r<<") "<<rt<<'\n';
    if(L<=l&&R>=r){//如果[L,R]里有(l,r)区间，直接返回对应的根节点
        return tree[rt];
    }
    int m = (l+r)>>1;
    int ans = 0;
    if(L<=m){
        ans = max(ans,query(L,R,l,m,lson));
    }
    if(R>=m+1){
        ans = max(ans,query(L,R,m+1,r,rson));
    }
    return ans;
}

int main(){
    build(1,vt.size(),1);
    showVtwithIndex(tree);

    update(6,99,1,vt.size(),1);//插入
    showVtwithIndex(tree);

    cout << query(2,6,1,7,1);
    return 0;
}