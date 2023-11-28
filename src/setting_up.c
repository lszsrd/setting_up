/*
** EPITECH PROJECT, 2023
** B-CPE-110-NCY-1-1-settingup-laszlo.serdet-1
** File description:
** setting_up
*/

#include "my.h"
#include "setting_up.h"

/* Re-wrote a better my_str_to_word_array function taking '\n' as separators */
static char **my_str_to_word_array_custom(const char *str)
{
    char **return_array;
    long word = 1;
    int sp = 0;
    int old_sp = 0;

    for (int i = 0; str[i] != 0; i++)
        word += (str[i] == '\n' && str[i - 1] != 0 && str[i + 1] != 0) ? 1 : 0;
    return_array = malloc(sizeof(char *) * (word + 1));
    for (int i = 0; i < word; i++) {
        for (old_sp = sp; str[i + sp] != 0 && str[i + sp] != '\n'; sp++);
        if ((sp - old_sp) <= 0)
            return NULL;
        return_array[i] = malloc(sizeof(char) * ((sp - old_sp) + 1));
        for (int j = old_sp; j < sp; j++)
            return_array[i][j - old_sp] = str[i + j];
        return_array[i][sp - old_sp] = 0;
    }
    return_array[word] = NULL;
    return return_array;
}

static int error_handler(int ac, char **av)
{
    char buf[32] = {0};

    if (ac < 2)
        return -1;
    if (ac == 2) {
        if (read(open(av[1], O_RDONLY), buf, 32) == -1)
            return -2;
        return 0;
    }
    return (ac == 3) ? 1 : -3;
}

/* Extract board from a given path */
static char **get_map(char *path)
{
    struct stat sb;
    char *b = (stat(path, &sb) != -1) ? malloc(sb.st_size + 1) : NULL;
    char **map;

    b[sb.st_size] = 0;
    map = (b != NULL && read(open(path, O_RDONLY), b, sb.st_size) != -1)
        ? my_str_to_word_array_custom(b) : NULL;
    free(b);
    return map;
}

/* Generate a board from arguments given by the user */
static char **generate_map(char **av)
{
    char **board;
    int size = my_getnbr(av[1]);
    int k = 0;

    for (int i = 0; av[2][i] != 0; i++)
        if ((av[2][i] != '.' && av[2][i] != 'o') || size < 1)
            return NULL;
    board = malloc(sizeof(char *) * (size * size) + 1);
    board[0] = av[1];
    for (int i = 1; i <= size; i++) {
        board[i] = malloc(sizeof(char) * (size + 1));
        for (int j = 0; j < size; j++) {
            board[i][j] = av[2][k];
            k = k < (my_strlen(av[2]) - 1) ? k + 1 : 0;
        }
        board[i][size] = 0;
    }
    board[size + 1] = NULL;
    return board;
}

/* Free the board, number of allocations dependes from where we get the map */
static int free_b(s_board *b, bool mode)
{
    int i = mode ? 0 : 1;

    for (; b->board[i] != NULL; i++)
        free(b->board[i]);
    free(b->board);
    return b->is_valid ? 0 : 84;
}

/* Primal call of the function */
int setting_up(int ac, char **av)
{
    s_board b;

    b.board = (error_handler(ac, av) == 0) ? get_map(av[1]) : NULL;
    b.board = (error_handler(ac, av) == 1 && av[2][0] != 0)
        ? generate_map(av) : b.board;
    if (b.board == NULL || b.board[1] == NULL)
        return 84;
    b.is_valid = true;
    for (int i = 0; b.board[0][i] != 0; i++)
        b.is_valid = (my_isnum(b.board[0][i])) ? b.is_valid : false;
    b.lines = my_getnbr(b.board[0]);
    for (b.columns = 0; b.board[1][b.columns] != 0; b.columns++);
    for (int i = find_biggest_square(&b); i <= b.lines; i++)
        i += (i > 0 && b.is_valid) ? 0 * my_printf("%s\n", b.board[i]) : 0;
    return error_handler(ac, av) == 1 ? free_b(&b, false) : free_b(&b, true);
}
