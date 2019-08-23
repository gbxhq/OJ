#include <iostream>
#include <algorithm>

using namespace std;

int a[7] = {6,9,5,6,8,2,0};

void show(){
    for (int i = 0; i < 7; ++i) {
        cout<s<a[i]<<' ';
    }
    cout<<'\n';
}

void quickSort(int i,int j){
    cout<<__func__<<i<<","<<j<<"\n";
    if(i>=j)
        return;
    show();
    int temp = a[i],ii=i,jj=j;
    while (i<j){
        while (a[j]>=temp && i<j)
            j--;
        a[i] = a[j];
        while (a[i]<=temp && i<j)
            i++;
        a[j] = a[i];
    }
    a[i] = temp;
    cout<<"this time:\n";
    show();
    cout<<"---\n";
    quickSort(ii,i-1);
    quickSort(i+1,jj);
}

int main(){

    quickSort(0,6);

    show();

    return 0;
}