#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

class Solution {
private: 
    class MyQueue {
        public:
            deque<int> que;
            //pop出当前移出窗口的元素,检查是否最大
            void pop(int value) {
                if (!que.empty() && value == que.front()) {
                    que.pop_front();
                }
            }
            //push后实现了降序,保证了最大的pop后,front依然是最大的,而不是简单把最大的放在front
            void push(int value) {
                while (!que.empty() && value > que.back()) {
                    que.pop_back();
                }
                que.push_back(value);

            }
            int front() {
                return que.front();
            }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        //上个循环走到了第k个元素,现在从k+1开始走
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,3,-1,-3,5,3,6,7};
    vector<int> result = sol.maxSlidingWindow(nums, 3);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

            
