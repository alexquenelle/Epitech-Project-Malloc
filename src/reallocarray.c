/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** reallocarray
*/

#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    return (realloc(ptr, nmemb * size));
}