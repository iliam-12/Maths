/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** 201yams
*/

#ifndef YAMS_HPP
#define YAMS_HPP

#include <iostream>
#include <iomanip>
#include <list>
#include "Operate.hpp"

class Dice : public Operate {
    public:
        // Ctor & Dtor
        Dice(char **);
        ~Dice();

        //Structure

        // Member Functions
        void print_dice();
        void combinaison();
        //void pair();
        void three_of_a_kind(); // brelan
        void four_of_a_kind(); // carré
        void full_house(); // carré + brelan
        void straight(); // suite
        void yams(); // tous les dès identiques
        // Variables
        int one;
        int two;
        int three;
        int four;
        int five;
        int A;
        int B;
        std::list<int> di_list;
};

// PROTOTYPES
int check_error(int ac, char **av);

#endif