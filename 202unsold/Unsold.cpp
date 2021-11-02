/*
** EPITECH PROJECT, 2021
** B-MAT-400-MAR-4-1-202unsold-franck.minassian
** File description:
** Unsold
*/

#include "Unsold.hpp"

float calc(float a, float b, float x, float y)
{
    return ((a - x) * (b - y)) / (((5 * a) - 150) * ((5 * b) - 150));
}

float **fill_prob(int a, int b)
{
    float **tab = new float*[6];
    float sum = 0, sum1 = 0;
    int Ya = 10, Xa = 10;

    for (int y = 0; y != 5; y++, Ya += 10) {
        tab[y] = new float[6];
        for (int x = 0; x != 5; x++) {
            sum += calc(a, b, Xa, Ya);
            tab[y][x] = calc(a, b, Xa, Ya);
            Xa += 10;
        }
        tab[y][5] = sum;
        sum = 0;
        Xa = 10;
    }
    tab[5] = new float[6];
    for (int x1 = 0; x1 != 6; x1++) {
        for (int y1 = 0; y1 != 5; y1++) {
            sum1 += tab[y1][x1];
        }
        tab[5][x1] = sum1;
        sum1 = 0;
    }
    return (tab);
}

float *fill_z(float **tab)
{
    float *z = new float[9];
    float sum;
    int i = 0;

    for (int x = 0, y = 0; i != 5; i++) {
        x = i;
        for (; x != 0; x--, y++)
            sum += tab[y][x];
        sum += tab[y][x];
        z[i] = sum;
        y = 0;
        sum = 0;
    }
    sum = 0;
    for (int i1 = 1, x = 5, y = i1; i1 != 5; i++, i1++) {
        x = 4;
        y = i1;
        for (; y != 4; y++, x--) {
            sum += tab[y][x];
        }
        sum += tab[y][x];
        z[i] = sum;
        x = 5;
        sum = 0;           
    }
    return (z);
}

float *fill_expected_value(float **tab, float *Z)
{
    float sumX = 0.0;
    float sumY = 0.0;
    float sumZ = 0.0;
    float *sum = new float[3];

    for (int x = 0; x != 5; x++) {
        sumX += (x + 1) * 10 * tab[5][x];
        sumY += (x + 1) * 10 * tab[x][5];
    }
    for (int x = 0; x != 9; x++)
        sumZ += (x + 2) * 10 * Z[x];
    sum[0] = sumX;
    sum[1] = sumY;
    sum[2] = sumZ;
    return (sum);
}

float *fill_variance(float **tab, float *Z, float *expt_val)
{
    float sumX = 0.0;
    float sumY = 0.0;
    float sumZ = 0.0;
    float *sum = new float[3];

    for (int i = 0; i != 5; i++) {
        sumX += pow(((i + 1) * 10 - expt_val[0]), 2) * tab[5][i];
        sumY += pow(((i + 1) * 10 - expt_val[1]), 2) * tab[i][5];
    }
    for (int i = 0; i != 9; i++)
        sumZ += pow(((i + 2) * 10 - expt_val[2]), 2) * Z[i];
    sum[0] = sumX;
    sum[1] = sumY;
    sum[2] = sumZ;
    return (sum);
}

void unsold(int a, int b)
{
    float **prob_tab;
    float *prob_z;
    float *expected_value;
    float *variance;

    prob_tab = fill_prob(a, b);
    print_tab(prob_tab);
    prob_z = fill_z(prob_tab);
    print_z(prob_z);
    expected_value = fill_expected_value(prob_tab, prob_z);
    variance = fill_variance(prob_tab, prob_z, expected_value);
    print_expt_var(expected_value, variance);
}
