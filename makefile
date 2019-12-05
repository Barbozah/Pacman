pacman: pac

pac: upecman.h upecman.c
	g++ upecman.h upecman.c -o pacman -Wall -lncurses -g -Og -Wextra -ansi -pedantic-errors
