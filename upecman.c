/***************************************************************************
*   upecman.c                                Version 20160529.013231      *
*                                                                         *
*   Pacman Ncurses                                                        *
*   Copyright (C) 2016         by Ruben Carlo Benante                     *
***************************************************************************
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License.        *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************
*   To contact the author, please write to:                               *
*   Ruben Carlo Benante                                                   *
*   Email: rcb@beco.cc                                                    *
*   Webpage: http://www.beco.cc                                           *
*   Phone: +55 (81) 3184-7555                                             *
***************************************************************************/

/* ---------------------------------------------------------------------- */

/**
* @file upecman.c
* @ingroup GroupUnique
* @brief Pacman Ncurses
* @details This program really do a nice job as a template, and template only!
* @version 20160529.013231
* @date 2016-05-29
* @author Ruben Carlo Benante <<rcb@beco.cc>>
* @par Webpage
* <<a href="http://www.beco.cc">www.beco.cc</a>>
* @copyright (c) 2016 GNU GPL v2
* @note This program is free software: you can redistribute it
* and/or modify it under the terms of the
* GNU General Public License as published by
* the Free Software Foundation version 2 of the License.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program.
* If not, write to the Free Software Foundation, Inc.,
* 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
* Or read it online at <<http://www.gnu.org/licenses/>>.
*
*
* @todo Now that you have the template, hands on! Programme!
* @warning Be carefull not to lose your mind in small things.
* @bug This file right now does nothing usefull
*
*/

/*
* Instrucoes para compilar:
*      $make
* ou
*      $gcc upecman.c -o upecman.x -Wall -lncurses -g -Og
*          -Wextra -ansi -pedantic-errors -DDEBUG=1
*/

/* ---------------------------------------------------------------------- */

/* includes */
#include <cstddef>
#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <assert.h> /* Verify assumptions with assert */
#include <unistd.h> /* UNIX standard function */
#include "upecman.h" /* To be created for this template if needed */
#include <time.h>  /* Time and date functions */
#include <math.h>  /* Mathematics functions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */

/**
* @ingroup GroupUnique
* @brief This is the main event of the evening
* @details Ladies and Gentleman... It's tiiiime!
* Fightiiiiing at the blue corner,
* he, who has compiled more C code than any other adversary in the history,
* he, who has developed UNIX and Linux, and is an inspiration to maaany languages
* and compilers, the GNU C Compiler, GCC!
* Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
* valid experience but angrily, blindly, and no doubtfully, will try to
* compile this program without errors. He, the student, the apprentice,
* the developer, beco!!
*
* @param[in] argc Argument counter
* @param[in] argv Argument strings (argument values)
*
* @retval 0 If succeed (EXIT_SUCCESS).
* @retval 1 Or another error code if failed.
*
* @par Example
* @code
*    $./upecman -h
* @endcode
*
* @warning   Be carefull with...
* @bug There is a bug with...
* @todo Need to do...
* @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
* @author Ruben Carlo Benante
* @version 20160529.013231
* @date 2016-05-29
*
*/

t_game pinkyMov(t_game g);

int main(int argc, char *argv[]) {
	/*IFDEBUG("main()\n");*/
	int opt; /* return from getopt() */
	t_game g; /* the game */
	const char *sready = "Are you ready? (y/n)"; /* ready string */
	int kin; /* keyboard input */
	/*IFDEBUG("Starting optarg loop...\n");*/
	/*  getopt() configured options:
	 *        -h  help
	 *        -c  copyright & version
	 *        -v  verbose
	 */
	opterr = 0;
	while((opt = getopt(argc, argv, "hvc")) != EOF)
      	switch(opt) {
        	case 'h':
           		help();
           		break;
        	case 'v':
           		verb++;
           		break;
           	case 'c':
           		copyr();
            	break;
           	case '?':
           	default:
            	printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
            	return EXIT_FAILURE;
       	}
	if(verb) printf("Verbose level set at: %d\n", verb);
	/* ...and we are done */
	IFDEBUG("Starting the game now...\n");
	g = upecman_init();
	printlab(g);
	mvprintw(10,25," %s",sready);
	refresh();
	while(1) {
   		kin = getch();
   		if(kin == 'y' || kin == 'Y')
	       break;
   		if(kin == 'n' || kin == 'N') {
	       endwin();
	       return EXIT_SUCCESS;
	   	}
	  	usleep(16667); /* wait 16666 microseconds to avoid frying the processor (1/60 s) */
	}
	clear();
	printlab(g);
	while(1) { /*laço para rodar o jogo*/
		g = MovPac(g);
		g = MovPacDir(g);
		g = blinkymov(g);
		g = pinkyMov(g);
        char score[20] = "";
        sprintf(score, "S C O R E: %d", g.pacman.score);
		mvprintw(10,25, score);
		refresh();
		usleep(16667); /* wait 16666 microseconds to avoid frying the processor (1/60 s) */
	}
	endwin();
	return EXIT_SUCCESS;
}

