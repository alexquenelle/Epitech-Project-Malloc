/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** tools
*/

#include "my_malloc.h"

void print_list(list_t *mem_list)
{
    node_t *node;

    if (mem_list== NULL)
        return;

    mputstr("\nList: \n\t");

    for (node = mem_list->head; node != NULL; node = node->next) {
        mputstr("| free -> ");
        mputnbr(node->is_free);
        mputstr(" & size -> ");
        mputnbr(node->size);
        mputstr(" & pointer -> ");
        print_adrr(node->mem_ptr);

        if (node != NULL)
            mputstr(" | ---> ");
    }
    mputstr("\n\n");
}

int mputnbr(long nb)
{
    long len = 0;
    long divider = 0;
    char c = '?';
    long ret = 0;

    if (nb <= 0) {
        ret = write(1, (!nb ? "0" : "-"), 1) < 1;
        nb *= -1;
    }
    for (long cpy = nb; cpy; (cpy /= 10), ++len);
    while (--len >= 0 && !ret) {
        divider = 1;
        for (long cpy = len; cpy; (divider *= 10), --cpy);
        c = (nb / divider) + 48;
        ret = write(1, &c, 1) < 1;
        nb -= (nb / divider) * divider;
    }
    return ret;
}

int mputnbrn(long nb)
{
    mputnbr(nb);
    write(1, "\n", 1);
    return 1;
}

int mputstr(char *str)
{
    return write(1, str, strlen(str));
}

int mputstrn(char *str)
{
    write(1, str, strlen(str));
    return write(1, "\n", 1);
}