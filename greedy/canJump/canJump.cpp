#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            //用int节省空间
            int cover = 0;
            if (nums.size() == 1) return true;
            for (int i = 0; i <= cover; i++) {
                cover = max(i + nums[i], cover);
                if (cover >= nums.size() - 1) return true;
            }
            return false;
        }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    bool result = sol.canJump(nums);
    cout << result << endl;
    return 0;
}
