#include <iostream>
#include <string>
#include <queue>
#include <vector>


using namespace std;

int n,m;
bool MAP[1500][1500];
int ans[1500][1500];//记忆化并初始化为0
int direction[4][2]={0,1,1,0,0,-1,-1,0};

struct node{
    int x;
    int y;
    node(int a, int b):x(a),y(b){}
};

int bfs(int i,int j){
    if(i<0||j<0||i>=n||j>=n)//坐标合法
        return 0;
    if(ans[i][j])//访问过了 直接返回
        return ans[i][j];
    ans[i][j]=1;//没访问过 先赋值1

    vector<node> liantong;//存联通块下标
    queue<node> queue1;//bfs用
    queue1.push(node(i,j));
    int cnt = 1;
    while (!queue1.empty()){//探索联通块存入
        node temp=queue1.front();
        int x1=temp.x;
        int y1=temp.y;
        liantong.push_back(node(x1,y1));//存入联通块
        queue1.pop();
        for (int k = 0; k < 4; ++k) {//四个方向找联通块
            int x2=x1+direction[k][0];
            int y2=y1+direction[k][1];
            if( x2>=0 && x2<n && y2>=0 && y2<n
                &&  (MAP[x1][y1]^MAP[x2][y2])
                && !ans[x2][y2]
                    )//坐标合法 && 走得通 && 没走过
            {
                queue1.push(node(x2,y2));
                ans[x2][y2] = 1;
                cnt++;
            }
        }
    }
    int sameAns=cnt;//liantong.size();//联通块里所有ans一直
    for (auto node:liantong) {
        ans[node.x][node.y]=sameAns;
    }//更新联通块答案
    return ans[i][j];
}

int main(){

    cin>>n>>m;
    string str;
    for (int i=0;i<n;i++){ //迷宫输入
        cin>>str;
        for (int j = 0; j < n; ++j) {
            MAP[i][j]=str[j]-'0';
        }
    }
//    memset(ans,0, sizeof(ans));
    int x,y;
    for (int i = 0; i < m; ++i) {
        cin>>x>>y;
        cout<<bfs(x-1,y-1)<<endl;
    }

    return 0;
}