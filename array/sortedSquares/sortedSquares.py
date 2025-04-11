class Solution:
    def sortedSqures(self, nums: list[int]) -> list[int]:
        #double index
        new_list = []
        front = 0
        last = len(nums) - 1
        while front != last:
            front_squre = nums[front]**2
            last_squre = nums[last]**2
            if front_squre < last_squre:
                new_list.insert(0, last_squre)
                last = last - 1
            else: 
                new_list.insert(0, front_squre)
                front = front + 1

        new_list.insert(0, nums[front]**2)

        return new_list

if __name__ == "__main__":
    nums = [-4, -2, 0, 1, 3]
    sol = Solution()
    new_list = sol.sortedSqures(nums)
    print(new_list)
