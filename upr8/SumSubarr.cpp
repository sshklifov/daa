#include <iostream>

struct QuerySubarr
{
    int from;
    int to;
};

void sumSubarray(int* arr, int n, QuerySubarr* q, int k)
{
    int* sum = new int[n];

    sum[0] = arr[0];
    for (int i = 1; i < n; ++i)
    {
        sum[i] = sum[i-1] + arr[i];
    }

    for (int i = 0; i < k; ++i)
    {
        int from = q[i].from;
        int to = q[i].to;

        int res;
        if (from==0) res = sum[to];
        else res = sum[to] - sum[from-1];

        std::cout << "sum [" << from << ", " << to << "]: ";
        std::cout << res << std::endl;
    }

    delete[] sum;
}
