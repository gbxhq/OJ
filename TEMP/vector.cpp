#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <ctime>
#include <map>
#include <set>
#define eps 1e-9
///#define M 1000100
///#define LL __int64
#define LL long long
///#define INF 0x7ffffff
#define INF 0x3f3f3f3f
#define PI 3.1415926535898
#define zero(x) ((fabs(x) < eps) ? 0 : x)
#define mod 1000000007

#define Cin() ios::sync_with_stdio(false)

using namespace std;

void showVt(vector<int> vt){
    int n = vt.size();
    for(int i=0;i<n;i++)
        cout << vt[i] << ' ';
}

void showvtvt(vector<vector <int> > vector){
    for(auto vt:vector){
        showVt(vt);
        printf("\n");
    }
}



bool biSearch(vector<int> vt, int key) {
    int mid;
    int start = 0;
    int end = vt.size() - 1;
    while (start <= end) {
        mid = (start + end)/2;
        if (key < vt[mid]) {
            end = mid - 1;
        } else if (key > vt[mid]) {
            start = mid + 1;
        } else {
            return true;
        }
    }
    return false;
}





void insertTostr(char *str,int length,char key,int x){
    char tmp = str[x];
    char tmp2;
    str[x] = key;
    for(int i=x+1;i<length;i++){
        tmp2 = str[i];
        str[i] = tmp;
        tmp = tmp2;
    }
}

void replaceSpace(char *str,int length) {
    int l = length;
    for(int i=0;i<l;i++){
        if(str[i]==' ')
        {
            insertTostr(str,l,'%',i);i++;l++;
            insertTostr(str,l,'2',i);i++;l++;
            str[i]='0';
        }
    }
}

int main(){
 
    char str[30] = "We are happy.";
    replaceSpace(str,13);
    cout<< str << endl;

     
    return 0;
}