/*--------------------------- Contagem de Pontos ----------------------------------------------- */
/* Funcao comer os Dots */

t_game pacDots(t_game g) {
	int j = 0;
	int x = g.pacman.pos.x;
	int y = g.pacman.pos.y;
	if(g.lab[y][x] == '.') {
		g.lab[y][x]= ' ';
		g.pacman.pellet++;
		g.pacman.score = g.pacman.score + 10;
	} else if(g.lab[y][x] == 'o') {
		g.pacman.pellet++;
		g.pacman.score = g.pacman.score + 50;
		g.lab[y][x] = ' ';
		/*for(j = blinky; j <= clyde; j++)
			g.ghost[j].mode = afraid;*/
	}
	return g;
}

/* Verifica se o jogador terminou o nivel */

/* -------------------------- Movimentaçao do Pacman -------------------------------------------- */
t_game MovPac(t_game g) {
	int mov;
	start_color();
	switch(mov = getch()) {
		case 'w':
       		if(g.lab[g.pacman.pos.y-1][g.pacman.pos.x] != '#') {
				mvprintw(g.pacman.pos.y, g.pacman.pos.x, " ");
				g.pacman.pos.y -= 1;
				mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
				g.pacman.dir = up;
				mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
				refresh();
				usleep(TEMP);
			}
	    	break;
		case 'a':
			if(g.lab[g.pacman.pos.y][g.pacman.pos.x-1] != '#') {
				mvprintw(g.pacman.pos.y, g.pacman.pos.x, " ");
				g.pacman.pos.x -= 1;
				mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
				g.pacman.dir = left;
				mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
				refresh();
				usleep(TEMP);
			}
			break;
		case 's':
		    if(g.lab[g.pacman.pos.y+1][g.pacman.pos.x] != '#') {
		        mvprintw(g.pacman.pos.y, g.pacman.pos.x, " ");
		        g.pacman.pos.y += 1;
		        mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
		        g.pacman.dir = down;
		        mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
		        refresh();
		        usleep(TEMP);
		    }
		    break;
		case 'd':
		    if(g.lab[g.pacman.pos.y][g.pacman.pos.x+1] != '#') {
		        mvprintw(g.pacman.pos.y, g.pacman.pos.x, " ");
		        g.pacman.pos.x += 1;
		        mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
		        g.pacman.dir = right;
		        mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
		        refresh();
		        usleep(TEMP);
		    }
		    break;
	}
    g = pacDots(g);
	return g;
}

