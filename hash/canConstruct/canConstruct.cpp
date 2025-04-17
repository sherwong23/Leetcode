#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            record[ransomNote[j] - 'a']--;
            if ((record[ransomNote[j] - 'a']) < 0) {
                return false;
            }
        }
        return true;
    cout << "weishiem" << endl;
    }
};

int main() {
    Solution sol;
    cout << sol.canConstruct("a", "ab") << endl;
    cout << sol.canConstruct("ab", "ab")  << endl;
    cout << sol.canConstruct("aab", "ab") << endl;
    cout << sol.canConstruct("cb", "ab") << endl;
    return 0;
}
