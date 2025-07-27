from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        phone_map = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(index: int, current_combination: str):
            if index == len(digits):
                combinations.append(current_combination)
                return

            letters = phone_map[digits[index]]
            for letter in letters:
                backtrack(index + 1, current_combination + letter)

        combinations = []
        backtrack(0, "")
        return combinations


if __name__ == "__main__":
    sol = Solution()

    digits = "23"
    # backtrack(index, current_combination)
    # 0
    # 1 a
    # 2 ad
    # 2 ae
    # 2 af
    # 1 b
    # 2 bd
    # 2 be
    # 2 bf
    # 1 c
    # 2 cd
    # 2 ce
    # 2 cf

    result = sol.letterCombinations(digits)

    print(result)
