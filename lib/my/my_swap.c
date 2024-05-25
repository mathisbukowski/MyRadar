/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** swap number
*/

void my_swap(int *a, int *b)
{
    int i;

    i = *a;
    *a = *b;
    *b = i;
}
