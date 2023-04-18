/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-yanis.ktab
** File description:
** move.c
*/

#include "../include/sokoban.h"

int player(game_t *game)
{
    int j = 0;

    for (int i = 0; game->tab[j] != NULL; i++) {
        if (game->tab[j][i] == '\0') {
            i = 0;
            j++;
        } else if (game->tab[j][i] == 'P') {
            game->pos_y = j;
            game->pos_x = i;
            return 0;
        }
    }
    exit(84);
}

void check_o_down(game_t *game)
{
    if (game->tab[game->pos_y + 1][game->pos_x] == 'O') {
        game->tab[game->pos_y][game->pos_x] = ' ';
        game->tab[game->pos_y + 1][game->pos_x] = 'P';
        game->pos_y++;
        return;
    }
}

void check_o_up(game_t *game)
{
    if (game->tab[game->pos_y - 1][game->pos_x] == 'O') {
        game->tab[game->pos_y][game->pos_x] = ' ';
        game->tab[game->pos_y - 1][game->pos_x] = 'P';
        game->pos_y--;
        return;
    }
}

void check_o_right(game_t *game)
{
    if (game->tab[game->pos_y][game->pos_x + 1] == 'O') {
        game->tab[game->pos_y][game->pos_x] = ' ';
        game->tab[game->pos_y][game->pos_x + 1] = 'P';
        game->pos_x++;
        return;
    }
}

void check_o_left(game_t *game)
{
    if (game->tab[game->pos_y][game->pos_x - 1] == 'O') {
        game->tab[game->pos_y][game->pos_x] = ' ';
        game->tab[game->pos_y][game->pos_x - 1] = 'P';
        game->pos_x--;
        return;
    }
}