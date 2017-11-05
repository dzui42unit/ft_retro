// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   N_vis.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 21:15:44 by yzakharc          #+#    #+#             //
//   Updated: 2017/11/04 21:15:45 by yzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "N_vis.hpp"
#include "GameClass.h"

N_vis::N_vis()
{
}

N_vis::~N_vis()
{
}

void	N_vis::exit()
{
	endwin();
}

WINDOW	*N_vis::getWin() const
{
	return (_retro);
}

WINDOW	*N_vis::getMenu() const
{
	return (_menu);
}

void	N_vis::init_vis()
{
	initscr();
	signal (SIGWINCH, NULL);
	_retro = newwin(W_R, H_R, 0, 0);
	_menu = newwin(H_M, W_M, 0, H_M);
	cbreak();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	create_win();
}

void	N_vis::create_win()
{
	_retro = newwin(W_R, H_R, 0, 0);
	_menu = newwin(H_M, W_M, 0, H_M);
	keypad(_retro, true);
	nodelay(_menu, true);
	for (int i = 0; i < W_R ; ++i)
	{
		wattron(_retro, COLOR_PAIR(1));
		wattron(_menu, COLOR_PAIR(1));
		mvwaddch(_retro, 0, i, ' ' | A_STANDOUT);
		mvwaddch(_retro, i, 0, ' ' | A_STANDOUT);
		mvwaddch(_retro, i, 79, ' ' | A_STANDOUT);
		mvwaddch(_retro, 79, i, ' ' | A_STANDOUT);
		mvwaddch(_menu, i, 0, ' ' | A_STANDOUT);
		mvwaddch(_menu, i, 29, ' ' | A_STANDOUT);
		mvwaddch(_menu, 0, i, ' ' | A_STANDOUT);
		mvwaddch(_menu, 79, i, ' ' | A_STANDOUT);
	}
//	intro();
	wrefresh(_retro);
	wrefresh(_menu);
}

void	N_vis::intro()
{
	WINDOW *big;

	big = newwin(W_R, W_R + W_M, 0, 0);
	std::string	st;
	int 			y = H_R / 3;
	int 			x = W_R / 4;

	wattron(big, COLOR_PAIR(3));
	wbkgd(big, COLOR_PAIR(3));
	st = "\n"
			"      ___                       ___           ___                 \n"
			"     /  /\\          ___        /  /\\         /  /\\          ___   \n"
			"    /  /:/_        /  /\\      /  /::\\       /  /::\\        /  /\\  \n"
			"   /  /:/ /\\      /  /:/     /  /:/\\:\\     /  /:/\\:\\      /  /:/  \n"
			"  /  /:/ /::\\    /  /:/     /  /:/~/::\\   /  /:/~/:/     /  /:/   \n"
			" /__/:/ /:/\\:\\  /  /::\\    /__/:/ /:/\\:\\ /__/:/ /:/___  /  /::\\   \n"
			" \\  \\:\\/:/~/:/ /__/:/\\:\\   \\  \\:\\/:/__\\/ \\  \\:\\/:::::/ /__/:/\\:\\  \n"
			"  \\  \\::/ /:/  \\__\\/  \\:\\   \\  \\::/       \\  \\::/~~~~  \\__\\/  \\:\\ \n"
			"   \\__\\/ /:/        \\  \\:\\   \\  \\:\\        \\  \\:\\           \\  \\:\\\n"
			"     /__/:/          \\__\\/    \\  \\:\\        \\  \\:\\           \\__\\/\n"
			"     \\__\\/                     \\__\\/         \\__\\/                \n"
			"      ___           ___           ___           ___               \n"
			"     /  /\\         /  /\\         /__/\\         /  /\\              \n"
			"    /  /:/_       /  /::\\       |  |::\\       /  /:/_             \n"
			"   /  /:/ /\\     /  /:/\\:\\      |  |:|:\\     /  /:/ /\\            \n"
			"  /  /:/_/::\\   /  /:/~/::\\   __|__|:|\\:\\   /  /:/ /:/_           \n"
			" /__/:/__\\/\\:\\ /__/:/ /:/\\:\\ /__/::::| \\:\\ /__/:/ /:/ /\\          \n"
			" \\  \\:\\ /~~/:/ \\  \\:\\/:/__\\/ \\  \\:\\~~\\__\\/ \\  \\:\\/:/ /:/          \n"
			"  \\  \\:\\  /:/   \\  \\::/       \\  \\:\\        \\  \\::/ /:/           \n"
			"   \\  \\:\\/:/     \\  \\:\\        \\  \\:\\        \\  \\:\\/:/            \n"
			"    \\  \\::/       \\  \\:\\        \\  \\:\\        \\  \\::/             \n"
			"     \\__\\/         \\__\\/         \\__\\/         \\__\\/              \n";

	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == '\n')
		{
			y++;
			x = W_R / 4;
			wrefresh(big);
			napms(100);
		}
		mvwaddch(big, y, x++, st[i]);
	}
	napms(1500);
	start = std::time(0);
}

void	N_vis::menu_bar(WINDOW *menu, int score, int lives, int enemy)
{
	wattrset(menu, COLOR_PAIR(1) | A_BOLD);
	mvwprintw(_menu,5, 5, "TIME: %02d : %02d", (time(0) - start) / 60, (time(0) - start) % 60);
	mvwprintw(menu, 10 , 5, "SCORE: %d", score);
	mvwprintw(menu, 15 , 5, "KILL ENEMY: %d", enemy);
	mvwprintw(menu, 20 , 5, "LIVE: %d", lives);
	wrefresh(menu);
}
