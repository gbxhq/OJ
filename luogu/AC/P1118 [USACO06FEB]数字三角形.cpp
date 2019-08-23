#include <iostream>

using namespace std;

int n,target,yhsj[13],check[13],ans[13],flag=0,sum=0;

int main(){

    cin>>n>>target;

    for (int i = 0; i < n; ++i) {
        ans[i]=i+1;
    }

    yhsj[0]=yhsj[n-1]=1;
    for (int i = 1; i*2 < n; ++i) {
        yhsj[i]=yhsj[n-1-i]=yhsj[i-1]*(n-i)/i;
    }//杨辉三角

    for (int i = 0; i < n; ++i) {
        sum+=yhsj[i]*ans[i];
        if(sum>target)
            break;
    }
    if(sum==target)
    {
        for (int i = 0; i < n; ++i) {
            cout<<ans[i]<<' ';
        }
        flag=1;
    }

    if(!flag)
        while (next_permutation(ans,ans+n)&&!flag){
            sum=0;
            for (int i = 0; i < n; ++i) {
                sum+=yhsj[i]*ans[i];
                if(sum>target)
                {
                    //这里剪枝！
                    sort(ans+i,ans+n,greater<int>());
                    break;
                }
            }
            if(sum==target)
            {
                for (int i = 0; i < n; ++i) {
                    cout<<ans[i]<<' ';
                }
                flag=1;
            }
        }

    return 0;
}
//
//下面是dfs方法
//
#include <iostream>

using namespace std;

int n,target,yhsj[13],check[13],ans[13],flag=0,sum=0;

void dfs(int x){
    if(x==0){//选够了
        if(sum==target){
            for (int i = 0; i < n; ++i) {
                cout<<ans[i]<<' ';
            }
            flag=1;
            return;
        }
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if(!check[i]){//这个数没选过
            ans[n-x]=i;
            if(sum+yhsj[n-x]*ans[n-x]<=target)
                sum+=yhsj[n-x]*ans[n-x];
            else{
                continue;
            }
            check[i]=1;
            dfs(x-1);
            check[i]=0;
            sum-=yhsj[n-x]*ans[n-x];
        }
        if(flag)
            break;
    }
}

int main(){

    cin>>n>>target;

    yhsj[0]=yhsj[n-1]=1;
    for (int i = 1; i*2 < n; ++i) {
        yhsj[i]=yhsj[n-1-i]=yhsj[i-1]*(n-i)/i;
    }//杨辉三角

    dfs(n);

    return 0;
}