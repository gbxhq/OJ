#include <iostream>

using namespace std;

void plus1(int &a){
    a++;
}

int main(int argc, char const *argv[])
{
    int a = 0;
    plus1(a);
    plus1(a);
    plus1(a);
    cout << a <<"\n";
    return 0;
}
