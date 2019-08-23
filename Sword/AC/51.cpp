//找数组中重复的数字
// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false
#include <iostream>
using namespace std;
bool duplicate(int numbers[], int length, int* duplication) {
    int abc[length];
    for(int i=0;i<length;i++)
        abc[i]=0;
    for(int i=0;i<length;i++){
        abc[numbers[i]]++;
        cout<<"abc["<<numbers[i]<<"]="<<abc[numbers[i]]<<"\n";
        if(abc[numbers[i]]>1)
        {
            *duplication = numbers[i];
            return true;
        }
    }
    return false;
}
int main(){
    int a[5]={2,4,3,1,4};
    int b=0;
    cout << duplicate(a,5,&b) << ' ' << b;
    return 0;
}