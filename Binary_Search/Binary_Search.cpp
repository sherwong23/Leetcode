#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target){
		int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) /2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            };
        }
        return -1;
        }
};

int main() {
    Solution solution;
    int n, target;

    cout << "please enter the size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "please enter an array of " << n << " sorted" << endl;
    for (int i = 0; i < n; i++){
	    cin >> nums[i];
	}

    cout << "enter the target: ";	
    cin >> target;

    int result = solution.search(nums, target);

    if (result == -1){
	    cout << "does not have target num" << endl;
	} else{ 
	    cout << result << endl;
	}

    return 0;
}
// This code implements a binary search algorithm to find the index of a target value in a sorted array.
// The search function takes a vector of integers and a target integer as input.
