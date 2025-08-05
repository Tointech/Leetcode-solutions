from typing import List


class Solution:
    # Brute Force: O(n^2) -> TLE
    def maxProfit1(self, prices: List[int]) -> int:
        n = len(prices)
        bestPrice = 0

        for i in range(0, n - 1):
            for j in range(i, n):
                if prices[j] - prices[i] > bestPrice:
                    bestPrice = prices[j] - prices[i]

        return bestPrice

    def maxProfit2(self, prices: List[int]) -> int:
        buyPrice = prices[0]
        profit = 0

        for price in prices[1:]:
            if buyPrice > price:
                buyPrice = price

            profit = max(profit, price - buyPrice)

        return profit


if __name__ == "__main__":
    sol = Solution()

    prices = [7, 1, 5, 3, 6, 4]
    result = sol.maxProfit2(prices)
    print(result)
