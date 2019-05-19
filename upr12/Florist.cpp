/**
 * @file Florist.cpp
 *
 * You would like to plan n flowers. You have three choices ---
 * blue, purple or yellow. You want them to look pretty so
 * define the following rules:
 *   1) adjacent flowers are not the same color.
 *   2) a yellow flower must be surrounded by a purple and blue
 *   one (order does not matter).
 * Given these rules, find out how many orderings there are.
 */

#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int* blue = new int[n];
    int* prpl = new int[n];

    blue[0] = 1;
    blue[1] = 1;
    prpl[0] = 1;
    prpl[1] = 1;

    for (int i = 2; i < n; ++i)
    {
        blue[i] = prpl[i-1] + prpl[i-2];
        prpl[i] = blue[i-1] + blue[i-2];
    }

    std::cout << blue[n-1] + prpl[n-1] << std::endl;
    delete[] blue;
    delete[] prpl;
}
