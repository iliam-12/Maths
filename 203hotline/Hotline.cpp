/*
** EPITECH PROJECT, 2021
** B-MAT-400-MAR-4-1-203hotline-franck.minassian
** File description:
** Hotline
*/

#include "Hotline.hpp"

Hotline::Hotline()
{
}

Hotline::~Hotline()
{
}

int check_1args(std::string str)
{
    for (unsigned long i = 0; i != str.size(); i++) {
        if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9')) {
            std::cout << "./hotline:    input are only numbers" << std::endl;
            return (84);
        }
    }
    return (0);
}

int check_2args(std::string str, std::string str2)
{
    for (unsigned long i = 0; i != str.size(); i++) {
        if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9')) {
            std::cout << "./hotline:    input are only numbers" << std::endl;
            return (84);
        }
    }
    for (unsigned long i = 0; i != str2.size(); i++) {
        if (str2[i] != '-' && str2[i] != '+' && (str2[i] < '0' || str2[i] > '9')) {
            std::cout << "./hotline:    input are only numbers" << std::endl;
            return (84);
        }
    }
    return (0);
}

int factorial(int nb)
{
    int y = 1;

    for (int i = nb; i > 0; i--)
        y = y * i;
    return (y);
}

double binomial_law(int n, int i, int p)
{
//     double coeff = factorial(n) / (factorial(i) * factorial(n - i)));
//     return (coeff * (pow(p, i) * (pow(1 - p, (n -i)))));
}

void boucle_50(int arg)
{
    int res = 0;
    int d = 100;
    int p = d / (8 * 60 * 60);

    for (int i = 0; i < 51; i++) {
        res = binomial_law(3500, i, p);
        if (i % 5 == 0 && i != 0)
            std::cout << std::endl;
        std::cout << i << " --> " << res << "\t";
    }
    std::cout << std::endl;
}

void print_binomial(int arg)
{
    arg = arg / 28800.0;
    double overload = 0.0;
    std::cout << "Binomial distribution:" << std::endl;
    boucle_50(arg);
    std::cout << "Overload: " << "... %" << std::endl;
    std::cout << "Computation time: " << "... ms" << std::endl;
}

void print_poisson(int arg)
{
    std::cout << "Poisson distribution:" << std::endl;
    boucle_50(arg);
    std::cout << "Overload: " << "... %" << std::endl;
    std::cout << "Computation time: " << "... ms" << std::endl;
}

void print_distribution(int arg)
{
    print_binomial(arg);
    std::cout << std::endl;
    //print_poisson(arg);
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
    // for (double i = 1.0; i <= k2; i++)
    //     b = ((b * (n - i + 1.0)) / i);
    b = factorial(n) / (factorial(k) * factorial(n - k));
    std::cout << k << "-combinations of a set of size " << std::fixed << std::setprecision(0) << n << ":" << std::endl;
    std::cout << b << std::endl;
    return (0);
}

int hotline(int ac, char **av)
{
    if (ac == 2) {
        if (check_1args(av[1]) == 84)
            return (84);
        print_distribution(atoi(av[1]));
    } else {
        if (check_2args(av[1], av[2]) == 84)
            return (84);
        if (print_combinaison(atoi(av[1]), atoi(av[2])) == 84)
            return (84);
    }
    return (0);
}