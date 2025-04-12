class Solution {
	public int minSubArrayLen(int s, int[] nums) {
		int left = 0;
		int sum = 0;
		int result = Integer.MAX_VALUE;
		for (int right = 0; right < nums.length ; right++){
			sum += nums[right];
			while (sum >= s){  //not if
				result = Math.min(result, right - left + 1);
				sum -= nums[left++];// sub to sum < s
			}
		}	
		
		return result == Integer.MAX_VALUE ? 0 : result;
		
	}
	
}
