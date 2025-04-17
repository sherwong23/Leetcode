#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    //input nums output the index that the numbers sum equal to sum
    vector<int> twoSum(vector<int> nums, int sum) {
        //
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
        //output empty set [] in python
        return {};
    }


    vector<int> twoSum2(vector<int>& nums, int target) {
        //map can save the val and the index
        //dont need save the data before
        std::unordered_map <int,int> map;

        for(int i = 0; i < nums.size(); i++) {

            //use iter to iter->second
            auto iter = map.find(target - nums[i]); 

            //if find the answer iter not the end
            if(iter != map.end()) {
                return {iter->second, i};
            }

            //save the data in map
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1, 2, 5, 3};

    vector<int> result = sol.twoSum2(nums, 6);

    //iter in for
    for (int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


