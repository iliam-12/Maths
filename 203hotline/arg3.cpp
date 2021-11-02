/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** arg3
*/

#include "arg3.hpp"

double factorial(double nb)
{
    double y = nb;

    for (double i = 1; i < nb; i++)
        y = y * i;
    return (y);
}

int print_combinaison(int n, int k)
{
    double b = 1.0;
    double k2 = 0;

    if (k < 0 || k > n)
        return (0);
    if (k <= (n - k))
        k2 = k;
    else
        k2 = (n - k);
    b = factorial(n);
    b /= factorial(k) * factorial(n - k);
    std::cout << k << "-combinations of a set of size " << std::fixed << std::setprecision(0) << n << ":" << std::endl;
    std::cout << b << std::endl;
    return (0);
}