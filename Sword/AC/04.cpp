/*
空格换成%20
*/

#include <iostream>

using namespace std;

void replaceSpace(char *str,int length) {
    //统计空格的个数
    int m=0;
    for(int i=0; i<length; i++){
        if(str[i]==' ')
            m++;
    }
    int len = length-1;
    int n = length + 2*m -1;
    for(;n>0;n--,len--){
        if(str[len]!=' ')
        {
            str[n]=str[len];
        }
        else{
            str[n--]='0';
            str[n--]='2';
            str[n]='%';
        }
    }
}

int main(int argc, char const *argv[])
{   
    char str[20] = "HH BB KK";
	
    replaceSpace(str,8);
    puts(str);

	return 0;
}