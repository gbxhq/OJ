//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
#include <iostream>
using namespace std;

/*//方法一
class A{
public:
    A(){
        N++;
        SUM+=N;
    }
    static void reset(){
        N=0;SUM=0;
    }
    static int getSum(){
        return SUM;
    }
private:
    static int N;
    static int SUM;
};
int A::N = 0;//non-friend class member 'N' cannot have a qualified name
int A::SUM = 0;
int Sum_Solution(int n) {
    A::reset();
    A *a = new A[n];
    int ans = A::getSum();
    delete[] a;
    return ans;
}*/

//方法2
class A;
A* tmp[2];

class A{
public:
    virtual int sum(int n){
        return 0;
    }
};

class B:public A{
    virtual int sum(int n){
        return tmp[!!n]->sum(n-1)+n;//use of non-static data member 'tmp' of 'Solution' from nested type 'B'
    }
};

int Sum_Solution(int n) {
    A a;
    B b;;
    tmp[0]=&a;
    tmp[1]=&b;
    int ans = tmp[1]->sum(n);
    return ans;
}

int main(){
    cout << Sum_Solution(5);
    return 0;
}