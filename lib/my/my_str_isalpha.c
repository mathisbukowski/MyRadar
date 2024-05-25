/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            return (1);
        if (str[i] >= 97 && str[i] <= 122)
            return (1);
    }
    return (0);
}
