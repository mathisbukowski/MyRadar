/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** my_atoi.c
*/

int my_atoi(char const *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            break;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}
