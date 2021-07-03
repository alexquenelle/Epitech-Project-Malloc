/*
** EPITECH PROJECT, 2020
** my_putnbr.c
** File description:
** print a nbr on stdout
*/

#include <unistd.h>
#include <string.h>
#define RES_LEN     30

void base(long long int nb, char *base)
{
    char res[RES_LEN + 1] = {};
    res[RES_LEN] = '\0';
    int base_len = 16;
    int val;

    for (int i = RES_LEN - 1; nb > 0; --i) {
        val = nb % base_len;
        nb /= base_len;
        res[i] = base[val];
    }
    write(1, res, RES_LEN);
}

void print_adrr(void *addr)
{
    write(1, "[0x", 3);
    base((long)addr, "0123456789abcdef");
    write(1, "]", 2);
}