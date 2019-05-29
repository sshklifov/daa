/* You are given an array of booleans --- 1 is for a
 * policeman, 0 for a thief. A policeman can capture
 * only one thief and it must be within range. You are
 * also given this range k as input. You must find how
 * many thiefs can be captured, given these restrictions.
 */

#include <iostream>
#include <queue>
#include <cmath>

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::queue<int> policeman;
    std::queue<int> thief;
    for (int i = 0; i < n; ++i)
    {
        bool isPoliceman;
        std::cin >> isPoliceman;

        if (isPoliceman)
        {
            policeman.push(i);
        }
        else
        {
            thief.push(i);
        }
    }

    int caught = 0;
    while (!policeman.empty() && !thief.empty())
    {
        if (abs(policeman.front() - thief.front()) <= k)
        {
            ++caught;
            policeman.pop();
            thief.pop();
        }
        else if (thief.front() > policeman.front())
        {
            policeman.pop();
        }
        else // thief.front() < policeman.front()
        {
            thief.pop();
        }
    }

    std::cout << "thiefs caught: " << caught << std::endl;
    return 0;
}
