// 最小栈
#include <iostream>
#include <vector>

using namespace std;

vector<int> vt;
stack<int> minStack;
int minVal = INT_MAX;

void push(int value) {
    if(value<=minVal){
        minVal = value;
        minStack.push(minVal);
    }
    vt.push_back(value);
}
void pop() {
    if(*(vt.end()-1)==minVal)
    {   
        minStack.pop();
        minVal = minStack.top();
    }
    vt.pop_back();
}
int top() {
    return *(vt.end()-1);
}
int min() {
    return minVal;
}

int main(int argc, char const *argv[])
{
    return 0;
}
