class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        #fast and slow index
        fast = 0
        slow = 0
        size = len(nums)
        while fast < size:
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow = slow + 1
            fast = fast + 1
        return slow

if __name__ == "__main__":
    nums = [3, 2, 2, 4]
    val = 2
    sol = Solution()
    new_length = sol.removeElement(nums, val)
    print("New length: ", new_length)
