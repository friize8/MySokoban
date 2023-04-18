/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-yanis.ktab
** File description:
** sokoban.h
*/

#ifndef SIGNAL_H
    #define SIGNAL_H
    #include <signal.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <curses.h>
    #include "struct.h"

int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
char *my_cat(char **argv);
int check_input(void);
int init_h(int argc, char **argv);
int my_file(int argc, char **argv);
char **my_str_to_word_array(char const *str);
void print_map(game_t *game);
int player(game_t *game);
int init(game_t * game, int argc, char ** argv);
int move_player_up(game_t * game);
void my_mouv_down(game_t * game);
void my_key(int key, game_t *game);
void check_o_down(game_t *game);
void check_o_up(game_t *game);
void check_o_right(game_t *game);
void check_o_left(game_t *game);
int check(game_t *game);
void win(game_t *game);

#endif