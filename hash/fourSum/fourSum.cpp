#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
    vector<vector<int>> fourSum(vector<int> nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = nums.size() - 1; j - i > 2; j--) {
                if (j < nums.size() - 1 && nums[j] == nums[j+1]) continue;
                if (nums[i] > 0) return result;
                int left = i + 1;
                int right = j - 1;
                while(left < right) {
                    if (nums[i] + nums[left] + nums[right] + nums[j] < 0) left++;
                    else if (nums[i] + nums[left] + nums[right] + nums[j] > 0) right--;
                    else {
                        result.push_back(vector<int> {nums[i], nums[left], nums[right], nums[j]});
                        while (left < right && nums[left] == nums[left+1]) left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> input = {-1, 0, 1, 2, -1, -4, 0, 4};
    vector<vector<int>> result = sol.fourSum(input);

    for (const auto& nums : result){
        cout << "[ ";
        for (int num : nums){
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

