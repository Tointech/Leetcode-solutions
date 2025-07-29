from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []

        def backtrack(current: str, open_count: int, close_count: int):
            print(f"Current: {current}, Open: {open_count}, Close: {close_count}")
            if open_count == n and close_count == n:  # or len(current) == n * 2
                result.append(current)
                return

            if open_count < n:
                backtrack(current + "(", open_count + 1, close_count)

            if close_count < open_count:
                backtrack(current + ")", open_count, close_count + 1)

        backtrack("", 0, 0)
        return result


if __name__ == "__main__":
    sol = Solution()

    n = 3
    result = sol.generateParenthesis(n)
    print(result)
