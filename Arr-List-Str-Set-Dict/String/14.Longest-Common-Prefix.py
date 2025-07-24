from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""

        # Start with the first string as the prefix
        prefix = strs[0]

        # Compare the prefix with each string in the list
        for s in strs[1:]:
            while not s.startswith(prefix):
                # Reduce the prefix by one character from the end
                prefix = prefix[:-1]
                if not prefix:
                    return ""

        return prefix


if __name__ == "__main__":
    sol = Solution()
    strs = ["flower", "flow", "flight"]

    result = sol.longestCommonPrefix(strs)
    print(result)