t_game MovPacDir(t_game g) {
   
   start_color();

	switch(g.pacman.dir) {
		case up:
			if(g.lab[g.pacman.pos.y-1][g.pacman.pos.x] != '#') {
				mvprintw(g.pacman.pos.y, g.pacman.pos.x, " ");
                g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
            	g.pacman.pos.y -= 1;
            	mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
            	g.pacman.dir = up;
            	mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
            	refresh();
            	usleep(TEMP);
        	}
        	break;
       	case left:
           	if(g.lab[g.pacman.pos.y][g.pacman.pos.x-1] != '#') {
            	mvprintw(g.pacman.pos.y, g.pacman.pos.x, " ");
                g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
            	if(g.pacman.pos.y == 10 && g.pacman.pos.x == 0){
            		g.pacman.pos.x = 20;
                	mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
              	} else {
                	g.pacman.pos.x -= 1;
                	mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
                	g.pacman.dir = left;
               	}
               	mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
               	refresh();
               	usleep(TEMP);           
           	}
           	break;
       	case down:
           	if(g.lab[g.pacman.pos.y+1][g.pacman.pos.x] != '#') {
           		mvprintw(g.pacman.pos.y, g.pacman.pos.x, " ");
                g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
            	g.pacman.pos.y += 1;
            	mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
               	g.pacman.dir = down;
               	mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
               	refresh();
               	usleep(TEMP);           
           	}
           	break;
       	case right:
           	if(g.lab[g.pacman.pos.y][g.pacman.pos.x+1] != '#') {
               	g.pacman.dir = right;
               	mvprintw(g.pacman.pos.y, g.pacman.pos.x, " ");
                g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
               	if(g.pacman.pos.x == 19 && g.pacman.pos.y == 10){
                   	g.pacman.pos.x = 0;
                   	mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
               	} else {
                   g.pacman.pos.x += 1;
                   mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
               	}
               	mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
               	refresh();
               	usleep(TEMP);           
            }
           	break;
   	}
   	return g;
}

