void swap(int& a, int& b)
{
    int swp = a;
    a = b;
    b = swp;
}

int choosePivotIndex(int* arr, int n)
{
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
