// Task: https://en.wikipedia.org/wiki/Subset_sum_problem

#include <iostream>

int main()
{
    // Read input
    int n, sum;
    std::cin >> n >> sum;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // Create dynamic table
    int** dp = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        dp[i] = new int[sum+1];
    }

    // Base cases
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = true;
    }
    for (int k = 1; k < sum; ++k)
    {
        if (arr[0] == k)
            dp[0][k] = true;
        else
            dp[0][k] = false;
    }

    // Step
    for (int i = 1; i < n; ++i)
    {
        for (int k = 1; k <= sum; ++k)
        {
            if (arr[i] <= k)
            {
                dp[i][k] = dp[i-1][k] | dp[i-1][k-arr[i]];
            }
            else
            {
                dp[i][k] = dp[i-1][k];
            }
        }
    }

    // Result
    std::cout << dp[n-1][sum] << std::endl;

    // Clean up
    for (int i = 0; i < n; ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;

    delete[] arr;
}
