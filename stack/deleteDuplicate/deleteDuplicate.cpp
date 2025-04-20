#include <iostream>
using namespace std;

class Solution {
public:
    string deleteDuplicates(string s) {
        string result;
        for (char c : s) {
            if (result.empty() || c != result.back()) {
                result.push_back(c);
            }
            else {
                result.pop_back();
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.deleteDuplicates("abbac") << endl;
    return 0;
}

