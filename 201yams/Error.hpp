/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <regex>
#include <string>
#include <iostream>
#include <list>

int check_error(int ac, char **av);
int check_operation(std::string ope);
int check_what_ope(std::string legit);
int check_full_nbr(std::string ope, size_t pos);
int check_nbr(std::string ope, size_t pos);
int check_dice(std::list<int> dice);


#endif /* !ERROR_HPP_ */
