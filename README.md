# Epitech-Project-Malloc

The Goal of this project is to recode the Malloc family functions : Malloc, free, realloc and reallocarray.

How to make ? : $ make

How to launch ? : First you have to preload the library you have just created otherwise your binary will use the Malloc function from the Lib C instead of yours.

./LD_PRELOAD=./libmy_malloc.so {command}

Example :

./LD_PRELOAD=./libmy_malloc.so ./ls

./LD_PRELOAD=./libmy_malloc.so ./ls -R
