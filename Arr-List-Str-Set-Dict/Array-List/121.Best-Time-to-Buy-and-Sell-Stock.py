from typing import List

class Solution:
    # Time out solution
    def maxProfitTE(self, prices: List[int]) -> int:
        maxProfit = 0
        transaction = []

        for i in range(len(prices)-1):
            if prices[i] < prices[i+1]:
                transaction.extend([prices[i], prices[i+1]])

        print(transaction)

        if len(transaction) == 0:
            return 0

        for i in range(len(transaction)-1):
            profit = 0
            for j in range(i, len(transaction)):
                if transaction[i] < transaction[j]:
                    print(transaction[i], transaction[j])   
                    profit = transaction[j] - transaction[i]
                    if maxProfit < profit:
                        maxProfit = profit
        
        return maxProfit
    
    # Optimize solution
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit = 0
        minPrice = prices[0]

        for price in prices[1:]:
            if price > minPrice:
                profit = price - minPrice
                maxProfit = max(maxProfit, profit)
            else:
                minPrice = price
        return maxProfit
                    

if __name__ == "__main__":
    sol = Solution()
    prices = [2,1,2,0,1]

    print(sol.maxProfit(prices))