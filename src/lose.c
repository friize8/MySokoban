/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-yanis.ktab
** File description:
** lose.c
*/

#include "../include/sokoban.h"

void lose(game_t *game)
{
    int j = 0;

    for (int i = 0; game->tab[j] != NULL; i++) {
        if (game->tab[j][i] == '\0') {
            i = 0;
            j++;
        }
        else if (game->tab[j][i] == 'X') {
            game->pos_y = j;
            game->pos_x = i;
            return 0;
        }
    }
    exit(84);
}
