#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void showVt(vector<T> vt){
    int n = vt.size();
    for(int i=0;i<n;i++)
        cout << vt[i] << ' ';
    cout<<"\n";
}

template <typename T>
void showVtvt(vector<vector <T> > vector){
    for(auto vt:vector){
        showVt<T>(vt);
    }
}

template <typename T>
void showVtwithIndex(vector<T> vt){
    int n = vt.size();
    for(int i=0;i<n;i++)
        cout <<"["<<i<<"]:" << vt[i]<<' ';
    cout <<"\n";
}
