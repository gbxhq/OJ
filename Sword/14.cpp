/* 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */

#include <iostream>
#include <vector>

using namespace std;

void reOrderArray(vector<int> &array) {
    vector <int> oushu;
    int n = array.size();
    int i = 0, j = 0;
    for(;i<n;i++){
        if(array[i]&1==0) //是偶数
            oushu.push_back(array[i]);
        else
            array[j++] = array[i];
    }
    for(i = 0;i<oushu.size();i++){
        array[j++] = oushu[i];
    }
}

int main(int argc, char const *argv[])
{

    cout << 1&1==0 << endl;
    
    return 0;
}