/* ---------------------------BLINKY MOV------------------------------------------- */
t_game blinkymov(t_game g) {
   	int x1,x2,y1,y2;
   	float hipo1,hipo2;
   	y1=g.pacman.pos.y;
   	x1=g.pacman.pos.x;
   	x2=g.ghost[blinky].pos.x;
   	y2=g.ghost[blinky].pos.y;
   	if(g.lab[g.ghost[blinky].pos.y-1][g.ghost[blinky].pos.x] != '#')
       	if(g.lab[g.ghost[blinky].pos.y-1][g.ghost[blinky].pos.x] != '-') {
           	if(g.ghost[blinky].dir != down) {
               	hipo1 = hipo(x1,y1,x2,y2);
               	y2=g.ghost[blinky].pos.y-1;
               	hipo2 = hipo(x1,y1,x2,y2);
               	if(hipo2 < hipo1) {
                    char c[2];
                    sprintf(c, "%c", g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x]);
                   	mvprintw(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, c);
                    mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 6, NULL);
                   	refresh();
                   	g.ghost[blinky].pos.y -= 1;
                   	g.ghost[blinky].dir = up;
                   	mvprintw(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, "B");
                    mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1, NULL);
                   	refresh();
                   	usleep(temp);
                   	return g;
               	}
           	}
       	}
   	if(g.lab[g.ghost[blinky].pos.y+1][g.ghost[blinky].pos.x] != '#')
       	if(g.lab[g.ghost[blinky].pos.y+1][g.ghost[blinky].pos.x] != '-') {
           	if(g.ghost[blinky].dir != up) {
               	hipo1 = hipo(x1,y1,x2,y2);
               	y2=g.ghost[blinky].pos.y+1;
               	hipo2 = hipo(x1,y1,x2,y2);
               	if(hipo2 < hipo1) {
                    char c[2];
                    sprintf(c, "%c", g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x]);
                   	mvprintw(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, c);
                    mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 6, NULL);
                   	refresh();
                   	g.ghost[blinky].pos.y += 1;
                   	g.ghost[blinky].dir = down;
                   	mvprintw(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, "B");
                    mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1, NULL);
                   	refresh();
                   	usleep(temp);
                   	return g;
               	}
           	}
       	}
   	if(g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x+1] != '#')
       if(g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x+1] != '-') {
           	if(g.ghost[0].pos.x == 19 && g.ghost[0].pos.y == 10) {
               	g.ghost[0].pos.x = 0;
               	mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, "B");
                mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1, NULL);
               	refresh();
               	usleep(temp);
               	return g;
           	} else if(g.ghost[0].dir != left) {
               	hipo1 = hipo(x1,y1,x2,y2);
               	x2=g.ghost[0].pos.x+1;
               	hipo2 = hipo(x1,y1,x2,y2);
               	if(hipo2 < hipo1) {
                    char c[2];
                    sprintf(c, "%c", g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x]);
                    if(c[0] == 'B'){
                        char s = ' ';
                        sprintf(c, "%c", s);
                    }
                   	mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, c);
                    mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 6, NULL);
                   	refresh();
                   	g.ghost[0].pos.x += 1;
                   	g.ghost[0].dir = right;
                   	mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, "B");
                    mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1, NULL);
                   	refresh();
                   	usleep(temp);
                   	return g;
               	}
           	}
       	}
   	if(g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x-1] != '#')
		if(g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x-1] != '-') {
           	if(g.ghost[0].pos.y == 10 && g.ghost[0].pos.x == 0) {
				g.ghost[0].pos.x = 20;
				mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, "B");
                mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1, NULL);
				refresh();
				usleep(temp);
				return g;
           	}
           	else if(g.ghost[0].dir != right) {
				hipo1 = hipo(x1,y1,x2,y2);
				x2=g.ghost[0].pos.x-1;
				hipo2 = hipo(x1,y1,x2,y2);
				if(hipo2 < hipo1) {
                    char c[2];
                    sprintf(c, "%c", g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x]);
                    if(c[0] == 'B' || c[0] == '@'){
                        char s = ' ';
                        sprintf(c, "%c", s);
                    }
					mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, c);
                    mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 6, NULL);
                   	refresh();
					g.ghost[0].pos.x -= 1;
					g.ghost[0].dir = left;
					mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, "B");
                    mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1, NULL);
					refresh();
					usleep(temp);
					return g;
               	}
           	}
       	}
   	if(g.lab[g.ghost[0].pos.y-1][g.ghost[0].pos.x] != '#')
       	if(g.lab[g.ghost[0].pos.y-1][g.ghost[0].pos.x] != '-') {
            char c[2];
            sprintf(c, "%c", g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x]);
			mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, c);
            mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 6, NULL);
            refresh();
			g.ghost[0].pos.y -= 1;
			g.ghost[0].dir = up;
			mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, "B");
            mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1, NULL);
			refresh();
			usleep(temp);
			return g;
       	}
   	if(g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x-1] != '#')
       if(g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x-1] != '-') {
            char c[2];
            sprintf(c, "%c", g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x]);
            if(c[0] == 'B' || c[0] == '@'){
                char s = ' ';
                sprintf(c, "%c", s);
            }
			mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, c);
            mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 6, NULL);
            refresh();
			g.ghost[0].pos.x -= 1;
			g.ghost[0].dir = left;
			mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, "B");
            mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1, NULL);
			refresh();
			usleep(temp);
			return g;
       	}
   	if(g.lab[g.ghost[0].pos.y+1][g.ghost[0].pos.x] != '#')
       	if(g.lab[g.ghost[0].pos.y+1][g.ghost[0].pos.x] != '-') {
            char c[2];
            sprintf(c, "%c", g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x]);
			mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, c);
            mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 6, NULL);
            refresh();
			g.ghost[0].pos.y += 1;
			g.ghost[0].dir = down;
			mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, "B");
            mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1, NULL);
			refresh();
			usleep(temp);
			return g;
       	}
   	if(g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x+1] != '#')
       	if(g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x+1] != '-') {
            char c[2];
            sprintf(c, "%c", g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x]);
            if(c[0] == 'B' || c[0] == '@'){
                char s = ' ';
                sprintf(c, "%c", s);
            }
           	mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, c);
            mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 6, NULL);
            refresh();
           	g.ghost[0].pos.x += 1;
           	g.ghost[0].dir = right;
           	mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, "B");
            mvchgat(g.ghost[blinky].pos.y, g.ghost[blinky].pos.x, 1, A_BOLD, 1, NULL);
           	refresh();
           	usleep(temp);
           	return g;
       	}
   	return g;
}


/*------------------- MOVIMENTA PINKY ------------------*/

