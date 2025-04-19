#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpace(string& s) {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            //if meet a char goin to copy
            if (s[i] != ' '){
                //the first word dont need a ' '
                if (slow != 0) s[slow++] = ' ';
                //begin to copy, until meet a ' '
                while (s[i] == ' '){
                    s[slow++] = s[i++];
                }
            }
        }
    }

    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i < s.size() + 1; i++){
            if (s[i] == ' ' || i == s.size()) {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    string test1 = "  the sky   is blue ";
    string result1 = sol.reverseWords(test1);
    cout << "Test 1: \"" << result1 << "\"" << endl; // "blue is sky the"

    string test2 = "hello world";
    string result2 = sol.reverseWords(test2);
    cout << "Test 2: \"" << result2 << "\"" << endl; // "world hello"

    string test3 = "niki love to fuck with sher  example";
    string result3 = sol.reverseWords(test3);
    cout << "Test 3: \"" << result3 << "\"" << endl; // "example good a"

    return 0;
}

