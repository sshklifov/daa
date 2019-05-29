/* Task: https://en.wikipedia.org/wiki/Knapsack_problem
 */

#include <iostream>

int main()
{
    int n, capacity;
    std::cin >> n >> capacity;

    int* values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> values[i];
    }

    int* weights = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> weights[i];
    }

    // Two dimentional table. The cell (i, w) contains the optimal
    // result for knapsack given the restricted input:
    //   1) use items in the range [0..i].
    //   2) total capacity of backpack is w.
    // We would like to compute the cell (n-1, capacity)
    int** dp = new int*[n];
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = new int[capacity+1];
    }

    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = 0;
    }
    for (int w = 1; w <= capacity; ++w)
    {
        dp[0][w] = (weights[0]<=w) ? values[0] : 0;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int w = 1; w <= capacity; ++w)
        {
            if (weights[i] <= w)
            {
                dp[i][w] = std::max(dp[i-1][w], values[i] + dp[i-1][w-weights[i]]);
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    std::cout << "Optimal value: " << dp[n-1][capacity] << std::endl;

    for (int i = 0; i <= n; ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;

    delete[] weights;
    delete[] values;
}
