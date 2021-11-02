/*
** EPITECH PROJECT, 2021
** B-MAT-400-MAR-4-1-202unsold-franck.minassian
** File description:
** unsold
*/

#ifndef UNSOLD_HPP_
#define UNSOLD_HPP_

#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <math.h>

// Main.cpp
int main(int ac, char **av);
void print_help(void);
void print_tab(float **tab);
void print_z(float *str);
void print_expt_var(float *exp, float *var);

// Error.cpp
int check_input(std::string sa, std::string sb, int *a, int *b);

// Unsold.cpp
void  unsold(int a, int b);
float **fill_prob(int a, int b);
float calc(float a, float b, float x, float y);
float *fill_expected_value(float **tab, float *Z);
float *fill_variance(float **tab, float *Z, float *expt_val);

#endif /* !UNSOLD_HPP_ */
