/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** my_printf.c
*/

#include "../../include/my_printf.h"
#include <stdarg.h>
#include <unistd.h>

void initialize_tab(int (*all_specifiers[256])(va_list))
{
    for (int i = 0; i < 256; i++) {
        all_specifiers[i] = 0;
    }
    all_specifiers['d'] = d_and_i_flags;
    all_specifiers['i'] = d_and_i_flags;
    all_specifiers['s'] = s_flag;
    all_specifiers['c'] = c_flag;
    all_specifiers['o'] = o_flag;
    all_specifiers['X'] = maj_x_flag;
    all_specifiers['x'] = x_flag;
    all_specifiers['u'] = u_flag;
    all_specifiers['f'] = f_flag;
    all_specifiers['F'] = f_flag;
    all_specifiers['p'] = p_flag;
    all_specifiers['%'] = pc_flag;
    all_specifiers['e'] = e_flag;
    all_specifiers['E'] = e_flag_maj;
    all_specifiers['g'] = g_flag;
}

int conditions(int (*all_specifiers[256])(va_list), char *format,
    int i, va_list arg)
{
    if (all_specifiers[(int)format[i]]) {
        all_specifiers[(int)format[i]](arg);
    } else
        return 84;
    return 0;
}

int my_printf(char *format, ...)
{
    va_list arg;
    int (*all_specifiers[256])(va_list);
    int count = 0;

    va_start(arg, format);
    initialize_tab(all_specifiers);
    for (int i = 0; format[i]; i++) {
        if (format[i + 1] == 'n' && format[i] == '%') {
            n_flag(arg, count);
        }
        if (format[i] == '%') {
            i++;
            conditions(all_specifiers, format, i, arg);
            count++;
        } else
            write(1, &format[i], 1);
        count++;
    }
    va_end(arg);
    return 0;
}
