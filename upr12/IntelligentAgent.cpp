/**
 * @file IntelligentAgent.cpp
 *
 * You are given an array. You play a game against an optimal
 * opponent. The game is turn based, and you start first. You
 * can either take the first element from the array or the last.
 * This elements gets added to your final score. The game ends
 * when there are no more elements left. Given that your opponent
 * plays optimally, what is the best score you can achieve?
 */

#include <iostream>
#include <algorithm> // std::max

int main()
{
    int n;
    std::cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    /* To solve the problem, we break down it down into smaller
     * subproblems --- we solve it for subarrays of 'arr'. We
     * store the results in 'dp'. The first dimension is be the
     * length of the subarray, the second dimension is the
     * starting position. If the input array was a single element,
     * then we pick it, so dp[1][i] = arr[i], where 'i' is the
     * index of the element. If the input array has two elements,
     * then we should choose the bigger one, thus dp[2][i] =
     * = max(arr[i], arr[i+1]). The input array would look like
     * [arr[i], arr[i+1]], since it starts from i and has
     * a length of 2.
     *
     * If we are asked for an arbitrary length n, given that we
     * have computed the answer for every length less than n,
     * we derive the answer as follows. We can pick arr[i] or
     * arr[i+n-1].
     *   1) Pick arr[i]. Then the opponent can pick arr[i+1] or
     *   arr[i+n-1].
     *     1.1) Opponent picks arr[i+1]. Then it is our turn
     *     again and the array will start from i+1 and will have
     *     a length of n-2. But we know the answer for
     *     dp[n-2][i+2]! So in this case our score is
     *     `arr[i] + dp[n-2[i+2]`.
     *     1.2) Opponent picks arr[i+n-1]. Similarly, our score
     *     will be `arr[i] + dp[n-2][i+1].
     *   Since our opponent is smart, he will leave us with the
     *   worse score, that min(case 1.1, case 1.2).
     *
     *   2) Pick arr[i+n-1]. Analogous to 1).
     */

    int** dp = new int*[n+1];
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = new int[n-i+1];
    }
    
    for (int i = 0; i <= n-1; ++i)
    {
        dp[1][i] = arr[i];
    }
    for (int i = 0; i <= n-2; ++i)
    {
        dp[2][i] = std::max(arr[i], arr[i+1]);
    }

    for (int len = 3; len <= n; ++len)
    {
        for (int pos = 0; pos <= n-len; ++pos)
        {
            int takeLeft = arr[pos] +
                std::min(dp[len-2][pos+1], dp[len-2][pos+2]);
            int takeRight = arr[pos+len-1] +
                std::min(dp[len-2][pos], dp[len-2][pos+1]);

            dp[len][pos] = std::max(takeLeft, takeRight);
        }
    }

    std::cout << "Optimal score: " << dp[n][0] << std::endl;;

    for (int i = 1; i <= n; ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] arr;
}

// len=1
