#include <iostream>

using namespace std;

int n,ans[13],ansCnt=0;

int check1[15],check2[30],check3[30];//用来检测行、两个对角线

void dfs(int i){//进入时，前i行已经排好了
    if(i==n){//输出
        ansCnt++;
        if(ansCnt<=3)
        {
            for (int j = 0; j < n; ++j) {
                cout<<ans[j]<<" ";
            }
            cout<<'\n';
        }
        return;
    } else{
        for (int j = 1; j <= n; ++j) {
            if(!check1[j] && !check2[i+j] && !check3[i-j+n])
            {
                ans[i]=j;//i行，j放棋子。并存入ans中。
                check1[j]=1;
                check2[i+j]=1;
                check3[i-j+n]=1;//做好标记
                dfs(i+1);//往下一行放棋子
                check1[j]=0;
                check2[i+j]=0;
                check3[i-j+n]=0;//请出标记
            }
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
    cout<<ansCnt;
    return 0;
}