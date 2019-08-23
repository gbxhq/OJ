//线段树 求解区间最值问题
#include <iostream>
#include <vector>
#include "../Vt.h"
//rt:root
#define lson rt<<1
#define rson rt<<1|1
#define len (r-l+1)

using namespace std;

vector<int> vt{6,9,5,6,8,2,0};
int i = 0;
vector<int> tree(16);
vector<int> lazy(16);

void pushUp(int rt){
    tree[rt] = tree[lson]+tree[rson];
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

void pushDown(int rt,int l){
    if(lazy[rt]){//这个点有lazyTag才往下下发lazyTag
        cout<<__func__<<" rt:"<<rt<<" len:"<<l<<'\n';
        lazy[lson]+=lazy[rt];
        lazy[rson]+=lazy[rt];

        tree[lson]+=lazy[rt]*(l-l/2);//这里要注意
        tree[rson]+=lazy[rt]*(l/2);
        lazy[rt]=0;
    }
}

void update(int L,int R,int addVal,int l,int r,int rt){
    cout<<__func__<<l<<','<<r<<','<<rt<<'\n';
    //(l,r)就是根节点rt所代表的区间。
    //[L,R]是要更新的区间。
    if(L<=l&&R>=r){//(l,r)在[L,R]里
        tree[rt]+= len*addVal;//那就只更新rt，不用往下更新了。
        lazy[rt]+= addVal; //但必须做好lazy标记用于pushDown。标记的值就是要加的数。
        return;
    }
    //如果区间不能涵盖:
    pushDown(rt,r-l+1);//下放懒标记。防止以前有过改动儿子没加载
    int m = (l+r)>>1;
    if(L<=m)
        update(L,R,addVal,l,m,lson);
    if(R>=m+1)
        update(L,R,addVal,m+1,r,rson);
    pushUp(rt);
}

int query(int L,int R,int l,int r, int rt){//[L,R]是要查询的区间
    cout<<__func__<<" ["<<L<<','<<R<<"] ("<<l<<','<<r<<") "<<rt<<'\n';
    if(L<=l&&R>=r){//如果[L,R]里有(l,r)区间，直接返回对应的根节点
        return tree[rt];
    }
    pushDown(rt,len);
    int m = (l+r)>>1;
    int sum = 0;
    if(L<=m){
        sum += query(L,R,l,m,lson);
    }
    if(R>=m+1){
        sum += query(L,R,m+1,r,rson);
    }
    return sum;
}

int main(){
    build(1,vt.size(),1);
    showVtwithIndex(tree);

    update(3,6,10,1,7,1);//3到6全加10
    showVtwithIndex(tree);

    cout << query(3,5,1,7,1)<<'\n';
    showVtwithIndex(tree);
    return 0;
}