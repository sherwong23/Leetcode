#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> nums, int sum) {
        unordered_set<int> mynums;
        for (int n : nums){
            mynums.insert(n);
        }
        for (int n : nums){
            
            int diff = sum - n;
            if (mynums.find(diff) != mynums.end()){
                return {n, diff};

            }
        }
        return {};
    }


    vector<int> twoSum2(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]); 
            //use iter to iter->second
            if(iter != map.end()) {
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1, 2, 5, 3};

    vector<int> result = sol.twoSum2(nums, 6);
    for (int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


