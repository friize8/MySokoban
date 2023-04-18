/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** struct
*/

#include "sokoban.h"

typedef struct game {
    int pos_x;
    int pos_y;
    char *map;
    char **tab;
    char **new_map;
} game_t;
