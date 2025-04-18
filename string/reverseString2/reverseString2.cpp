#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString1(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
    }
    }
    void reverseString2(vector<char>& s, int n) {
        for (int i = 0; i < s.size() - 1; i += 2*n) {
            if ((i + n) <= s.size() - 1){
                reverse(s.begin() + i, s.begin() + i + n );
                continue;
            }
            reverse(s.begin() + i, s.end());
        }
}
};

int main() {
	vector<char> s = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    Solution sol;
	sol.reverseString2(s, 2);
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
 	}
	cout << endl;
	return 0;
}
