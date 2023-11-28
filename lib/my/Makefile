##
## EPITECH PROJECT, 2023
## src/Makefile
## File description:
## Precompile all .c files and create the lib's archive
##

SRC		=	$(wildcard *.c)
OBJ		=	$(SRC:.c=.o)
NAME	=	libmy.a
INCLUDE =	../../include

all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p $(INCLUDE)
	cp $(NAME) ../
	cp my.h $(INCLUDE)
	cp my_printf.h $(INCLUDE)
	make clean
clean:
	rm -rvf *~ "#*#" *.out coding-style-reports.logs
fclean: clean
	rm -rvf $(OBJ) $(NAME) ../$(NAME) $(INCLUDE)
	rm -rvf unit_tests *.gcno *.gcda main.c
re: fclean all
