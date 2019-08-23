//判断字符串是否表示数值（包括整数和小数）。
// 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
// 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
#include <iostream>
using namespace std;

bool isNumeric(char* string)
{
    bool eFlag=1,dotFlag=1;
    char *p = string;
    if(*p=='+'||*p=='-')
    {
        p++;
        if(*p>='0'&&*p<='9'){//则后面必须是数字
            p++;
        } else if(*p=='.'){
            dotFlag=0;
            p++;
        }
        else
            return false;
    }
    while (*p!='\0'){
        if(*p>='0'&&*p<='9'){
            p++;
            continue;
        }
        if(*p=='E'||*p=='e'){
            if(eFlag){//E\e后面的情况
                eFlag=0;
                dotFlag=0;
                p++;
                if(*p=='\0')//不能是空
                    return false;
                if(*p=='+'||*p=='-'){//如果是+、-
                    p++;
                    if(*p>='0'&&*p<='9'){//则后面必须是数字
                        continue;
                    } else
                        return false;
                }
                if(*p>='0'&&*p<='9'){//则后面必须是数字
                    continue;
                } else
                    return false;
            } else
                return false;
        }
        if(*p=='.'){
            if(dotFlag){
                dotFlag=0;
                p++;
                if(*p=='\0')//不能是空
                    return false;
                if(*p>='0'&&*p<='9'){//则后面必须是数字
                    continue;
                } else
                    return false;
            } else
                return false;
        }
        else
            return false;
    }
    return true;
}
int main(){
    cout<<isNumeric("5e2");
    return 0;
}