/*
** EPITECH PROJECT, 2023
** my_strupcase
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    int index;

    for (index = 0; str[index] != '\0'; index++) {
        if (str[index] >= 97 && str[index] <= 122) {
            str[index] = str[index] - 32;
        }
    }
    return (str);
}
