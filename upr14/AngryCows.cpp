/* You are given a list of barns and k cows. You must determine if it
 * is possible to place the cows in such a way, that the distance
 * between barns is at least k. This means that a barn can have at
 * most one cow.
 */

#include <iostream>

int main()
{
    int barns, cows, k;
    std::cin >> barns >> cows >> k;

    int* arr = new int[barns];
    for (int i = 0; i < barns; ++i)
    {
        std::cin >> arr[i];
    }

    int last = arr[0];
    int cnt = 1;

    for (int i = 1; i < barns; ++i)
    {
        if (arr[i]-last >= k)
        {
            ++cnt;
            last = arr[i];
        }
    }

    if (cnt >= cows)
    {
        std::cout << "Possible." << std::endl;
    }
    else
    {
        std::cout << "Not possible." << std::endl;
    }

    delete[] arr;
}
