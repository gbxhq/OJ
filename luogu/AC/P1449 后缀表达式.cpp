#include <iostream>
#include <stack>

using namespace std;

int main(){
    string str;
    cin>>str;
    stack<int > s;
    for (int i=0;i<str.size();i++) {
        char x=str[i];
        if(x=='@')
            break;
        if(x>='0'&&x<='9'){
            int a=x-'0';
            i++;
            while (str[i]!='.'){
                a=a*10+(str[i]-'0');
                i++;
            }
            s.push(a);
        } else{
            int a,b;
            switch (x){
                case '+':
                    a=s.top();
                    s.pop();
                    b=s.top();
                    s.pop();
                    s.push(b+a);
                    break;
                case '-':
                    a=s.top();
                    s.pop();
                    b=s.top();
                    s.pop();
                    s.push(b-a);
                    break;
                case '*':
                    a=s.top();
                    s.pop();
                    b=s.top();
                    s.pop();
                    s.push(b*a);
                    break;
                case '/':
                    a=s.top();
                    s.pop();
                    b=s.top();
                    s.pop();
                    s.push(b/a);
                    break;
            }
        }
    }
    cout<<s.top();
    return 0;
}