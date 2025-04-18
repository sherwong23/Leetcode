#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

int main() {
    Solution sol;
    vector<char> s = {'a', 'b', 'c'};
    sol.reverseString(s);
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}
