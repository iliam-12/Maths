/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Operate
*/

#include "Operate.hpp"

Operate::Operate(std::string str)
{
    combi = str.substr(0, str.find("_"));

    str = str.substr(str.find("_") + 1, str.size());
    //std::cout << combi << std::endl;
    combi == "pair" ? ope = PAIR : 0;
    combi == "three" ? ope = THREE: 0;
    combi == "four" ? ope = FOUR: 0;
    combi == "full" ? ope = FULL : 0;
    combi == "straight" ? ope = STRAIGHT: 0;
    combi == "yams" ? ope = YAMS: 0;
    if (str.find("_") == (size_t)(-1)) {
        nbr1 = std::stoi(str.substr(0, str.size()));
        nbr2 = -1;
    } else {
        nbr1 = std::stoi(str.substr(0, str.find("_")));
        str = str.substr(str.find("_") + 1, str.size());
        nbr2 = std::stoi(str);
    }
}

Operate::~Operate()
{
}

int Operate::factorial(int nb)
{
    int y = 1;

    for (int i = nb; i > 0; i--) {
        y = y * i;
    }
    return (y);
}

double Operate::binomial(double a, double b)
{
    return (pow((1.0 / 6), b) * pow((1 - (1.0 / 6.0)), a - b) * (factorial(a) / (factorial(b) * factorial(a - b))));
}

double Operate::proba(int rec, int fct)
{
    double proba = 0;

    if (rec >= fct)
        return (100.00);
    for (int nb_times = 5 - rec, rest = fct - rec; rest <= nb_times; rest++)
        proba += binomial(nb_times, rest);
    return (proba*100);
}

double Operate::proba_full(int rec_triple, int rec_pair)
{
    int p_pair;
    int p_brelan;

    if (rec_pair > 2)
		rec_pair = 2;
	if (rec_triple > 3)
		rec_triple = 3;
    p_pair = factorial(5 - rec_triple - rec_pair) / (factorial(3 - rec_pair) * factorial((5 - rec_pair - rec_triple) - (3 - rec_triple)));
	p_brelan = factorial(2 - rec_pair) / (factorial(2 - rec_pair) * factorial((2 - rec_pair) - (2 - rec_pair)));
    return (((p_pair * p_brelan) / pow(6, 5 - rec_triple - rec_pair))*100);
}

int exist(std::list<int> list, int nb)
{
    for (int x : list) {
        if (nb == x) {
            return (1);
        }
    }
    return (0);
}

double Operate::proba_straight(std::list<int> list, int nb)
{
    int rec = 0;

    if (nb == 6) {
        rec = exist(list, 6) + exist(list, 2)
        + exist(list, 3) + exist(list, 4) + exist(list, 5);
    }
    if (nb == 5) {
        rec = exist(list, 1) + exist(list, 2)
        + exist(list, 3) + exist(list, 4) + exist(list, 5);
    }
    return (factorial(5 - rec) / pow(6, 5 - rec)*100);
}

int Operate::recurrence(std::list<int> di, int nb)
{
    int i = 0;

    for (int x : di) {
        if (nb == x) {
            i++;
        }
    }
    return (i);
}