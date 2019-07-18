//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
// 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
// 如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
// 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
// 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
#include "../../Vt.h"

bool hasPath(vector<vector<char > > vt,char* str,int i,int j){
    if(*str=='\0')
        return true;
    if(i<0||j<0||i>=vt.size()||j>=vt[0].size())
        return false;
    if(vt[i][j]!=*str)
        return false;
    if(vt[i][j]==*str){
        vt[i][j]='\0'; //让这一格子失效
        //往4个方向遍历
        return hasPath(vt,str+1,i,j+1)||hasPath(vt,str+1,i,j-1)||hasPath(vt,str+1,i+1,j)||hasPath(vt,str+1,i-1,j);
    }
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    vector<vector<char > > vt;
    vector<vector<int > > xy;
    for(int i=0;i<rows;i++){
        vector<char > tmp;
        for(int j=0;j<cols;j++) {
            if(*str==*matrix){
                vector<int > tmp2;
                tmp2.push_back(i);
                tmp2.push_back(j);
                xy.push_back(tmp2);
            }
            tmp.push_back(*matrix);
            matrix++;
        }
        vt.push_back(tmp);
    }
    //建立好的矩阵：
    showVtvt(vt);
    //可以开头的坐标：
    showVtvt(xy);
    if(xy.size()==0)
        return false;
    bool ans = false;
    for(auto index:xy){
        ans = ans || hasPath(vt,str,index[0],index[1]);
    }
    return ans;
}

int main(){
    char str[] = "ABCESFCSADEE";
    cout << hasPath(str, 3, 4, const_cast<char *>("SEE"));
    return 0;
}