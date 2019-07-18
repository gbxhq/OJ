#include <iostream>
#include "../Vt.h"
using namespace std;

void quickSort(vector<int> &vt,int i, int j){
    cout<<__func__<<i<<" "<<j<<"\n";
    if(i>=j)
        return;
    int ii = i;//i和j需要存下来递归的时候当参数用
    int jj = j;
    int x = vt[i];
    while (i<j){
        while (x<=vt[j]&&i<j){ //这里开始条件没写 <= 导致
            j--;
        }
        if(i<j){
            vt[i]=vt[j];
            i++;
        }
        while (x>=vt[i]&&i<j){
            i++;
        }
        if(i<j){
            vt[j]=vt[i];
            j--;
        }
    }
    vt[i]=x;
    showVt(vt);
    quickSort(vt,ii,i-1);
    quickSort(vt,i+1,jj);
}

//    优化：不取区间第一个数作为标杆 而是取i\j\mid三个值的中间值
void quickSort2(vector<int> &vt,int i, int j){
    cout<<__func__<<i<<" "<<j<<"\n";
    if(i>=j)
        return;
    int ii = i;//i和j需要存下来递归的时候当参数用
    int jj = j;
    int x=vt[i],y=vt[j],z=vt[(i+j)>>1];
    cout<<"从"<<x<<' '<<y<<' '<<z<<"中";
    int index=i;//标杆下标
    if((y>=x&&y<=z)||(y>=z&&y<=x))
    {
        x=y;
        index=j;
    }
    if((z>=x&&z<=y)||(z>=y&&z<=x))
    {
        x=z;
        index=(i+j)>>1;
    }
    cout<<"选择标杆:"<<x<<"下标"<<index<<endl;
    swap(vt[i],vt[index]);
    while (i<j){
        while (x<=vt[j]&&i<j){ //这里开始条件没写 <= 导致
            j--;
        }
        if(i<j){
            vt[i]=vt[j];
            i++;
        }
        while (x>=vt[i]&&i<j){
            i++;
        }
        if(i<j){
            vt[j]=vt[i];
            j--;
        }
    }
    vt[i]=x;
    showVt(vt);
    quickSort2(vt,ii,i-1);
    quickSort2(vt,i+1,jj);
}

int main(){
    vector<int > data={6,9,9,8,8,7,6};
    quickSort2(data,0,data.size()-1);
    showVt(data);
    return 0;
}
