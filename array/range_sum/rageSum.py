nums = []

n = int(input())
sum_nums = [0] * (n + 1)

for i in range(n):
    nums.append(int(input()))

for j in range(n):
    sum_nums[j + 1] = sum_nums[j] + nums[j]

left = int(input())
right = int(input())

print("result = ", sum_nums[right + 1] - sum_nums[left])
