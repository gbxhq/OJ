#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

void quick(int *a,int i,int j){
    if(i>=j)
        return;
    int ii=i,jj=j;
    int m = a[(i+j)/2];
    while (i<j){
        while (a[i]<m){
            i++;
        }
        while (a[j]>m){
            j--;
        }
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if(ii<j) quick(a,ii,j);
    if(jj>i) quick(a,i,jj);
}

int main(){

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    quick(a,0,n-1);

    for(int x:a)cout<<x<<' ';

    return 0;
}

//下面是普通的快排 实测过不了
void quick1(int *a,int i,int j){
    if(i>=j)
        return;
    int ii=i,jj=j;//暂存坐标
    int x = a[i];//以x为标杆
    while (i<j){
        while (x<a[j]&&i<j){
            j--;
        }
        if(i<j){
            a[i]=a[j];
            i++;
        }
        while (x>a[i]&&i<j){
            i++;
        }
        if(i<j){
            a[j]=a[i];
        }
    }
    //上面的while执行完，i一定和j相同了。这个位置也是x的正确位置
    a[i]=x;//x就放好了
    quick(a,ii,i-1);
    quick(a,i+1,jj);
}
