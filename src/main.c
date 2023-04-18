/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-yanis.ktab
** File description:
** main.c
*/

#include "../include/sokoban.h"

static void error(int argc)
{
    if (argc != 2) {
        my_putstr("ça marche pas\n");
        exit(84);
    }
}

static void print_help(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("      ./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("    map file representing the warehouse map, containing");
        my_putstr("‘#’ for walls,\n");
        my_putstr("    ‘P’ for the player, ‘X’ for boxes and ‘O’ for storage");
        my_putstr("locations.\n");
    }
}

void print_map(game_t *game)
{
    for (int i = 0; game->tab[i] != NULL; i++) {
        mvprintw((LINES / 2) + i - 8, (COLS / 2) - 10, game->tab[i]);
    }
}

static void print(char **argv, game_t * game)
{
    game->map = my_cat(argv);
    game->tab = my_str_to_word_array(game->map);
    game->new_map = my_str_to_word_array(game->map);
    int key = 0;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    while (1) {
        clear();
        player(game);
        print_map(game);
        key = getch();
        my_key(key, game);
        if (check(game) == 0)
            break;
        refresh();
    }
    print_map(game), refresh(), endwin();
}

int main(int argc, char **argv)
{
    game_t *game = malloc(sizeof(game_t));

    error(argc);
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        print_help(argv);
    if (my_cat(argv) == NULL)
        exit (84);
    print(argv, game);
    return 0;
}