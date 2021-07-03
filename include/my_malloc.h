/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** my_malloc
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct node_s
{
    void *mem_ptr;
    size_t size;
    bool is_free;
    struct node_s *next;
} node_t;

typedef struct list_s
{
    node_t *head;
    node_t *tail;
} list_t;

extern list_t *mem_list;

extern void *malloc(size_t);
extern void free(void *ptr);
extern void *realloc(void *ptr, size_t size);
extern void *calloc(size_t nmemb, size_t size);
extern void *reallocarray(void *ptr, size_t nmemb, size_t size);

void list_handler (node_t *node);
node_t *create_node(size_t size, bool is_free);
void *assign_value_node(void *tmp_ptr, size_t size);
void *check_free_space(list_t *mem_list, size_t size);
size_t new_align_size(size_t size, size_t size_bis);
int mputnbr(long nb);
int mputnbrn(long nb);
int mputstr(char *str);
int mputstrn(char *str);
void change_base(long long int nb, char *base);
void print_adrr(void *addr);

#endif /* !MY_H_ */