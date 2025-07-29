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
    # backtrack(index=0, current_combination='')
    # letters: abc
    # backtrack(index=1, current_combination='a')
    # letters: def
    # backtrack(index=2, current_combination='ad')
    # backtrack(index=2, current_combination='ae')
    # backtrack(index=2, current_combination='af')
    # backtrack(index=1, current_combination='b')
    # letters: def
    # backtrack(index=2, current_combination='bd')
    # backtrack(index=2, current_combination='be')
    # backtrack(index=2, current_combination='bf')
    # backtrack(index=1, current_combination='c')
    # letters: def
    # backtrack(index=2, current_combination='cd')
    # backtrack(index=2, current_combination='ce')
    # backtrack(index=2, current_combination='cf')

    result = sol.letterCombinations(digits)

    print(result)
