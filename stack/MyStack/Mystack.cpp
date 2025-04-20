#include <iostream>
using namespace std;

class MyStack {
    public:
        queue<int> que;
        MyStack() {
        
        }
        void push(int x) {
            que.push(x);
        }
        int pop() {
            int size = que.size();
            for (int i = 0; i < size - 1; i++) {
                que.push(que.front());
                que.pop();
            }
            int res = que.front();
            que.pop();
            return res;
        }
        int top() {
            int res = this->pop();
            que.push(res);
            return res;
        }
        bool empty() {
            return que.empty();
        }

};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.pop() << stack.pop() << endl;
    return 0;
}
