// 避免n=100 k=50的情况 回溯算法用递归来解决嵌套层数
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        vector<vector<int>> result;
        vector<int> path;
        void backtracking(int n, int k, int startIndex) {
            // 先写一个退出条件，但path满足要求时（size == k）回溯到上一步，继续去迭代
            if (path.size() == k) {
                result.push_back(path);
                return;
            }
            // 修改path的最后一个数字，试图再往下找，之后清空path
            for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
                path.push_back(i);
                backtracking(n, k, i + 1);
                path.pop_back();
            }
        }

    public:
        vector<vector<int>> combine(int n, int k) {
            result.clear();
            path.clear();
            backtracking(n, k, 1);
            return result;
        }
};

int main() {
    Solution sol;
    int n = 4, k = 2;
    vector<vector<int>> combinations = sol.combine(n, k);
    for (const auto& combo : combinations) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}


