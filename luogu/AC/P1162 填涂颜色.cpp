#include <iostream>

using namespace std;
int a[32][32];
int dir[4][2]={0,1,1,0,0,-1,-1,0};

struct xy{
    int x;
    int y;
    xy(int a=0,int b=0):x(a),y(b){}
}q[2000];

void tu(xy zuobiao){
    a[zuobiao.x][zuobiao.y]=2;
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>a[i][j];
        }
    }
    int begin=0,end=2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(a[i][j]==1)
            {
                q[++begin]=xy(i+1,j+1);
//                cout<<"Start\n";
                break;
            }
        }
        if(begin)
            break;
    }
    while (begin<end){
//        cout<<"New:begin="<<begin<<",end="<<end<<endl;
        xy temp=q[begin];
        int save=end,i=temp.x,j=temp.y;
        a[i][j]=2;
//        cout<<i<<","<<j<<"修改完毕\n";
        begin++;
//        cout<<"begin="<<begin<<endl;
        for (int k = 0; k < 4; ++k) {
            if(a[i+dir[k][0]][j+dir[k][1]]==0)
            {
                a[i+dir[k][0]][j+dir[k][1]]=2;
                q[save++]=xy(i+dir[k][0],j+dir[k][1]);
//                cout<<"存入"<<i+dir[k][0]<<','<<j+dir[k][1]<<'\n';
                end++;
//                cout<<"end="<<end<<endl;
            }
        }
//        cout<<"computing\n";
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
//#include <iostream>
//#include <queue>
//
//using namespace std;
//int a[32][32];
//
//struct xy{
//    int x;
//    int y;
//    xy(int a=0,int b=0):x(a),y(b){}
//};
//
//void tu(xy zuobiao){
//    a[zuobiao.x][zuobiao.y]=2;
//}
//
//int main(){
//    int n;
//    cin>>n;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cin>>a[i][j];
//        }
//    }
//    queue<xy > q1;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if(a[i][j]==1)
//            {
//                q1.push(xy(i+1,j+1));
//                break;
//            }
//        }
//        if(!q1.empty())
//            break;
//    }
//    while (!q1.empty()){
//        xy temp=q1.front();
//        int i=temp.x,j=temp.y;
//        a[i][j]=2;
//        q1.pop();
//        if(a[i+1][j]==0)
//        {
//            a[i+1][j]=2;
//            q1.push(xy(i+1,j));
//        }
//        if(a[i][j+1]==0)
//        {
//            a[i][j+1]=2;
//            q1.push(xy(i,j+1));
//        }
//        if(a[i-1][j]==0)
//        {
//            a[i-1][j]=2;
//            q1.push(xy(i-1,j));
//        }
//        if(a[i][j-1]==0)
//        {
//            a[i][j-1]=2;
//            q1.push(xy(i,j-1));
//        }
//
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout<<a[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
//    return 0;
//}