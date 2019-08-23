//考虑的情况太复杂。先放一放吧
//里面用来计算复杂度的思路也是有问题的。不要细看。
#include <iostream>
#include <stack>

using namespace std;

int main(){
    int t,L;//t个程序 每个程序长L行
    string fzd,prog;//复杂度
    int fzd1;//复杂度int类型 0为常数
    int fzd2,error=0;//用于验证
    cin>>t;
    while (t--){
        cin>>L;
        cin>>fzd;
        if(fzd[2]==1){
            fzd1=0;
        } else{
            fzd1=fzd[fzd.length()-2]-'0';//这是个字符串倒数第二位

            if(fzd[fzd.length()-3]!='^'){//可能倒数第三位也是数字
                fzd1+=((fzd[fzd.length()-3]-'0')*10);
            }
        }
        //开始分析程序 先读入
        int cnt=0;//存F/E配对个数 最后cnt不为0或为负则错误
        fzd2=0;
        char abc[27];//用来存字母；
        stack<char> stk;
        while (L--){
            if(error)
                break;
            getline(cin,prog);
            if(prog[0]=='F'){
                cnt++;
                abc[prog[2]-'a']++;
                if(abc[prog[2]-'a']>1)//如果这个字母用过了 ERROR
                    error=1;
            }
            if(prog[0]=='E'){
                cnt--;
                if(cnt<0)
                    error=1;
                fzd2++;
            }
        }
        if(cnt>0)
            error=1;
        if(error){
            cout<<"ERR\n";
            continue;
        }

    }
    return 0;
}