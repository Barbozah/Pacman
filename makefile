pacman: pac

pac: upecman.h upecman.c
	gcc upecman.h upecman.c -o pacman -Wall -lncurses -g -Og -Wextra -ansi -pedantic-errors -std=gnu99
