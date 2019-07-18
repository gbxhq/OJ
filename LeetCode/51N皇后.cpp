//回溯法解N皇后问题
//参考： 数据结构PPT 第六讲50页

#include <iostream>
#include <vector>
#include "../Vt.h"

using namespace std;

bool isOk(vector<string> vt){
    int n = vt.size();
    //横 、 竖 、 斜
    vector<int > heng(n);
    vector<int > shu(n);
    vector<int > zheng(n*2);//正对角线 存j-i的值。如n=4时。最小为（4,1）为-3. 因此再加3变成0
    vector<int > ni(n*2);//逆对角线 存i+j
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vt[i][j]=='Q'){
                heng[i]++;
                shu[j]++;
                zheng[j-i+n-1]++;//让斜着的坐标为负数的变成非负数
                ni[i+j]++;
                if(heng[i]>1||shu[j]>1||zheng[j-i+n-1]>1||ni[i+j]>1){
                    return false;
                }
            }
        }
    }
    return true;
}

void Trial(int i,int n,vector<string> vt,vector<vector <string>> &ans){
//进入本函数时，nxn棋盘的前i-1行已经放置了互不攻击的i-1个棋子。
//现从第i行起为后续棋子选择满足条件的位置
    if(i<0)
    {
        cout<<"Fail.";
        return;
    }
    if(i==n){
        cout<<"Success！"<<endl;
        showVt(vt);
        ans.push_back(vt);
//        showVtvt(ans);
        return;
    } else{
        for (int j = 0; j < n; ++j) {
            vt[i][j]='Q'; //[i,j]位置放置棋子
            if(isOk(vt))
                Trial(i+1,n,vt,ans);
            vt[i][j]='.'; //[i,j]位置取消放置
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector <string>> ans;
    vector<string> qipan;
    string one(n,'.');
    int i=0;
    while (i++<n)
        qipan.push_back(one);
    Trial(0,n,qipan,ans);
    return ans;
}

int main(){
    vector<vector <string>> ans = solveNQueens(4);
    showVtvt(ans);
    return 0;
}