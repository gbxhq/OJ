#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

map<string,int> dic={{"zero",0},
                     {"one",1},
                     {"two",2},
                     {"three",3},
                     {"four",4},
                     {"five",5},
                     {"six",6},
                     {"seven",7},
                     {"eight",8},
                     {"nine",9},
                     {"ten",10},
                     {"eleven",11},
                     {"twelve",12},
                     {"thirteen",13},
                     {"fourteen",14},
                     {"fifteen",15},
                     {"sixteen",16},
                     {"seventeen",17},
                     {"eighteen",18},
                     {"nineteen",19},
                     {"twenty",20},
                     {"a",1},
                     {"both",2},
                     {"another",1},
                     {"first",1},
                     {"second",2},
                     {"third",3}};


int main(){
    int a[6],i=0;
    string sentence="Black Obama is two five zero .";
    getline(cin,sentence);
    istringstream is(sentence);
    string word;
    while (is>>word){
        if(dic.find(word)!=dic.end())
        {
            int x=dic[word];
            a[i++]=(x*x%100);
        }
    }
    if(i==0){
        cout<<0;
        return 0;
    }
    //数字都取出来存在了 a[0..i-1]里
    sort(a,a+i);//排序

    //输出
    int flag=0;//是否补0
    for (int j = 0; j < i; ++j) {

        if(a[j]<10) {
            if (flag)
                cout << 0 << a[j];
            else
            {
                if(a[j])//也不能是0
                {
                    cout << a[j];
                    flag=1;
                }
            }
        } else
        {
            cout << a[j];
            flag=1;
        }
    }
    return 0;
}