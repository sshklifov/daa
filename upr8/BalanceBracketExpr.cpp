#include <iostream>

void balanceBracketExpr(const char* s, int n)
{
    int dif = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(') ++dif;
        else --dif;

        if (dif < 0)
        {
            std::cout << "(";
            ++dif;
        }
        std::cout << s[i];
    }

    while (dif>0)
    {
        std::cout << ")";
        --dif;
    }
}
