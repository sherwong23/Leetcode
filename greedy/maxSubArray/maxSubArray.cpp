#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int result = INT32_MIN;
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                count += nums[i];
                //如果count大于0就可以一直保留
                if (count >= result) {
                    result = count;
                }
                if (count < 0) {
                    count = 0;
                }
            }
        return result;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = sol.maxSubArray(nums);
    cout << result << endl;
    return 0;
}
