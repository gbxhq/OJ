#include <iostream>
#include <vector>

using namespace std;

int target;
int cnt=0;
vector<vector <int>> ans;

void showVt(vector<int> vt){
    for(int x:vt){
        cout<<x<<" ";
    }
    cout<<"\n";
    return;
}

void kaoji(int n,vector<int> vt){

    if(n==0)
    {

        int sum=0;
        for(int x:vt){
            sum+=x;
        }
//        cout<<"sum="<<sum<<"\n";
        if(sum==target)
        {
            cnt++;
            ans.push_back(vt);
        }
        return;
    }else
        for(int i=1;i<=3;i++){
            vt.push_back(i);
            kaoji(n-1,vt);
            vt.pop_back();
        }
}

int main(){
    cin >> target;

    if(target<10||target>30)
        cout<<"0\n";
    else if(target==10)
        cout<<"1\n1 1 1 1 1 1 1 1 1 1";
    else if(target==30)
        cout<<"1\n3 3 3 3 3 3 3 3 3 3";
    else{
        vector<int> vt;
        kaoji(10,vt);
        cout<<cnt<<endl;
        for(auto x:ans){
            showVt(x);
        }
    }


    return 0;
}