/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** calloc
*/

#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t to_allocate = nmemb * size;
    void *new_ptr;

    new_ptr = malloc(to_allocate);
    memset(new_ptr, 0, to_allocate);
    return (new_ptr);
}