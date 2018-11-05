#include <iostream>
#include <vector>

using namespace std;

void showVt(vector<int> vt){
    int n = vt.size();
    for(int i=0;i<n;i++)
        cout << vt[i] << ' ';
    cout << "\n";
}

void showVtvt(vector<vector <int> > vector){
    for(auto vt:vector){
        showVt(vt);
        printf("\n");
    }
}