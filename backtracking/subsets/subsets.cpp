#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex) {
        //zhongzhitiaojian
        result.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subset(vector<int> nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main() {
    vector<vector<int>> result;
    Solution sol;
    vector<int> nums = {1, 2, 3};
    result = sol.subset(nums);
    for (auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << endl;
    return 0;
}


