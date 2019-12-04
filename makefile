pacmen: pac

pac: upecman.h upecman.c
	g++ upecman.h upecman.c -o pacmen -Wall -lncurses -g -Og -Wextra -ansi -pedantic-errors
