#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& nums) {
            int result = 0;
            for (int i = 1; i < nums.size(); i++) {
                result += max(nums[i] - nums[i - 1], 0);
            }
            return result;
        }
};

int main() {
    vector<int> nums = {7,1,5,3,6,4};
    Solution sol;
    int max = sol.maxProfit(nums);
    cout << max << endl;
    return 0;
}

