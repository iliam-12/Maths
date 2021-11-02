/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** 201yams
*/

#include "Dice.hpp"
#include "Error.hpp"
#include "Operate.hpp"

int main(int ac, char **av)
{
    if (check_error(ac, av) == 84)
        return (84);
    Dice d(av);
    d.combinaison();
    // Operate op((std::string)(av[6]));
    return (0);
}