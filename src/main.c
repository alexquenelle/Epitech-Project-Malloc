/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** main
*/

#include "../include/my_malloc.h"
#include <stdio.h>

int main(void)
{
//    char *p1 = NULL;
//    char a1 = 'F';
//    void *tmp1 = sbrk(0);
//    p1 = malloc(30);
//
//    *p1 = a1;
//    free(p1);
//
//    char *p2 = NULL;
//    char a2 = 'P';
//    p2 = malloc(120);
//
//    *p2 = a2;
//    free(p2);
//
//    char *p3 = NULL;
//    char a3 = 'E';
//    p3 = malloc(420);
//
//    *p3 = a3;
//    free(p3);
//
//    char *p4 = NULL;
//    char a4 = 'K';
//    p4 = malloc(20);
//
//    *p4 = a4;
//
//    mputstrn(p1);
//    print_adrr(p1);
//    write(1, "\n", 1);
//    mputstrn(p2);
//    print_adrr(p2);
//    write(1, "\n", 1);
//    mputstrn(p3);
//    print_adrr(p3);
//    write(1, "\n", 1);
//    mputstrn(p4);
//    print_adrr(p4);
//
//    if (p1 == NULL) {
//        mputstr("Allocation failed.\n");
//        return 84;
//    }



   char *str;

   str = (char *) malloc(15);
   strcpy(str, "tutorialspoint");
   mputstrn(str);
   print_adrr(str);
  // printf("String = %s,  Address = %u\n", str, str);

    str = (char *) realloc(str, 15);
    strcat(str, ".com");
    mputstrn(str);
    print_adrr(str);
  //  printf("String = %s,  Address = %u\n", str, str);

   free(str);

    return 0;
}