/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    int index;
    int a = 0;
    char b;
    char c;

    while (str[a] != '\0') {
        a++;
    }
    for (index = 0; index < a / 2; index++) {
        b = str[index];
        c = str[a - index - 1];
        str[index] = c;
        str[a - index - 1] = b;
    }
    return (str);
}
