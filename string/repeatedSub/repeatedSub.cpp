#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // KMPのnext配列を構築
    void getNext (int* next, const string& s){
        next[0] = -1;
        int j = -1;
        for(int i = 1; i < s.size(); i++){
            while(j >= 0 && s[i] != s[j + 1]) {
                j = next[j]; // 前の位置に戻って再チェック
            }
            if(s[i] == s[j + 1]) {
                j++; // 一致したらjを伸ばす
            }
            next[i] = j;
        }
    }

    // 主処理：繰り返し部分文字列かどうか
    bool repeatedSubstringPattern (string s) {
        if (s.size() == 0) return false;
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        int last = next[len - 1];
        // パターンが存在し、文字列長がそのパターンで割り切れるならtrue
        if (last != -1 && len % (len - (last + 1)) == 0) {
            return true;
        }
        return false;
    }
};
int main() {
    Solution solution;

    vector<string> tests = {
        "abab",     // true (abが繰り返し)
        "aba",      // false
        "abcabcabcabc", // true (abcが繰り返し)
        "a",        // false
        "aaaa",     // true (aが4回)
        "abcdabcd", // true (abcdが2回)
        "xyzxyzxy"  // false
    };

    for (int i = 0; i < tests.size(); ++i) {
        cout << "Test " << i + 1 << " (" << tests[i] << "): "
             << (solution.repeatedSubstringPattern(tests[i]) ? "true" : "false") << endl;
    }

    return 0;
}

