#include <algorithm> // std::nth_element is used in place of PICK

bool dominatingElement(int* arr, int n)
{
    std::nth_element(arr, arr+n/2, arr+n);
    int elem = arr[n/2];

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i]==elem) ++cnt;
    }

    return cnt > (n/2);
}

int maximumUneven(int* arr, int n)
{
    // g.i: arr contains distinct integers

    std::nth_element(arr, arr+n/2, arr+n);
    int median = arr[n/2];

    int weakTeam=0, strongTeam=0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < median) weakTeam+=arr[i];
        else strongTeam+=arr[i];
    }

    return strongTeam-weakTeam;
}

int partition(int* arr, int n, int pivotIdx)
{
    std::swap(arr[n-1], arr[pivotIdx]);

    int pivot = arr[n-1];
    int pp = 0;

    for (int i = 0; i <= n-2; i++)
    {
        if (arr[i] < pivot)
        {
            std::swap(arr[i], arr[pp]);
            ++pp;
        }
    }

    std::swap(arr[pp], arr[n-1]);
    return pp;
}

int knapsackSlow(int* arr, int n, int limit)
{
    // g.i. arr contains distinct elements

    std::sort(arr, arr+n);

    int sum = 0;
    for (int i=0; i < n; ++i)
    {
        if (sum+arr[i] > limit) return i;
        else sum+=arr[i];
    }

    return n;
}

int knapsackFast(int* arr, int n, int limit)
{
    // g.i. arr contains distinct elements

    if (n < 10)
    {
        return knapsackSlow(arr, n, limit);
    }

    int mid = n/2;
    std::nth_element(arr, arr+mid, arr+n);
    partition(arr, n, mid);

    int sum = 0;
    for (int i = 0; i <= mid; ++i)
    {
        sum += arr[i];
    }

    if (sum > limit) return knapsackFast(arr, mid, limit);
    else if (sum < limit) return mid+1+knapsackFast(arr+mid+1, n-mid-1, limit-sum);
    else return mid+1;
}
