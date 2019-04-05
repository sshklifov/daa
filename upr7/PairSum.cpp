#include <algorithm>

bool binarySearch(int* arr, int n, int elem)
{
    int l=0, h=n-1;
    while (h-l > 1)
    {
        int m = (l+h) / 2;
        if (elem < arr[m]) h = m-1;
        else l = m;
    }

    for (int i = l; i <= h; ++i)
    {
        if (arr[i]==elem) return true;
    }
    return false;
}

bool pairSum(int* arr, int n, int k)
{
    std::sort(arr, arr+n);

    for (int i = 0; i < n-1; ++i)
    {
        int elem = k-arr[i];
        if (binarySearch(arr+i+1, n-i-1, elem)) return true;
    }

    return false;
}

bool pairSumSorted(int* arr, int n, int k)
{
    int l=0, h=n-1;
    while (l < h)
    {
        int sum = arr[l]+arr[h];

        if (sum == k) return true;
        else if (sum < k) l = l+1;
        else h = h-1;
    }

    return false;
}

bool tripletSum(int* arr, int n, int k)
{
    std::sort(arr, arr+n);

    for (int i = 0; i < n-2; ++i)
    {
        int pairSum = k-arr[i];
        if (pairSumSorted(arr+i+1, n-i-1, pairSum)) return true;
    }

    return false;
}
