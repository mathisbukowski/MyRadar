/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** my_revstr
*/
#include <stdarg.h>

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H
int my_put_nbr(int n);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
void my_putchar(char c);
char *my_revstr(char *str);
int my_strlen(char const *str);
int pc_flag(va_list arg);
int my_printf(char *format, ...);
int o_flag(va_list arg);
int c_flag(va_list arg);
int s_flag(va_list arg);
int d_and_i_flags(va_list arg);
int f_flag(va_list arg);
int u_flag(va_list arg);
void u_flag_rec(unsigned int nb);
int x_flag(va_list arg);
int maj_x_flag(va_list arg);
int p_flag(va_list arg);
int n_flag(va_list arg, int count);
int my_put_nbr_f_flag(int n);
int g_flag(va_list arg);
int e_flag_maj(va_list arg);
int e_flag(va_list arg);
#endif //MY_PRINTF_H
