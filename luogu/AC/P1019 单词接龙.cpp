#include <iostream>
#include <string>

using namespace std;

int n,maxL=0,check[20];//用于做标记
string s[20];

int append(string a,string b){//本题的关键函数。（DFS那里都是模板了）
    //a后面接上b, 接不上返回0.
    //能接上，返回b的开始坐标(即b不与a重叠部分的第一个字母下标）
//    cout<<"Append("<<a<<"+"<<b<<")\n";
    char target=b[0];
    int l1=a.size(),l2=b.size(),i=1;
    while (i<l1&&i<l2){
        //对于a来说。最多截取l1-1长度。
        // 对于b来说，i=l2时就是整个b了
        if(a[l1-i]==target&&a.substr(l1-i,i)==b.substr(0,i))
            return i;//i正是b的新起点下标
        i++;
    }
    return 0;
}

void dfs(string str){
//    cout<<str<<endl;
    if(str.length()>maxL)//进来一个串就更新一下最大长度
            // （这题没法用i控制遍历结束，因题目说了可以不把所有单词用掉。因此只能全部遍历
        maxL=str.length();

    for(int j=0;j<n;j++){
        if(check[j]<2&&append(str,s[j])){//这个串还没用2次&&这俩能拼接上
            int k=append(str,s[j]);
            check[j]++;
            dfs(str+s[j].substr(k));
            check[j]--;
        }
    }
    return;
}

int main(){
//    cout<<append("atoucheatoucheat","tact");
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    char start;
    cin>>start;
//    dfs(0,start);第一次需要特判！因为是个字母
    for (int j = 0; j < n; ++j) {
        if(s[j][0]==start){
            check[j]++;
            dfs(s[j]);
            check[j]--;
        }
    }
    cout<<maxL;
    return 0;
}