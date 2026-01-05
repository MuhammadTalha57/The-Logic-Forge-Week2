"""
Asymptotic Analysis

Time Complexity = O(N * totalSum)
Space Complexity = O(N)

"""

def count_payment_combinations(coins: list[int], totalSum: int) -> int:
    coins.sort(reverse=True)

    dp = [0] * (totalSum + 1)
    dp[totalSum] = 1

    for i in range(len(coins)):
        for sm in range(totalSum, coins[i] - 1, -1):
            dp[sm - coins[i]] += dp[sm]
    
    return dp[0]


def main():
    coins = [4]
    totalSum = 4
    print(count_payment_combinations(coins, totalSum))


main()

