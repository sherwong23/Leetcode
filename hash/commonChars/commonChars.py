class Solution:
    def commonChars(self, words: list[str]) -> list[str]:
        if not words: return []
        result = []
        hash = [0] * 26

        #init the hash using the first word
        for c in words[0]:
            hash[ord(c) - ord('a')] += 1

        #iter rest words reduce the hash[] to the min
        for i in range(1, len(words)):
            hashotherStr = [0] * 26
            for c in words[i]:
                hashotherStr[ord(c) - ord('a')] += 1
            for j in range(26):
                hash[j] = min(hash[j], hashotherStr[j])
        
        #transform to result able to output the same letter
        for i in range(26):
            while (hash[i] != 0):
                result.extend(chr(i + ord('a')))
                hash[i] -= 1
        return result

sol = Solution()
print(sol.commonChars(["bella", "label", "roller"]))  # ['e', 'l', 'l']
print(sol.commonChars(["cool", "lock", "cook"]))      # ['c', 'o']
print(sol.commonChars(["a", "b", "c"]))               # []
