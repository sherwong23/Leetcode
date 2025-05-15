#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;
    private:
    void backtracking(vector<int>& candidate, int target, int sum, int starIndex, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        
        for (int i = starIndex; i < candidate.size(); i++) {
            if (i > 0 && candidate[i] == candidate[i - 1] && used[i - 1] == true) continue;

            sum += candidate[i];
            path.push_back(candidate[i]);
            used[i] = true;
            
            backtracking(candidate, target, sum, i + 1, used);

            used[i] = false;
            path.pop_back();
            sum -= candidate[i];
        }
    }

    public:
    vector<vector<int>> combination(vector<int>& candidate, int target) {
        result.clear();
        path.clear();
        vector<bool> used(candidate.size(), false);
        sort(candidate.begin(), candidate.end());
        backtracking(candidate, target, 0, 0, used);
        return result;
    }
};

int main() {
    vector<int> candidate = {2, 5, 2, 1, 2};
    Solution sol;
    vector<vector<int>> result = sol.combination(candidate, 5);
    for (auto& nums : result) {
        cout << "[ ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
