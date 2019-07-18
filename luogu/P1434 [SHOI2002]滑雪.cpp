#include <iostream>
#include <queue>
using namespace std;

int n,m,maxL=1,map[105][105],ans[105][105];
int direction[4][2]={0,1,1,0,0,-1,-1,0};

struct node{
    int x;
    int y;
    int l;
    node(int a,int b,int c=0):x(a),y(b),l(c){}
};

struct cmp{
    bool operator() (node a, node b){
        return a.l>b.l;
    }
};

void bfs(int i,int j){
    if(ans[i][j])//从其他起点来过这
        return;//用这个做起点肯定不是答案
    ans[i][j]=1;
    priority_queue<node,vector<node>,cmp> q1;
    q1.push(node(i,j,1));
    while (!q1.empty()){
        node temp=q1.top();
        q1.pop();
        int x1=temp.x,y1=temp.y,l=temp.l+1;
        for (int i = 0; i < 4; ++i) {
            int x2=x1+direction[i][0];
            int y2=y1+direction[i][1];
            if(x2>=0 && x2<n && y2>=0 && y2<m
               && map[x1][y1]<map[x2][y2]
               && l>ans[x2][y2]){
                q1.push(node(x2,y2,l));
                ans[x2][y2]=l;
                if(l>maxL)
                    maxL=l;
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&map[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bfs(i,j);
        }
    }
    cout<<maxL;

    return 0;
}