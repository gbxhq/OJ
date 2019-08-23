#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min.push_back(INT_MAX);
    }
    
    void push(int x) {
        data.push_back(x);
        if(x<getMin()){
            min.push_back(x);
        }
    }
    
    void pop() {
        if(top()==getMin()){
            min.pop_back();
        }
        data.pop_back;
    }
    
    int top() {
        return *(data.end()-1);
    }
    
    int getMin() {
        return *(min.end()-1);
    }
private:
    vector<int> data;
    vector<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
