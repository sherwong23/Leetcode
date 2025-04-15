#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int getSum(int n) { //get sum function
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n = n /10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        while (1) {
            int sum = getSum(n);
            if (sum == 1){return true;}
            if (set.find(sum) != set.end()){
                return false;
            }
            else {set.insert(sum);}
            
            n = sum;
        }
    }
};

int main() {
    Solution sol;
    cout << sol.isHappy(19) << endl;
    cout << sol.isHappy(7) << endl;
    cout << sol.isHappy(2) << endl;
}
