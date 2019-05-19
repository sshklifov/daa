/**
 * @file MatrixBestCost.cpp
 *
 * You are given a 2D matrix with size nxm. We would like to
 * find the longest possible path, i.e. a path consisting of
 * as many vertices as possible. We can go from one cell 'u' to
 * another 'v' iff they are adjacent and the value at 'u' is
 * strictly less than the value at 'v'.
 */

#include <algorithm> // std::max
#include <iostream>

int** memo;
int** mat;
int n, m;

int MatrixLongestPath(int i, int j)
{
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    int res = 1;
    int d[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    for (int k = 0; k < 4; ++k)
    {
        int di = i + d[k][0];
        int dj = j + d[k][1];
        if (0 <= di && di <= n-1 && 0 <= dj && dj <= m-1 &&
                mat[di][dj] > mat[i][j])
        {
            res = std::max(res, MatrixLongestPath(di, dj) + 1);
        }
    }

    memo[i][j] = res;
    return memo[i][j];
}

int main()
{
    std::cin >> n >> m;
    mat = new int*[n];
    memo = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        mat[i] = new int[m];
        memo[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            memo[i][j] = -1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> mat[i][j];
        }
    }

    int res = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            res = std::max(res, MatrixLongestPath(i, j));
        }
    }
    std::cout << "The longest increasing path is: " << res << std::endl;

    for (int i = 0; i < n; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

