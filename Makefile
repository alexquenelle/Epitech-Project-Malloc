##
## EPITECH PROJECT, 2021
## B-FUN-300-BDX-3-1-funPoolDay2-alexandre.quenelle
## File description:
## Makefile
##

SRC			=	src/malloc.c		\
				src/align.c			\
				src/free.c			\
				src/realloc.c		\
				src/calloc.c		\
				src/reallocarray.c	\

BUILDDIR	=	obj

OBJ			=	$(SRC:%.c=$(BUILDDIR)/%.o)

NAME		=	libmy_malloc.so

CC			=	gcc

LD			=	$(CC)

CFLAGS		=	-fPIC -I./include

LDFLAGS		=	-shared

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LINK.o) $^ $(LDLIBS) $(OUTPUT_OPTION)

clean:
	rm -rf $(BUILDDIR)
	rm -f *.gc*
	rm -f a.out

fclean: clean
	rm -f $(NAME)

re:	fclean all

.SECONDEXPANSION:
$(BUILDDIR)/%.o : override CPPFLAGS += -MT $@ -MMD -MP -MF $(@:.o=.d)
$(BUILDDIR)/%.o : %.c | $$(@D)/.
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILDDIR)/.:
	mkdir $@

$(BUILDDIR)%/.:
	mkdir -p $@

.PRECIOUS:	$(BUILDDIR)/. $(BUILDDIR)%/.

.PHONY: all re clean fclean

-include $(OBJ:.o=.d)