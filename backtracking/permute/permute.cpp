#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> result;
    vector<int> path;
   
    void backtracking (vector<int>& nums, vector<bool>& used) {
        //满足条件就加入
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        //不用startIndex
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            
            used[i] = true;
            path.push_back(nums[i]);
            
            backtracking(nums, used);
            
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> result = sol.permute(nums);
    cout << "[ ";
    for (auto& list : result) {
        cout << "[ ";
        for (int num : list) {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << " ]" << endl;
    return 0;
}

