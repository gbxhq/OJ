# include <iostream>
# include <string>

using namespace std;

bool stringPlus1(string &a){
    bool flag = 0;
    int n = a.size();

    int i = n-1;

    if(a[i] == '9')
        {
            a[i] = '0';
            flag = 1;
        }
    else
        a[i]++;

    i--;

    while(flag==1&&i!=-1){
        if(a[i] == '9')
        {
            a[i] = '0';
            flag = 1;
            i--;
        }
        else
        {
            a[i]++;
            flag = 0;
        }
    }
    if(flag == 1)
        return 1;
    else 
        return 0;
}

// void ans1(){
//     string a (n,'0');
//     cout << a <<endl;
//     while(!plus1(a)){
//         string tmp = a;
//         while(tmp[0]=='0')
//             tmp = tmp.substr(1,tmp.size()-1);
//          cout << tmp << " ";
//     }
// }

void ans2(string &a, int i, int n){

    a[i] = '0'; //从0开始

    while(a[i]!=('9'+1)){
        if(i+1<n)
            ans2(a,i+1,n);
        if(i+1==n)
            cout << a << " ";
        a[i]++;
    }

}

int main(int argc, char const *argv[])
{
    int n = 0;

    string a = "123";

    ans2(a,0,3);

    return 0;
}
