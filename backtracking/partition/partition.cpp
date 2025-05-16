#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;

    void backtracking (const string& s, int startIndex) {
        //但要求在size()迭代时,知道到底了直接加上
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {

            //如果新截取到的str符合回文条件,则加上path
            //startIndex固定,i做迭代找每一个可能的切断
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {
                continue;
            }

            backtracking(s, i + 1);
            
            path.pop_back();
        }
    }
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};

int main() {
    Solution sol;
    string str = "aab";
    vector<vector<string>> result = sol.partition(str);
    for (auto& str1 : result) {
        for (string str2 : str1) {
            cout << str2 << ",";
        }
        cout << "\n";
    }
    return 0;
}

