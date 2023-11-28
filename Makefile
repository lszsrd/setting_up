##
## EPITECH PROJECT, 2023
## B-PSU-100-NCY-1-1-myls-laszlo.serdet
## File description:
## Makefile
##

all:
	make -C src/
clean:
	rm -rfv coding-style-reports.log *gcno *gcda vgcore* *~ "#*#"
	make clean -C src/
	make clean -C lib/my/
fclean: clean
	make fclean -C lib/my
	make fclean -C src/
re: fclean all
