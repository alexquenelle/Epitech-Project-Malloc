/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** align
*/

#include "malloc.h"

size_t new_align_size(size_t size, size_t size_bis) {
    size_t value = (size + (size_bis * (size % size_bis > 0))) / size_bis;
    return (value);
}