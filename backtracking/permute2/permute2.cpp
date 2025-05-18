#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            //同层去重
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == true) {continue;}

            path.push_back(nums[i]);
            used[i] = true;

            backtracking(nums, used);

            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int> nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1 ,1, 2};
    vector<vector<int>> result = sol.permuteUnique(nums);
    cout << "[ ";
    for (auto& list : result) {
        cout << "[ ";
        for (int num : list) {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
    return 0;
}
