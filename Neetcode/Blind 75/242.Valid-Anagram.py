from collections import Counter


class Solution:
    # Simple
    # Time complexity: O(nlogn), Space complexity: O(n)
    def isAnagram1(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)

    # Character count (hash map) using library
    # Time complexity: O(n), Space complexity: O(1)
    def isAnagram2(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)

    # Character count from scratch
    def isAnagram3(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count = {}

        for char in s:
            count[char] = count.get(char, 0) + 1

        for char in t:
            if char not in count or count[char] == 0:
                return False
            count[char] -= 1

        return True


if __name__ == "__main__":
    sol = Solution()

    s = "anagram"
    t = "nagaram"
    result = sol.isAnagram3(s, t)
    print(result)
