/*
** EPITECH PROJECT, 2021
** B-MAT-400-MAR-4-1-202unsold-franck.minassian
** File description:
** Main
*/

#include "Unsold.hpp"

void print_help(void)
{
    std::cout << "USAGE" << std::endl;
    std::cout << "    ./202unsold a b" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "    a       constant computed from past results" << std::endl;
    std::cout << "    b       constant computed from past results" << std::endl;     
}

void print_tab(float **tab)
{
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "\tX=10\tX=20\tX=30\tX=40\tX=50\tY law" << std::endl;
    for (int y = 0; y != 6; y++) {
        y == 5 ? std::cout << "X Law\t" : std::cout << "Y=" << (y + 1) * 10 << "\t";
        for (int x = 0; x != 6; x++)
            std::cout << std::fixed << std::setprecision(3) <<  tab[y][x] << "\t";
        std::cout << std::endl;
    }
}


void print_z(float *str)
{
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "z\t20\t30\t40\t50\t60\t70\t80\t90\t100" << std::endl << "p(Z=z)\t";
    for (int i = 0; i != 9; i++) {
        std::cout << str[i] << "\t";
    }
    std::cout << std::endl;
}

void print_expt_var(float *exp, float *var)
{
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "expected value of X:\t" << std::setprecision(1) << std::fixed << exp[0] << std::endl;
    std::cout << "variance of X:\t\t" << std::setprecision(1) << std::fixed << var[0] << std::endl;
    std::cout << "expected value of Y:\t" << std::setprecision(1) << std::fixed << exp[1] << std::endl;
    std::cout << "variance of Y:\t\t" << std::setprecision(1) << std::fixed << var[1] << std::endl;
    std::cout << "expected value of Z:\t" << std::setprecision(1) << std::fixed << exp[2] << std::endl;
    std::cout << "variance of Z:\t\t" << std::setprecision(1) << std::fixed << var[2] << std::endl;
    std::cout << "--------------------------------------------------------------------------------";
}

int main(int ac, char **av)
{
    int a = 0, b = 0;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    if (ac != 3) {
        std::cout << "./202unsold: Bad input" << std::endl;
        return (84);
    }
    if (check_input((std::string)(av[1]), (std::string)(av[2]), &a, &b) == -1 || a < 50 || b < 50) {
        std::cout << "./202unsold: Bad implementation" << std::endl;
        return (84);
    }
    unsold(a, b);
    return (0);
}