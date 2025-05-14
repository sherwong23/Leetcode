#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
        };
    public:
        vector<string> result;
        string s;
        void backtracking(const string& digits, int index) {
            //退出条件 当size == digits.size 
            if (index == digits.size()) {
                result.push_back(s);
                return;
            }
            //为每个digit确定对应的letters
            int digit = digits[index] - '0';
            string letters = letterMap[digit];
            //遍历对应的letters,加一个,然后寻找下面的
            for (int i = 0; i < letters.size(); i++) {
                s.push_back(letters[i]);
                backtracking(digits, index + 1);
                s.pop_back();
            }
        }

        vector<string> letterCombination(string digits) {
            s.clear();
            result.clear();
            if (digits.size() == 0) {
                return result;
            }
            backtracking(digits, 0);
            return result;
        }
};

int main() {
    Solution sol;
    string digits = "23";
    vector<string> result = sol.letterCombination(digits);
    for (const auto& str : result) {
        cout << "[";
        cout << str << "]\n";
    }
    return 0;
}


