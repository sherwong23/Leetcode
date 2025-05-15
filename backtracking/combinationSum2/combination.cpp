#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

private:
    void backtracking(vector<int>& candidates, int target, int sum, int starIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        if (sum > target) {
            return;
        }

        for (int i = starIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            //i not i+1 can be same number
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

int main() {
    vector<int> candidates = {2, 5, 3};
    Solution sol;
    vector<vector<int>> result = sol.combinationSum(candidates, 7);
    for (auto& nums : result) {
        cout << "[ ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << "]" <<endl;
    }
    return 0;
}

