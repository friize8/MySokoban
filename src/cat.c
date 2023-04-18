/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-yanis.ktab
** File description:
** cat.c
*/

#include "../include/sokoban.h"

char *my_cat(char **argv)
{
    struct stat st;
    stat(argv[1], &st);
    char *buf = malloc(sizeof(char) * st.st_size + 1);
    int x = 0;

    int fd = open(argv[1], O_RDONLY);
    x = read(fd, buf, st.st_size);
    buf[st.st_size] = '\0';
    if (fd == -1)
        return NULL;
    if (x == -1 || x == 0)
        return NULL;
    close(fd);
    return buf;
}

static int checking(game_t *game)
{
    int j = 0;
    int o = 0;

    for (int i = 0; game->new_map[i] != NULL; j++) {
        if (game->new_map[i][j] == 'O' &&
        (game->tab[i][j] == 'P' || game->tab[i][j] == 'O'))
            o++;
        if (game->new_map[i][j] == '\0') {
            i++;
            j = 0;
        }
    }
    return o;
}

int check(game_t *game)
{
    int i = 0;
    int j = 0;

    for (; game->new_map[i] != NULL; j++) {
        if (game->new_map[i][j] == 'O') {
            if (game->tab[i][j] == ' ')
                game->tab[i][j] = 'O';
        }
        if (game->new_map[i][j] == '\0') {
            i++;
            j = 0;
        }
    }
    if (checking(game) == 0) {
        print_map(game);
        refresh();
        endwin();
        return 0;
    }
    return 84;
}
