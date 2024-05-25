/*
** EPITECH PROJECT, 2023
** my_str_isupper
** File description:
** my_str_isupper
*/


int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            return (1);
    }
    return (0);
}
