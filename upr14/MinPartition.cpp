/* Task: Two brothers receive a heritage - a list of items. Each
 * item has a value. You must divide the items fairly between the
 * brothers. Fair means that the difference in their share is minimal.
 *
 * The first input line will be n - the number of items. After it will
 * follow n integers - the prices of the items. You must find a
 * fair partition, such that the difference received by each brother
 * is minimal. Output this difference.
 */

#include <iostream>
#include <queue>

int** dp;
void SubsetSum(int* arr, int n, int sum)
{
    // Standard dp solution to subsetsum.
    // Keep the dynamic table!
    dp = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        dp[i] = new int[sum+1];
    }

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
}

int main()
{
    int n;
    std::cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    int halfsum = sum/2;
    SubsetSum(arr, n, halfsum);

    int res = sum;
    for (int k = 1; k <= halfsum; ++k)
    {
        if (dp[n-1][k])
        {
            int fstBrother = k;
            int sndBrother = sum-k;
            if (sndBrother-fstBrother < res)
            {
                res = sndBrother - fstBrother;
            }
        }
    }

    std::cout << res << std::endl;

    for (int i = 0; i < n; ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;

    delete[] arr;
}
