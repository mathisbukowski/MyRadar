/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    while (((*s1) != '\0') && ((*s2) != '\0') && n > 0) {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
        n--;
    }
    if (n == 0)
        return 0;
    return *s1 - *s2;
}
