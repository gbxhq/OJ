//顺时针打印矩阵
#include<iostream>
#include"Vt.h"

using namespace std;

void goup(vector<vector<int> > matrix,int &i_min,int &i_max,int &j_min,int &j_max,vector<int> &ans){
    for(int i=i_max;i>=i_min;i--){
        ans.push_back(matrix[i][j_min]);
    }
    j_min++;
}
void godown(vector<vector<int> > matrix,int &i_min,int &i_max,int &j_min,int &j_max,vector<int> &ans){
    for(int i=i_min;i<=i_max;i++){
        ans.push_back(matrix[i][j_max]);
    }
    j_max--;
}
void goleft(vector<vector<int> > matrix,int &i_min,int &i_max,int &j_min,int &j_max,vector<int> &ans){
    for(int j=j_max;j>=j_min;j--){
        ans.push_back(matrix[i_max][j]);
    }
    i_max--;
}
void goright(vector<vector<int> > matrix,int &i_min,int &i_max,int &j_min,int &j_max,vector<int> &ans){
    for(int j=j_min;j<=j_max;j++){
        ans.push_back(matrix[i_min][j]);
    }
    i_min++;
}

vector<int> printMatrix(vector<vector<int> > matrix) {
    int i_min = 0, j_min = 0;
    int i_max = matrix.size()-1, j_max = matrix[0].size()-1;

    vector<int> ans;
    int i = 1;
    while(i_min<=i_max && j_min<=j_max){    //一个结束条件
        switch (i%4)
        {
            case 1: goright(matrix,i_min,i_max,j_min,j_max,ans); i++; break;
            case 2: godown(matrix,i_min,i_max,j_min,j_max,ans); i++; break;
            case 3: goleft(matrix,i_min,i_max,j_min,j_max,ans); i++; break;
            case 0: goup(matrix,i_min,i_max,j_min,j_max,ans); i++; break;
            default:
                break;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int a[16];
    for(int i=0;i<16;i++){
        a[i] = i+1;
    }
    vector<int> vt1(a,a+4);
    vector<int> vt2(a+4,a+8);
    vector<int> vt3(a+8,a+12);
    vector<int> vt4(a+12,a+16);

    vector< vector<int> > vt;
    vt.push_back(vt1);
    vt.push_back(vt2);
    vt.push_back(vt3);
    vt.push_back(vt4);

    // showVtvt(vt);
    vector<int> show = printMatrix(vt);
    showVt(show);

    return 0;
}
