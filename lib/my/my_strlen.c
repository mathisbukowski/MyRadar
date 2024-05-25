/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Give the lenght of a string
*/

int my_strlen(char const *str)
{
    int index;

    index = 0;
    while (str[index] != '\0'){
        index++;
    }
    return (index);
}
