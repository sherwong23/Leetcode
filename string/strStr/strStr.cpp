#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void getNext (int* next, const string& s){
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j + 1]){
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while (j >= 0 && haystack[i] != needle[j+ 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == needle.size() - 1) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};


int main() {
    Solution solution;

    // 测试用例1
    string haystack1 = "hello";
    string needle1 = "ll";
    cout << "Test 1: " << solution.strStr(haystack1, needle1) << endl; // 输出: 2

    // 测试用例2
    string haystack2 = "aaaaa";
    string needle2 = "bba";
    cout << "Test 2: " << solution.strStr(haystack2, needle2) << endl; // 输出: -1

    // 测试用例3
    string haystack3 = "abc";
    string needle3 = "";
    cout << "Test 3: " << solution.strStr(haystack3, needle3) << endl; // 输出: 0

    // 测试用例4
    string haystack4 = "mississippi";
    string needle4 = "issip";
    cout << "Test 4: " << solution.strStr(haystack4, needle4) << endl; // 输出: 4

    // 测试用例5
    string haystack5 = "ababcabcacbab";
    string needle5 = "abcac";
    cout << "Test 5: " << solution.strStr(haystack5, needle5) << endl; // 输出: 5

    return 0;
}
