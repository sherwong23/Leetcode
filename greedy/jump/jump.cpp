#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            if (nums.size() == 1) return 0;
            int curDistance = 0;
            int ans = 0;
            int nextDistance = 0;
            //整体放在一个大循环里,很好的写法
            for (int i = 0; i < nums.size() - 1; i++) {
                nextDistance = max(nextDistance, nums[i] + i);
                if (i == curDistance) {
                    ans++;
                    curDistance = nextDistance;
                    if (nextDistance >= nums.size() - 1) break;
                }
            }
            return ans;
        }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    int result = sol.jump(nums);
    cout << result << endl;
    return 0;
}
                
