#include <iostream>
#include <algorithm>

using namespace std;

int a[9][9],maxScore=0;
int checkI[9][10],checkJ[9][10],checkK[9][10];//标记

struct node{
    int index;
    int value;
    node(int a=0,int b=0):index(a),value(b){}
}order[9];//用于找目前填了最多的一行
bool cmp(node x,node y){ return x.value>y.value;}

void dfs(int i,int sum){

}

int main(){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin>>a[i][j];
        }
    }
    for (int i = 0,k=0; i < 9; ++i) {
        k = i/3;
        for (int j = 0; j < 9; ++j) {
            k += j/3;
            if(a[i][j])
            {
                checkI[i][a[i][j]]=1;
                checkJ[j][a[i][j]]=1;
                checkK[k][a[i][j]]=1;
                order[i].value++;
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        order[i].index=i;
    }
    sort(order,order+9,cmp);

    for (int i = 0; i < 9; ++i) {
        dfs(order[i].index,1);
    }

    return 0;
}