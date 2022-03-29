##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	sources/error_handling.c	\
		sources/one_line.c	\
		sources/set_map.c	\
		sources/find_max.c	\
		sources/get_columns.c	\
		sources/my_getnbr.c	\
		sources/get_start.c	\
		sources/set_buffer.c	\
		sources/bsq.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	find . -type f \( -name "*.o" -or -name "*#*" -or -name "*~" \
	-or -name "*.gcno" -or -name "*.gcda" \) -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean
