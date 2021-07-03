/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** free
*/

#include "my_malloc.h"

void free(void *ptr)
{
    node_t *node;

    if (mem_list == NULL)
        return;

    node = mem_list->head;
    while (node != NULL)
    {
        if (node->mem_ptr == ptr)
        {
            node->is_free = true;
        }
        node = node->next;
    }
    return;
}