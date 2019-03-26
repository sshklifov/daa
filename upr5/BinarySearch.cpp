int findRotations(int* arr, int n)
{
    int l = 0, h = n-1;

    while (h-l > 1)
    {
        int m = (l+h) / 2;

        if (arr[l] < arr[h]) return l;
        else if (arr[l] < arr[m]) l = m+1;
        else h = m;
    }

    if (h-l == 1)
    {
        if (arr[l] < arr[h]) return l;
        else return h;
    }
    if (h-l == 0)
    {
        return l;
    }
}

int findOutOfPlace(int* arr, int n)
{
    int l = 0, h = n-1;

    while (h-l > 1)
    {
        int m = (l+h) / 2;

        if (arr[m] == m) l = m+1;
        else h=m;
    }

    for (int i = l; i <= h; ++i)
    {
        if (arr[i] != i) return i;
    }
}
