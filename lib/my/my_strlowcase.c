/*
** EPITECH PROJECT, 2023
** my_strlowcase
** File description:
** my_strlowcase
*/


char *my_strlowcase(char *str)
{
    int index;

    for (index = 0; str[index] != '\0'; index++) {
        if (str[index] >= 65 && str[index] <= 90) {
            str[index] = str[index] + 32;
        }
    }
    return (str);
}
