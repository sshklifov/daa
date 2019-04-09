void swap(int& a, int& b)
{
    int swp = a;
    a = b;
    b = swp;
}

int choosePivotIndex(int* arr, int n)
{
    /* Choosing a correct pivot matters.
       Most popular options are:

       - The least element. This is analogous to just running lomuto partition
       - Median of medians. Choose the median from the first, middle and last
       element. This is a simple and effective heuristic.
       - Random element. As the average running time of quickselect is linear,
       choosing a random element is very likely to yield good running time.
       - Median of median approach. This will ensure worst case linear time.
       The algorithm is as follow: divide the input into groups with 5
       elements, where the last group will have n mod 5 elements if 5 does not
       divide n. From there sort each group of 5 elements (e.g. using insertion
       sort) and retrieve the medians of all n/5 groups. Call recursively
       quickselect on the n/5 medians and retrieve their median, the
       'median of medians'. This in practice does not work well.

       Here, we will just return the last element.
    
    */
    return n-1;
}

int partition(int* arr, int n)
{
    int idx = choosePivotIndex(arr, n);
    swap(arr[n-1], arr[idx]);

    int pivot = arr[n-1];
    int pp = 0;

    for (int i = 0; i <= n-2; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[pp]);
            ++pp;
        }
    }

    swap(arr[pp], arr[n-1]);
    return pp;
}


int quickselect(int* arr, int n, int k)
{
    if (n == 0)
    {
        return arr[k];
    }

    int m = partition(arr, n);
    if (k < m)
    {
        return quickselect(arr, m, k);
    }
    else if (k > m)
    {
        return quickselect(arr+m+1, n-m-1, k);
    }
    else
    {
        return arr[m];
    }
}
