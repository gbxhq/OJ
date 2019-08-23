//53正则
#include <iostream>
using namespace std;

bool match(char* str, char* pattern)
{
    if(*str=='\0') {
        if (*pattern == '\0')
            return true;
        if (*pattern == '*')
            if(*(pattern-1)==*(str-1)||*(pattern-1)=='.') //上一个数可匹配
                return match(str-1,pattern+1);
        return match(str, pattern + 1);
        if (*(pattern + 1) == '*')
            return match(str, pattern + 2);
        else
            return false;
    }
    if(*str==*pattern||*pattern=='.')
        return match(str+1,pattern+1);
    if(*pattern=='*')
        if(*(pattern-1)==*str||*(pattern-1)=='.') //上一个数可匹配
            return match(str+1,pattern) || match(str,pattern+1) || match(str+1,pattern+1);
    if(*(pattern+1)=='*')
        return match(str,pattern+2);
    return false;
}

int main(){
    char *str;
    str = "aba";
//    str = "ab";
    char *pat;
    pat = ".*ca";
//    pat = "c*ab";
//    cout << str+1 <<' '<< pat+1;
    cout<< match(str,pat);
    return 0;
}