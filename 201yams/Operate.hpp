/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Operate
*/

#ifndef OPERATE_HPP_
#define OPERATE_HPP_

#include <string>
#include <cmath>
#include <limits>
#include <iostream>
#include <iomanip>
#include <list>

enum Ope_e {
    PAIR,
    THREE,
    FOUR,
    FULL,
    STRAIGHT,
    YAMS
};

class Operate {
    public:
        Operate(std::string);
        ~Operate();

        double proba(int, int);
        double proba_full(int, int);
        double proba_straight(std::list<int>, int);
        int recurrence(std::list<int>, int);
        int power(float, unsigned int);
        int factorial(int);
        double binomial(double, double);
        
        int nbr1;
        int nbr2;
        std::string combi;
        Ope_e ope;
    protected:
    private:
};

#endif /* !OPERATE_HPP_ */
