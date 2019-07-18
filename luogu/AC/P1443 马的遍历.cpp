#include <iostream>
#include <queue>
using namespace std;

int n,m,ans[405][405];
int dirction[8][2]={1,2,1,-2,-1,2,-1,-2,
                    2,1,2,-1,-2,1,-2,-1};

struct node{
    int x;
    int y;
    int step;
    node(int a,int b,int c):x(a),y(b),step(c){}
};

int main(){
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i][j]=-1;
        }
    }
    int x,y;
    cin>>x>>y;
    ans[x-1][y-1]=0;
    queue<node> q1;
    q1.push(node(x-1,y-1,0));
    //bfs
    while (!q1.empty()){
        auto temp=q1.front();
        q1.pop();
        int x1=temp.x;
        int y1=temp.y;
        int step=temp.step;
        //8个方向寻找
        int x2,y2;
        for (int i = 0; i < 8; ++i) {
            x2=x1+dirction[i][0];
            y2=y1+dirction[i][1];
            if(x2>=0 && x2<n && y2>=0 && y2<m
               && ans[x2][y2]==-1){
                ans[x2][y2]=step+1;
                q1.push(node(x2,y2,step+1));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%-5d",ans[i][j]);
        }
        cout<<endl;
    }

    return 0;
}