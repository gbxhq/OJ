#include <iostream>
#include <queue>
using namespace std;

int k,visited[101][101]={1};
int dirction[4][2]={0,1,1,0,0,-1,-1,0};

bool check(int x,int y){
    int sum=0;
    while (x){
        sum += (x % 10);
        x /= 10;
    }
    while (y){
        sum += (y % 10);
        y /= 10;
    }
    return sum<=k;
}

struct node{
    int x;
    int y;
    node(int a,int b):x(a),y(b){}
};

int movingCount(int threshold, int rows, int cols)
{
    int ans = 0;
    k = threshold;
    queue<node> q1;
    q1.push(node(0,0));
    ans++;
    while (!q1.empty()){
        node temp = q1.front();
        q1.pop();
        int x1 = temp.x, y1 = temp.y;
        for (int i = 0; i < 4; ++i) {
            int x2 = x1 + dirction[i][0];
            int y2 = y1 + dirction[i][1];
            if(x2 >= 0 && x2 < rows && y2 >= 0 && y2 < cols
                && check(x2,y2)
                && !visited[x2][y2])
            {
                q1.push(node(x2,y2));
                ans++;
                visited[x2][y2] = 1;
//                cout<<x2<<','<<y2<<",ans="<<ans<<'\n';
            }
        }
    }
    return ans;
}


int main(){

    cout<<movingCount(15,20,20);

    return 0;
}