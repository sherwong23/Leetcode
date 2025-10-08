from bisect import bisect_left
import math
class Solution:
    def successfulPairs(self, spells: list[int], potions: list[int], success: int) -> list[int]:
        potions.sort()
        m = len(potions)
        pairs = []

        for s in spells:
            required = math.ceil(success / s)
            idx = bisect_left(potions, required)
            pairs.append(m - idx)
        return pairs

spells = [5, 1, 3]
potions = [1, 2, 3, 4, 5]
success = 7
sol = Solution()
pair = sol.successfulPairs(spells, potions, success)
print(pair)
