#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
        }

        for (int i = startIndex; i < nums.size(); i++) {
            if (nums[i] == path.:)
