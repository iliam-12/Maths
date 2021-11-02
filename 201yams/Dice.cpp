/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Dice
*/

#include "Dice.hpp"

Dice::Dice(char **av) : Operate::Operate((std::string)(av[6]))
{
    this->one = atoi(av[1]);
    this->two = atoi(av[2]);
    this->three = atoi(av[3]);
    this->four = atoi(av[4]); 
    this->five = atoi(av[5]);
    di_list = {one, two, three, four, five};
}

Dice::~Dice()
{
}

void Dice::combinaison()
{
    int fct;

    if (combi == "pair")
        fct = 2;
    if (combi == "three") {
        combi = "three-of-a-kind";
        fct = 3;
    }
    if (combi == "four") {
        combi = "four-of-a-kind";
        fct = 4;
    }
    if (combi == "yams")
        fct = 5;
    if (combi == "full") {
        full_house();
        return;
    }
    if (combi == "straight") {
        straight();
        return;
    }
    std::cout << "Chances to get a " << nbr1 << " " << combi << ": " <<
    std::setprecision(2) << std::fixed << proba(recurrence(di_list, nbr1), fct)
    << "%\n";
}

void Dice::full_house()
{
    std::cout << "Chances to get a " << nbr1 << " full of " << nbr2 <<
    ": " << std::setprecision(2) << std::fixed << proba_full(recurrence(di_list, nbr1),
    recurrence(di_list, nbr2)) << "%\n";
}

void Dice::straight()
{
    std::cout << "Chances to get a " << nbr1 << " straight: "
    << std::setprecision(2) << std::fixed << proba_straight(di_list, nbr1)
    << "%\n";
}

void Dice::print_dice()
{
    std::cout << "Dice[1] = " << this->one << std::endl;
    std::cout << "Dice[2] = " << this->two << std::endl;
    std::cout << "Dice[3] = " << this->three << std::endl;
    std::cout << "Dice[4] = " << this->four << std::endl;
    std::cout << "Dice[5] = " << this->five << std::endl;
}
