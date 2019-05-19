/**
 * @file WaysToClimbSteps.cpp
 *
 * You are given n steps and start from step #1. You can climb
 * one step, two steps, or tree steps. You must find the number
 * of unique ways you can get to the last step.
 */

#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int* mat = new int[n];

    mat[0] = 1;
    mat[1] = 1;
    mat[2] = 2;
    for (int i = 3; i < n; ++i)
    {
        mat[i] = mat[i-1] + mat[i-2] + mat[i-3];
    }

    std::cout << mat[n-1] << std::endl;
    delete[] mat;
}
