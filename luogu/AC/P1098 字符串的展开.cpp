#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int type(char c1){
    if(c1>='a'&&c1<='z')
        return 1;
    if(c1>='0'&&c1<='9')
        return 2;
    return 0;
}

string times(string s,int p2){
    string ans;
    for(char x:s){
        int n=p2;
        while (n--){
            ans+=x;
        }
    }
    return ans;
}

int main(){
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;

    string str[50];
    int i=0,n=s.length();//初始化坐标准备存
    for (int k = 1; k < n; ++k) {
        if(s[k]=='-'&&k+1<n){
            if(type(s[k-1])==type(s[k+1])&&type(s[k-1])&&s[k-1]<s[k+1]){//类型相同且不是0
                string temp;//要插入的字符串
                for(char x=s[k-1]+1;x<s[k+1];x++){
                    temp+=x;
                }
//                下面分别处理三个参数 p1
                if(type(s[k-1])==1){//如果是字母

                    switch (p1){
                        case 1:
                            break;
                        case 2:
                            for(int i=0;i<temp.length();i++){
                                temp[i] -= ('a'-'A');
                            }
//                            transform(temp.begin(),temp.end(),temp.begin(),::toupper);
                            break;
                    }
                }
                if(p1==3)
                    for(auto it=temp.begin();it!=temp.end();it++){
                        *it='*';
                    }
                //p2
                temp = times(temp,p2);
                //p3
                if(p3==2)
                    reverse(temp.begin(),temp.end());
                //处理完之后
                s[k]=' ';//把k变成空格。方便一会儿插入！！！我太机智了。
                str[i++]=temp;//要插入的串
            }
        }
    }
//    cout<<"Ready to insert:"<<s<<endl;
    i=0;
    while (s.find(' ')!=s.npos)
    {
//        s.insert(s.cbegin() + s.find_first_of(' '),str[i++]);
        s.replace(s.find(' '),1,str[i++]);
    }
    cout<<s;
    return 0;
}