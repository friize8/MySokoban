/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-yanis.ktab
** File description:
** my_str_to_word_array.c
*/

#include "../include/sokoban.h"

static int get_nbr_of_word(char const *str)
{
    int nb_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            nb_word++;
    }
    return (nb_word);
}

static int nbr_char(char const *str, int *i)
{
    int ret = 0;
    for (; str[*i] != '\n' && str[*i] != '\0'; *i = *i + 1)
        ret++;
    *i = *i + 1;
    return ret;
}

static char **malloc_array(char const *str)
{
    int len_char = 0;
    int m = 0;
    int nb_lines = get_nbr_of_word(str);
    char **tab = malloc(sizeof(char *) * (nb_lines + 1));
    int pos = 0;

    for (int i = 0; i != nb_lines; i++) {
        len_char = nbr_char(str, &pos);
        tab[m] = malloc(sizeof(char) * len_char + 1);
        m++;
    }
    return (tab);
}

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    int k = 0;
    char **tab = malloc_array(str);

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            tab[j][k] = '\0';
            ++j;
            k = 0;
        } else {
            tab[j][k] = str[i];
            k++;
        }
    }
    tab[j] = NULL;
    return (tab);
}
