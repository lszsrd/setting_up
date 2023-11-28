##
## EPITECH PROJECT, 2023
## B-PSU-100-NCY-1-1-myls-laszlo.serdet
## File description:
## Makefile
##

SRC		=	$(wildcard *.c)
OBJ		=	$(SRC:.c=.o)
NAME	=	setting_up
CFLAGS	+=	-O2 -I../include
LDFLAGS += 	-L../lib/my -lmy

all: $(NAME)
build_lib:
	make -C ../lib/my
$(NAME): build_lib $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
	mv $(NAME) ../
	make clean
clean:
	rm -rfv coding-style-reports.log *gcno *gcda vgcore* *~ "#*#" .gcda .gcno
fclean: clean
	rm -rvf $(OBJ) $(NAME) ../$(NAME) ../include/my.h
	rm -rvf unit_tests *.gcno *.gcda
re: fclean all
