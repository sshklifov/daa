/* You are given a set of distinct coin values. There is an
 * infinite amount of coins for each value. As input, you are
 * also given a price which you have to pay. How many ways are
 * there to pay it?
 */

#include <iostream>

int main()
{
    int n, sum;
    std::cin >> n >> sum;

    int* coins = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> coins[i];
    }

    int** dp = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        dp[i] = new int[sum+1];
    }

    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = 1;
    }
    for (int s = 1; s <= sum; ++s)
    {
        dp[0][s] = (s%coins[0] == 0) ? 1 : 0;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int s = 1; s <= sum; ++s)
        {
            dp[i][s] = dp[i-1][s];
            if (coins[i] <= s)
            {
                dp[i][s] += dp[i][s-coins[i]];
            }
        }
    }

    std::cout << dp[n-1][sum] << std::endl;

    delete[] coins;
}
