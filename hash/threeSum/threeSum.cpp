#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        //sort
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            //smallest num > 0 result is {}
            if(nums[i] > 0){
                return result;
            }
            //消除a的重复
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //消除b和c的重复
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
    
                right--;
                left++;
                }
             }
        }
    return result;
    }
};

int main() {
    Solution sol;
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(input);

    cout << "三数之和的结果：" << endl;
    for (const auto& triplet : result) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
