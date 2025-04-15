class Solution:
    def commonChars(self, words: list[str]) -> list[str]:
        if not words: return []
        result = []
        hash = [0] * 26
        #init the hash uding the first word
        for c in words[0]:
            hash[ord(c) - ord('a')] += 1
        for i in range(1, len(words)):
            hashotherStr = [0] * 26
            for c in words[i]:
                hashotherStr[ord(c) - ord('a')] += 1
            for j in range(26):
                hash[j] = min(hash[j], hashotherStr[j])
        for i in range(26):
            while (hash[i] != 0):
                result.extend(chr(i + ord('a')))
                hash[i] -= 1
        return result

sol = Solution()
print(sol.commonChars(["bella", "label", "roller"]))  # ['e', 'l', 'l']
print(sol.commonChars(["cool", "lock", "cook"]))      # ['c', 'o']
print(sol.commonChars(["a", "b", "c"]))               # []
