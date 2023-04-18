/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-yanis.ktab
** File description:
** player.c
*/

#include "../include/sokoban.h"

static void m_down(game_t * game)
{
    if (game->tab[game->pos_y + 1][game->pos_x] == ' ') {
        game->tab[game->pos_y + 1][game->pos_x] = 'P';
        game->tab[game->pos_y][game->pos_x] = ' ';
        game->pos_y++;
        return;
    }
    if (game->tab[game->pos_y + 1][game->pos_x] == 'X') {
        if (game->tab[game->pos_y + 2][game->pos_x] != '#' &&
            game->tab[game->pos_y + 2][game->pos_x] != 'X') {
            game->tab[game->pos_y][game->pos_x] = ' ';
            game->tab[game->pos_y + 1][game->pos_x] = 'P';
            game->tab[game->pos_y + 2][game->pos_x] = 'X';
            game->pos_y++;
            return;
        }
    }
    check_o_down(game);
}

static void m_up(game_t *game)
{
    if (game->tab[game->pos_y - 1][game->pos_x] == ' ') {
        game->tab[game->pos_y - 1][game->pos_x] = 'P';
        game->tab[game->pos_y][game->pos_x] = ' ';
        game->pos_y--;
        return;
    }
    if (game->tab[game->pos_y - 1][game->pos_x] == 'X') {
        if (game->tab[game->pos_y - 2][game->pos_x] != '#' &&
            game->tab[game->pos_y - 2][game->pos_x] != 'X') {
            game->tab[game->pos_y][game->pos_x] = ' ';
            game->tab[game->pos_y - 1][game->pos_x] = 'P';
            game->tab[game->pos_y - 2][game->pos_x] = 'X';
            game->pos_y--;
        return;
        }
    }
    check_o_up(game);
}

static void m_right(game_t *game)
{
    if (game->tab[game->pos_y][game->pos_x + 1] == ' ') {
        game->tab[game->pos_y][game->pos_x + 1] = 'P';
        game->tab[game->pos_y][game->pos_x] = ' ';
        game->pos_x++;
        return;
    }
    if (game->tab[game->pos_y][game->pos_x + 1] == 'X') {
        if (game->tab[game->pos_y][game->pos_x + 2] != '#' &&
        game->tab[game->pos_y][game->pos_x + 2] != 'X') {
            game->tab[game->pos_y][game->pos_x] = ' ';
            game->tab[game->pos_y][game->pos_x + 1] = 'P';
            game->tab[game->pos_y][game->pos_x + 2] = 'X';
            game->pos_x++;
        return;
        }
    }
    check_o_right(game);
}

static void m_left(game_t *game)
{
    if (game->tab[game->pos_y][game->pos_x - 1] == ' ') {
        game->tab[game->pos_y][game->pos_x - 1] = 'P';
        game->tab[game->pos_y][game->pos_x] = ' ';
        game->pos_x--;
        return;
    }
    if (game->tab[game->pos_y][game->pos_x - 1] == 'X') {
        if (game->tab[game->pos_y][game->pos_x - 2] != '#' &&
            game->tab[game->pos_y][game->pos_x - 2] != 'X') {
            game->tab[game->pos_y][game->pos_x] = ' ';
            game->tab[game->pos_y][game->pos_x - 1] = 'P';
            game->tab[game->pos_y][game->pos_x - 2] = 'X';
            game->pos_x--;
            return;
        }
    }
    check_o_left(game);
}

void my_key(int key, game_t *game)
{
    key == ' ' ? game->tab = my_str_to_word_array(game->map) : 0;
    key == KEY_UP ? m_up(game) : key;
    key == KEY_DOWN ? m_down(game) : key;
    key == KEY_RIGHT ? m_right(game) : key;
    key == KEY_LEFT ? m_left(game) : key;
}