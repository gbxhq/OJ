//先分析一下。输入坐标其实是球的右下角。
// 所以在判断下、右墙面时，直接判断。判断上、左墙面时，要隔两个身位。
//初步思路就是这样。
#include <iostream>
#include <queue>

int n,m;
int M[51][51],check[51][51][4];//地图、来访标记
int direction[4][2]={-1,0,0,1,1,0,0,-1};//上右下左

using namespace std;

struct node{
    int x;
    int y;
    int d;//方向 上右下左 0123
    int t;
    node(int a=0,int b=0,int d=0,int t=0):x(a),y(b),d(d),t(t){}
};

node start,target;

bool judge(int x,int y){
    //[x,y]是机器人右下角的坐标 因此要判断四个点是不是都没有障碍
    //能进入这个函数的[x,y]保证都是合法坐标，故不用判断边界
    return !(M[x][y]||M[x-1][y]||M[x][y-1]||M[x-1][y-1]);
}

int bfs(node s){
    queue<node> q1;
    q1.push(s);
    check[s.x][s.y][s.d]=1;
    while (!q1.empty()){//注意，我每次执行一次循环。只代表这个点1秒的执行内容
        node temp=q1.front();

        q1.pop();
        int x1=temp.x,y1=temp.y,d1=temp.d,t=temp.t;//取出值方便写代码
//        printf("到达点[%d,%d] 方向%d 时间%d\n",x1,y1,d1,t);
        //如果选择转方向 计算两个新方向(1秒内只能转一次)
        int d2=(d1+1)%4;
        if(!check[x1][y1][d2])
            q1.push(node(x1,y1,d2,t+1));
        d2=(d1-1+4)%4;
        if(!check[x1][y1][d2])
            q1.push(node(x1,y1,d2,t+1));
        //d1方向往前走 计算走step个步子的坐标
        for (int step = 1; step <= 3 ; ++step) {//step从3开始，走得越快越好啊！
            int x2=x1+direction[d1][0]*step;
            int y2=y1+direction[d1][1]*step;
            if(!judge(x2,y2)){//如果这个方向有障碍就不用看走更多步数的情况了
//                cout<<"撞了\n";
                break;
            }
            if(x2>0 && x2<n && y2>0 && y2<m
               && !check[x2][y2][d1])//坐标合法 && 没以d1方向来过
                //特别注意判断坐标合法时 xy不能为0 因为坐标是机器人的右下角 不能走到边界上
            {
                if (x2 == target.x && y2 == target.y) {
                    return t + 1;
                }
                q1.push(node(x2, y2, d1, t + 1));
            }
        }
    }
    return -1;
}

int main(){

    cin>>n>>m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>M[i][j];
        }
    }
    cin>>start.x>>start.y>>target.x>>target.y;

    char direction;cin>>direction;
    switch (direction){
        case 'N':
            start.d=0;
            break;
        case 'E':
            start.d=1;
            break;
        case 'S':
            start.d=2;
            break;
        case 'W':
            start.d=3;
            break;
    }

    cout<<bfs(start);

    return 0;
}