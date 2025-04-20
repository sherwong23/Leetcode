#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() {
    
    }

    //push data in the stack-In (back of queue)
    void push(int x) {
        stIn.push(x);
    }

    //pop data in the stack-Out (front of queue)
    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result;
        result = stOut.top();
        stOut.pop();
        return result;
    }

    //get the front element
    int front() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result;
        result = stOut.top();
        return result;
    }

    bool empty() {
        if (stIn.empty() && stOut.empty()){
            return true;
        }
        return false;
    }
};
int main() {
    MyQueue queue;
    queue.push(10);

    queue.push(20);
    queue.push(30);
    cout << queue.pop() << queue.pop() << endl;
    return 0;
}


