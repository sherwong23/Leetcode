#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int targetSum, int k, int sum, int startIndex) {
        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9; i++) {
            // 剪枝：当前和 + i 超过目标，就直接跳过
            if (sum + i > targetSum) break;

            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(n, k, 0, 1);
        return result;
    }
};

int main() {
    Solution sol;
    int n = 9, k = 3;
    vector<vector<int>> combinations = sol.combinationSum3(k, n);

    for (const auto& combo : combinations) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}

