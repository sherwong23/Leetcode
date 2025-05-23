#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int candy (vector<int>& ratings) {
            vector<int> candyVec(ratings.size(), 1);

            for (int i = 1; i < ratings.size(); i++) {
                if (ratings[i] > ratings[i - 1]) {
                    candyVec[i] = candyVec[i - 1] + 1;
                }
            }

            for (int i = ratings.size() - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]) {
                    candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
                }
            }

            int result = 0;
            for (int i = 0; i < ratings.size(); i++) {
                result += candyVec[i];
            }
            return result;
        }
};

int main () {
    vector<int> ratings = {1,2,2};
    Solution sol;
    int result = sol.candy(ratings);
    cout << result << endl;
    return 0;
}
