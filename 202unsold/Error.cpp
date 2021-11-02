/*
** EPITECH PROJECT, 2021
** B-MAT-400-MAR-4-1-202unsold-franck.minassian
** File description:
** Error
*/

#include "Unsold.hpp"

int check_input(std::string sa, std::string sb, int *a, int *b)
{
    if (std::regex_match(sa, std::regex("[+-]?[0-9]+")) == false || std::regex_match(sb, std::regex("[+-]?[0-9]+")) == false )
        return (-1);
    else {
        *a = std::stoi(sa);
        *b = std::stoi(sb);
    }
    return (0);
}