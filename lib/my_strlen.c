/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-yanis.ktab
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
