class Solution:
    def isAnagram(self, s: str, t: str)  -> bool:
        record = [0] * 26
        for i in s:
            #add record using s
            record[ord(i) - ord("a")] += 1
        for i in t:
            #sub record using t
            record[ord(i) - ord("a")] -= 1

        #check is 0
        for i in range(26):
            if (record[i] != 0):
                return False

        return True

sol = Solution()
print(sol.isAnagram("anagram", "naagram"))
print(sol.isAnagram("rat", "eat"))
print(sol.isAnagram("niki", "nikisher"))
print(sol.isAnagram("niki", "kini"))
