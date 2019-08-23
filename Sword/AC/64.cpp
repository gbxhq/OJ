//如何得到一个数据流中的中位数？
// 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
// 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
// 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
#include "../../Vt.h"

vector<int> data;

int find(int l,int r,int key){
    if(key>=data[r])
        return r+1;
    if(key<=data[l])
        return l;
    if(l==r)
        return l;
    int m = (l+r)>>1;
    if(key<=data[m])
        return find(l,m,key);
    else
        return find(m+1,r,key);
}

void Insert(int num)
{
    int n = data.size();
    if(n==0){
        data.push_back(num);
        return;
    }
    int x = find(0,n-1,num);
    data.insert(data.begin()+x,num);
}

double GetMedian()
{
    int n = data.size();
    if(n%2!=0)
        return data[n/2];
    else
        return (double)(data[n/2]+data[n/2-1])/2;
}

int main(){

    Insert(5);
    Insert(6);
    Insert(2);
    Insert(6);
    Insert(8);
    Insert(3);

    showVt(data);

    cout << GetMedian();

    return 0;

}