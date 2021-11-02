/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Error
*/

#include "Error.hpp"

//Checker si pour full les 2 sont différent

int check_nbr(std::string ope, size_t pos)
{
    std::string nbr = ope.substr(pos + 1, ope.size());
    int a = 0;

    if (std::regex_match(nbr, std::regex{"[+-]?[0-9]+"}) == false) {
        std::cout << "There is no numbers after your combinaison" << std::endl;
        return (84);
    }
    a = std::stoi(nbr);
    if (a > 0 && a <= 6)
        return (0);
    else
        return (84);
}

int check_full_nbr(std::string ope, size_t pos)
{
    std::string nbr1 = ope.substr(pos + 1, ope.size());
    std::string nbr2;
    int a = 0, b = 0;

    if (nbr1.find("_") == (size_t) (-1))
        return (84);
    nbr2 = nbr1.substr(nbr1.find("_") + 1, nbr1.size());
    nbr1 = nbr1.substr(0, nbr1.find("_"));
    if ((std::regex_match(nbr1, std::regex{"[+-]?[0-9]+"}) == false) || std::regex_match(nbr2, std::regex({"[+-]?[0-9]+"})) == false) {
        std::cout << "There is no numbers after your combinaison" << std::endl;
        return (84);
    }
    a = std::stoi(nbr1);
    b = std::stoi(nbr2);
    if (a > 0 && a <= 6 && b > 0 && b <= 6 && nbr1 != nbr2)
        return (0);
    else
        return (84);
}

int check_what_ope(std::string legit)
{
    int a = 0;

    legit == "pair" ? a = 1 : 0;
    legit == "three" ? a = 2 : 0;
    legit == "four" ? a = 3 : 0;
    legit == "full" ? a = 4 : 0;
    legit == "straight" ? a = 5 : 0;
    legit == "yams" ? a = 6 : 0;
    return (a);
}

int get_last_nbr(std::string ope)
{
    char const *str = ope.c_str();
    int i = 0;

    while (str[i + 1]) {
        i++;
    }
    return ((int)str[i] - 48);
}

int check_operation(std::string ope)
{
    std::string legit;
    size_t pos_underscore = ope.find("_");
    int a = 0;

    if (pos_underscore == (size_t) (-1))
        return (84);
    legit = ope.substr(0, pos_underscore);
    if (strcmp(legit.c_str(), "straight") == 0 &&
    (get_last_nbr(ope) != 5 && get_last_nbr(ope) != 6))
        return (84);
    a = check_what_ope(legit);
    if (a == 0) {
        std::cout << "There is no combinaison" << std::endl;
        return (84);
    }
    if (a == 4) {
        if (check_full_nbr(ope, pos_underscore) == 84)
            return (84);
    } else {
        if (check_nbr(ope, pos_underscore) == 84)
            return (84);
    }
    return (0);
}

int check_dice(std::list<int> dice)
{
    for (int x : dice) {
        if (x < 0 || x > 6) {
            std::cout << "These Dice aren't number" << std::endl;
            return (84);
        }
    }
    return (0);
}

int check_error(int ac, char **av)
{
    std::list<int> dice;
    int a, b, c, d, e;

    if (ac != 7) {
        std::cout << "Need 7 arguments" << std::endl;
        return (84);
    }
    try {
        a = std::stoi(av[1]);
        b = std::stoi(av[2]);
        c = std::stoi(av[3]);
        d = std::stoi(av[4]);
        e = std::stoi(av[5]);
    } catch (std::exception& e){
        std::cout << "Put only 5 dices (0" << std::endl;
        return (84);
    }
    dice = {a, b, c, d, e};
    if (check_operation(av[6]) == 84 || check_dice(dice) == 84)
        return (84);
    return (0);
}