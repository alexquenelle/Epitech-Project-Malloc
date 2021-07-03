/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** realloc
*/

#include "my_malloc.h"

void *realloc(void *ptr, size_t size) {
    node_t *node;
    size_t size_align = new_align_size(size + sizeof(node_t),
    2 * sizeof(size)) * (2 * sizeof(size));

    if (mem_list == NULL)
        return (NULL);

    for (node = mem_list->head; node != NULL; node = node->next) {
        if (node->mem_ptr == ptr)
            break;
    }

    if (ptr == NULL || node == NULL)
        return (malloc(size));

    if (node->size >= size_align) {
        node->size = size_align;
        return (node->mem_ptr);
    } else
        return (memcpy(sbrk(node->size + size_align),
        ptr, node->size + size_align));
}