t_pos nnPacman(t_game g, t_pos p1, t_pos p2){
    int i, j, n = 99999, h;
    t_pos r;
    r.x = p1.x;
    r.y = p1.y;
    h = hipo(p1.x+1, p1.y, p2.x, p2.y);
    if(h < n && g.lab[p1.y][p1.x+1] != '#'){
        n = h;
        r.x = p1.x+1;
        r.y = p1.y;
    }
    h = hipo(p1.x-1, p1.y, p2.x, p2.y);
    if(h < n && g.lab[p1.y][p1.x-1] != '#'){
        n = h;
        r.x = p1.x-1;
        r.y = p1.y;
    }
    h = hipo(p1.x, p1.y+1, p2.x, p2.y);
    if(h < n && g.lab[p1.y+1][p1.x] != '#'){
        n = h;
        r.x = p1.x;
        r.y = p1.y+1;
    }
    h = hipo(p1.x, p1.y-1, p2.x, p2.y);
    if(h < n && g.lab[p1.y][p1.x-1] != '#'){
        n = h;
        r.x = p1.x;
        r.y = p1.y-1;
    }
    return r;
    for(i=-1;i<2;i++){
        for(j=-1;j<2;j++){
            if(p1.y+i < 2 ||
               p1.y+i >= 21 ||
               p1.x+j < 2 ||
               p1.x+j >= 19 ||
               g.lab[p1.y+i][p1.x+j] == '#' ||
               (i == -1 && j == -1) ||
               (i == -1 && j == 1) ||
               (i == 1 && j == -1) ||
               (i == 1 && j == 1)){
                continue;
            }else{
                int h = hipo(p1.x+i, p1.y+j, p2.x, p2.y);
                if(h<n){
                    n = h;
                    r.x = p1.x+j;
                    r.y = p1.y+i;
                }
            }
        }
    }
    return r;
}

t_game pinkyMov(t_game g) {
    t_pos nn, p;
    switch(g.pacman.dir) {
       	case up:
            p.x = g.pacman.pos.x;
            p.y = g.pacman.pos.y-4;
            break;
       	case down:
           	p.x = g.pacman.pos.x;
            p.y = g.pacman.pos.y+4;
            break;
       	case right:
			p.x = g.pacman.pos.x+4;
            p.y = g.pacman.pos.y;
            break;
       	case left:
            p.x = g.pacman.pos.x-4;
            p.y = g.pacman.pos.y;
            break;
   	}
    p = g.pacman.pos;
    nn = nnPacman(g, g.ghost[1].pos, p);
    printf("%d, %d", nn.x, nn.y);
    char c[2];
    sprintf(c, "%c", g.lab[g.ghost[1].pos.y][g.ghost[1].pos.x]);
    mvprintw(g.ghost[1].pos.y, g.ghost[1].pos.x, c);
    mvchgat(g.ghost[1].pos.y, g.ghost[1].pos.x, 1, A_BOLD, 6, NULL);
    refresh();
    g.ghost[1].pos.y = nn.y;
    g.ghost[1].pos.x = nn.x;
    mvprintw(g.ghost[1].pos.y, g.ghost[1].pos.x, "P");
    mvchgat(g.ghost[1].pos.y, g.ghost[1].pos.x, 1, A_BOLD, 2, NULL);
    refresh();
    usleep(temp);
   	return g;
}

/*-------------------------------------------------------*/
int hipo(int x1, int y1, int x2, int y2) {
	float hipo, dista, distb;
	dista = x1-x2;
	if(dista<0)
		dista *= -1;
	distb = y1-y2;
	if(distb<0)
		distb *= -1;
	hipo = (dista)+(distb);
	return hipo;
}
/* ---------------------------------------------------------------------- */

