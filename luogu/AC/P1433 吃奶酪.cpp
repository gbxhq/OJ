#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int n=0;
double l=0.00,minDistance=INT_MAX*1.00;

struct node{
    double x;
    double y;
    bool visited;
    node(int a=0,int b=0):x(a),y(b),visited(0){}
}a[16];

double getDistance(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void dfs(double x1, double y1, double x2, double y2,int sum){
    double distance=getDistance(x1,y1,x2,y2);
    l+=distance;
    if(l>=minDistance)
    {
        return;
    }
    if(sum==n){
        if(l<minDistance)
        {
            minDistance=l;
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(!a[i].visited)
        {
            a[i].visited=1;
            dfs(x2,y2,a[i].x,a[i].y,sum+1);
            l-=distance=getDistance(x2,y2,a[i].x,a[i].y);
            a[i].visited=0;
        }
    }

}

int main(){

    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i].x>>a[i].y;
    }

    for (int i = 0; i < n; ++i) {
        l=0.00;
        a[i].visited=1;
        dfs(0,0,a[i].x,a[i].y,1);
        a[i].visited=0;
    }

    printf("%.2f",minDistance);

    return 0;
}