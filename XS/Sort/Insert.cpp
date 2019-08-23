#include <iostream>

using namespace std;

int main(){
        vector<int> ans1 = selectSort(input);
    cout << "简单选择：";  showVt(ans1);
    return 0;
}
//InserSort
vector<int> insertSort(vector<int> vt){
    vt.insert(vt.begin(),999); //加一个哨兵
    int n = vt.size();
    for(int i=2;i<n;i++){
        vt[0]=vt[i];
        int j=i-1;
        for(;vt[j]>vt[0];j--)
            vt[j+1] = vt[j];
        vt[j+1] = vt[0];
    }
    vt.erase(vt.begin()); //去掉哨兵
    return vt;
}
