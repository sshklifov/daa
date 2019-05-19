/**
 * @file MatrixBestCost.cpp
 *
 * You are given a 2D matrix with size nxm. We start from (0, 0)
 * and are allowed to move either right, i.e. (i, j+1), or down,
 * i.e. (i+1, j). By traversing a cell, we add its value to our
 * total profit. What is maximum possible profit? Note that
 * the values of the matrix are strictly positive.
 */

#include <algorithm> // std::max
#include <iostream>

int** memo;
int** mat;
int n, m;

int MatrixBestCost(int i, int j)
{
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    if (i==n-1 && j==m-1)
    {
        memo[i][j] = mat[i][j];
        return memo[i][j];
    }

    int res = -1;
    if (i < n-1)
    {
        res = std::max(res, mat[i][j] + MatrixBestCost(i+1, j));
    }
    if (j < m-1)
    {
        res = std::max(res, mat[i][j] + MatrixBestCost(i, j+1));
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

    std::cout << "Best cost is: " << MatrixBestCost(0, 0) << std::endl;

    for (int i = 0; i < n; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;
}
