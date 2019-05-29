/* Given a proper fraction, represent it as a finite sum of unit
 * fractions.
 */

#include <iostream>

void printFraction(int a, int b)
{
    if (b % a == 0)
    {
        std::cout << "1/" << (b/a) << std::endl;
        return;
    }

    // 1/r is the biggest fraction, such that 1/r < a/b.
    // To compute r, take ceil(b/a).
    int r = b / a + 1;
    std::cout << "1/" << r << " + ";

    // Compute a/b - 1/r
    int difNum = a*r - b;
    int difDenom = b*r;
    printFraction(difNum, difDenom);
}

int main()
{
    int p, q;
    std::cin >> p >> q;
    if (p >= q)
    {
        std::cout << "not a proper fraction" << std::endl;
        return 1;
    }

    std::cout << p << "/" << q << " = ";
    printFraction(p, q);
    return 0;
}
