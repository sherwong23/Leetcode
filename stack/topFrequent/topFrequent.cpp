#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public: 
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs,const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }
    };

    vector<int> topFrequent(vector<int> nums, int k){
        unordered_map<int, int> map;
        for (int i : nums) {
            map[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = sol.topFrequent(nums, k);
    for (int i :result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

