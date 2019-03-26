#include <climits>

int cubic(int* arr, int n)
{
    int res = INT_MIN;
    for (int start = 0; start < n; ++start)
    {
        for (int end = start; end < n; ++end)
        {
            int sum = 0;
            for (int i = start; i <= end; ++i)
            {
                sum += arr[i];
            }

            if (sum > res) res = sum;
        }
    }

    return res;
}

int quadratic(int* arr, int n)
{
    int res = INT_MIN;
    for (int start = 0; start < n; ++start)
    {
        int sum = 0;
        for (int end = start; end < n; ++end)
        {
            sum += arr[end];
            if (sum > res) res = sum;
        }
    }

    return res;
}

int maxCrossingSubarray(int* arr, int n, int leftMid, int rightMid)
{
    int leftSum=0, rightSum=0;

    int sum = 0;
    for (int i = leftMid-1; i >= 0; --i)
    {
        sum += arr[i];
        if (sum > leftSum) leftSum = sum;
    }

    sum = 0;
    for (int i = rightMid+1; i < n; ++i)
    {
        sum += arr[i];
        if (sum > rightSum) rightSum = sum;
    }

    return leftSum+rightSum+arr[leftMid]+arr[rightMid];
}

int nlogn(int* arr, int n)
{
    if (n == 1) return arr[0];

    int mid = n/2;
    int resLeft = nlogn(arr, mid);
    int resRight = nlogn(arr+mid, n-mid);
    int resMid = maxCrossingSubarray(arr, n, mid-1, mid);

    if (resLeft > resRight && resLeft > resMid)
        return resLeft;
    else if (resRight > resLeft && resRight > resMid)
        return resRight;
    else
        return resMid;
}
