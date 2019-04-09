#include <iostream>

struct QuerySubmat
{
    int a;
    int b;
    int c;
    int d;
};

void sumSubmatrix(int** mat, int n, int m, QuerySubmat* q, int k)
{
    int** sum = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        sum[i] = new int[m];
    }

    // base cases
    sum[0][0] = mat[0][0];
    for (int i = 1; i < n; ++i)
    {
        sum[i][0] = sum[i-1][0] + mat[i][0];
    }
    for (int i = 1; i < m; ++i)
    {
        sum[0][i] = sum[0][i-1] + mat[0][i];
    }

    // construct sum
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + mat[i][j];
        }
    }

    // answer queries
    for (int i = 0; i < k; ++i)
    {
        int a=q[i].a, b=q[i].b, c=q[i].c, d=q[i].d;

        int res = sum[c][d];
        if (b > 0) res -= sum[c][b-1];
        if (a > 0) res -= sum[a-1][d];
        if (b>0 && a>0) res += sum[a-1][b-1];

        std::cout << "sum from (" << a << ", " << b << ")";
        std::cout << " to (" << c << ", " << d << ") is: ";
        std::cout << res << std::endl;
    }

    for (int i = 0; i < n; ++i)
    {
        delete[] sum[i];
    }
    delete[] sum;
}
