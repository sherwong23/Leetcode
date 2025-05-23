#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<string> result;
    vector<string> path;

    private:
    void backtracking(string& s, int startIndex, int pointNum) {
 
        if (pointNum == 3) {
            if (isValid(s, startIndex, s.size() - 1)) {
                //直接把s整个放到result中
                result.push_back(s);
            }
            return;
        }
        
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracking(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            } else break;
        }
    }
    
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }

    public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result;
        backtracking(s, 0, 0);
        return result;
    }
};

int main() {
    string str = "101023";
    Solution sol;
    vector<string> result = sol.restoreIpAddresses(str);
    for (auto& str1 : result) {
        cout << "\"" << str1 << "\"";
        cout << "\n";
    }
    cout << endl;
    return 0;
}


