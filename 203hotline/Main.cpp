/*
** EPITECH PROJECT, 2021
** B-MAT-400-MAR-4-1-203hotline-franck.minassian
** File description:
** Main
*/

#include "Main.hpp"

void print_help()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "    ./203hotline [n k | d]" << std::endl;
    std::cout << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "    n       n value for the computation of C(n, k)" << std::endl;
    std::cout << "    k       k value for the computation of C(n, k)" << std::endl;
    std::cout << "    d       average duration of calls (in seconds)" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    if (ac != 2 && ac != 3) {
        print_help();
        return(84);
    }
    if (hotline(ac, av) == 84)
        return (84);
    return (0);
}