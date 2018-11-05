#include <iostream>
#include <map>

using namespace std;

map <char,int> yupiao;

int howManyYupiao(char s,char e){
    if(s>e)
        return 0;
    int min = 10;
    for(char i=s;i<=e;i++){
        min = yupiao[i] < min? yupiao[i] : min;
    }
    return min;
}

int canIBuy(char s,char e){
    if (howManyYupiao(s,e)>0)
        return 1;
    else
        return 0;
}

void buy(char s,char e){
    for(char i=s;i<=e;i++){
        --yupiao[i];
    }
}

int main()
{
    int n;
    char start,end;
    string input;
    //Initail YuPiao
    for(char i = 'A';i<='J';i++){
        yupiao[i] = 10;
    }

    while (cin >> start >> end)
    {   
        if(start>=end||start<'A'||end>'J')
        {
            cout << "输入错误" << endl;
            continue;
        }
        cout << "余票： " <<howManyYupiao(start,end) <<endl;
        if (canIBuy(start,end)){
            cin >> input;
            if(input == "buy")
            {
                buy(start,end);
                cout << "buy ok" <<endl;
            }else
            {
                cout << "输入错误" << endl;
                continue;
            }
        }else{
            cout << "余票不足 退出" <<endl;
            continue;
        }
    }
}