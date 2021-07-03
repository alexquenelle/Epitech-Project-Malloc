/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** malloc
*/

#include "my_malloc.h"

list_t *mem_list = NULL;

node_t *create_node(size_t size, bool is_free)
{
    node_t *nNode;

    nNode = sbrk(sizeof(node_t));

    nNode->size = size;
    nNode->is_free = is_free;
    nNode->next = NULL;

    return nNode;
}

void *check_free_space(list_t *mem_list, size_t size) {
    node_t *node;
    size_t tmp;
    int i = 0;
    void *tmp_ptr;

    if (mem_list == NULL)
        return (NULL);

    for (node = mem_list->head, i; node != NULL; node = node->next, i++) {
        if (node->is_free == true && node->size >= size) {
            if (i == 0) {
                tmp_ptr = node->mem_ptr;
                tmp = node->size;
            } else if (tmp > node->size) {
                tmp_ptr = node->mem_ptr;
                tmp = node->size;
            }
        }
    }
    return (assign_value_node(tmp_ptr, size));
}

void *assign_value_node(void *tmp_ptr, size_t size) {
    node_t *node;
    node = mem_list->head;

    while (node != NULL) {
        if (tmp_ptr == node->mem_ptr) {
            node->size = size;
            node->is_free = false;
            return (node->mem_ptr);
        }
        node = node->next;
    }
    return (NULL);
}

void list_handler (node_t *node) {
    if (mem_list == NULL) {
        mem_list = sbrk(sizeof(list_t));
        mem_list->head = node;
        mem_list->tail = node;
    } else {
        mem_list->tail->next = node;
        mem_list->tail = mem_list->tail->next;
    }
}

void *malloc(size_t size)
{
    if (!size)
        return (NULL);

    size_t size_bis = 2 * sizeof(size);
    node_t *node;
    size = new_align_size(size + sizeof(node_t), size_bis) * size_bis;
    node = create_node(size, false);
    void *free_space = check_free_space(mem_list, size);
    void *new_mem;

    if (free_space != NULL)
        return (free_space);
    else
        new_mem = sbrk(size);

    list_handler(node);

    mem_list->tail->mem_ptr = new_mem;
    return (new_mem);
}