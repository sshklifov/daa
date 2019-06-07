/* Professor Gekko has decided to participate in a marathon. He
 * starts at 0 km and must reach the finish. Since Gekko is not
 * very athletic, he must take breaks every once in a while. You are
 * given a list of stop locations (how far they are from the start).
 * You must help professor Gekko chose where to take breaks, such
 * that he takes as few breaks as possible. It is guaranteed that the
 * professor can finish the marathon.
 */

#include <iostream>

int main()
{
    int n, k, finish;
    std::cin >> n >> k >> finish;

    int* arr = new int[n+1];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    arr[n] = finish;

    int last = 0;
    int stops = 0;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i+1] - last > k)
        {
            ++stops;
            last = arr[i];
            std::cout << "Stopping at " << arr[i] << "km.\n";
        }
    }

    std::cout << "Number of stops: " << stops << std::endl;

    delete[] arr;
}
