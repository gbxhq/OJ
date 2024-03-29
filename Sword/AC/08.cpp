/*题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
#include <iostream>
#include "Vt.h"

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {
    int n = rotateArray.size();
    if(rotateArray.size()==0)
        return 0;
    int ans = rotateArray[0];
    if(rotateArray[n-1]>rotateArray[0])
        return ans;
    for(int i=1;i<n;i++){
        if(rotateArray[i]<ans){
            ans = rotateArray[i];
            break;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    
    return 0;
}
