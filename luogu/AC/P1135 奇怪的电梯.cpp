#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n=5,a=1,b=5;
int elevator[201],check[201];

int bfs(){
    if(a<=0||a>n)
        return -1;
    if(a==b)
        return 0;
    queue<vector <int> >queue1;
    queue1.push({a,0});
    check[a]=1;
    while (!queue1.empty()){
        int temp=queue1.front()[0];
        int step=queue1.front()[1];//此时步数
        queue1.pop();
        int up=temp+elevator[temp];
        int down=temp-elevator[temp];
        if(up==b||down==b)
            return step+1;
        if(up<=b&&!check[up])
        {
            queue1.push({up,step+1});
            check[up]=1;
        }
        if(down>=1&&!check[down]){
            queue1.push({down,step+1});
            check[down]=1;
        }
    }
    return -1;
}

int main(){
    cin>>n>>a>>b;
    for (int i = 1; i <= n ; ++i) {
        cin>>elevator[i];
    }
    cout<<bfs();
    return 0;
}