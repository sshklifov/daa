int kadane(int* arr, int n)
{
    int maximum=0, ending=0;

    for (int i = 0; i < n; ++i)
    {
        ending += arr[i];
        if (ending < 0) ending=0;

        if (ending > maximum) maximum=ending;
    }

    return maximum;
}

int kadane2(int** mat, int n, int m)
{
    int maximum = 0;
    int* arr = new int[n];

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            arr[j] = 0;
        }
        for (int j = i; j < m; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                arr[k] = arr[k] + mat[k][j];
            }

            int curr = kadane(arr, n);
            if (curr > maximum) maximum=curr;
        }
    }

    delete[] arr;
    return maximum;
}