/**
* @ingroup GroupUnique
* @brief Prints help information and exit
* @details Prints help information (usually called by opt -h)
* @return Void
* @author Ruben Carlo Benante
* @version 20160529.013231
* @date 2016-05-29
*
*/
void help(void) {
	IFDEBUG("help()");
	printf("%s - %s\n", "upecman", "Pacman Ncurses");
	printf("\nUsage: ./%s [-h|-v|-c]\n", "upecman");
	printf("\nOptions:\n");
	printf("\t-h,  --help\n\t\tShow this help.\n");
	printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
	printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
	/* add more options here */
	printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
	printf("\nTodo:\n\tLong options not implemented yet.\n");
	printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
	exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Prints version and copyright information and exit
* @details Prints version and copyright information (usually called by opt -V)
* @return Void
* @author Ruben Carlo Benante
* @version 20160529.013231
* @date 2016-05-29
*
*/
void copyr(void) {
	IFDEBUG("copyr()");
	printf("%s - Version %s\n", "upecman", VERSION);
	printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
	if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
	exit(EXIT_FAILURE);
}
/* ---------------------------------------------------------------------- */

/**
* @ingroup GroupUnique
* @brief This function initializes some operations before start
* @details Details to be written
* @return Void
* @todo Need to implement it. Its empty now.
* @author Ruben Carlo Benante
* @version 20160530.224016
* @date 2016-05-30
*
*/
t_game upecman_init(void) {
	/*IFDEBUG("init()");*/
	/* initialization */
	t_game g;
	int f, y;
	for(y = 0; y < LABL; y++)
	   strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */
	g.pacman.pos.y = 17; /* pacman start position (line) */
	g.pacman.pos.x = 9; /* pacman start position (column) */
	g.pacman.dir = left; /* pacman start direction */
	g.pacman.life = 3; /* 3 lifes */
	g.pacman.score = 0; /* 0 points */
	for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */ {
       	switch(f) {
           	case blinky:
				g.ghost[f].pos.y = 7; /* blinky start position (line) */
				g.ghost[f].pos.x = 9; /* inky start position (column) */
				g.ghost[f].starget.y = 0; /* preferred corner (line) */
				g.ghost[f].starget.x = 19; /* preferred corner (column) */
				break;
           	case pinky:
				g.ghost[f].pos.y = 9; /* inky start position (line) */
				g.ghost[f].pos.x = 10; /* inky start position (column) */
				g.ghost[f].starget.y = 0; /* preferred corner (line) */
				g.ghost[f].starget.x = 0; /* preferred corner (column) */
				break;
           	case inky:
				g.ghost[f].pos.y = 10; /* inky start position (line) */
				g.ghost[f].pos.x = 10; /* inky start position (column) */
				g.ghost[f].starget.y = 22; /* preferred corner (line) */
				g.ghost[f].starget.x = 19; /* preferred corner (column) */
				break;
           	case clyde:
				g.ghost[f].pos.y = 11; /* clyde start position (line) */
				g.ghost[f].pos.x = 10; /* clyde start position (column) */
				g.ghost[f].starget.y = 22; /* preferred corner (line) */
				g.ghost[f].starget.x = 0; /* preferred corner (column) */
				break;
       	}
		g.ghost[f].dir = left; /* start direction and future direction: left */
		g.ghost[f].mode = chase;
   	}
	initscr(); /* start ncurses mode screen */
	cbreak(); /* stop line buffering */
	keypad(stdscr, TRUE); /* grab extended keys */
	noecho(); /* stop echoing chars */
	timeout(0); /* do not wait */
	curs_set(0);
	start_color(); /* initialize the color functionality */
	/* Initialize all the colors */
	init_pair(1, COLOR_RED, COLOR_BLACK); /* Blinky */
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK); /* Pinky */
	init_pair(3, COLOR_CYAN, COLOR_BLACK); /* Inky */
	init_pair(4, COLOR_GREEN, COLOR_BLACK); /* Clyde doesn't have orange :( */
	init_pair(5, COLOR_BLUE, COLOR_BLACK); /* Afraid mode: blue with A_BLINK */
	init_pair(6, COLOR_YELLOW, COLOR_BLACK); /* Pacman */
	return g;
}
/* ---------------------------------------------------------------------- */

/**
* @ingroup GroupUnique
* @brief This function initializes some operations before start
* @details Details to be written
* @return Void
* @todo Need to implement it. Its empty now.
* @author Ruben Carlo Benante
* @version 20160530.224016
* @date 2016-05-30
*
*/
void printlab(t_game g) {
	/*IFDEBUG("printlab()");*/
	int y,i,j,f;
	/*clear(); / * clear the screen */
	for(y = 0; y < LABL; y++)
		printw("%s\n", g.lab[y]);
	for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
		mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f + 1, NULL);
	mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);

	for(i=0;i<LABL;i++) {
       for(j=0;j<LABC;j++) {
           	if(g.lab[i][j]=='#')
            	mvchgat(i,j,1,A_BOLD,5,NULL);
           	if(g.lab[i][j]== 'o')
            	mvchgat(i,j,1,A_BOLD,6,NULL);
           	if(g.lab[i][j]=='.')
            	mvchgat(i,j,1,A_BOLD,6,NULL);
       	}
   	}
   	refresh();
}
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
