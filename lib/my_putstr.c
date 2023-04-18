/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-yanis.ktab
** File description:
** my_putstr.c
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    write(1, str, i);
}
