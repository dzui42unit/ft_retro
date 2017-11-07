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
#include "GameClass.hpp"

N_vis::N_vis()
{
}

N_vis::~N_vis()
{
}

void	N_vis::exit_nv()
{
	end();
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
	raw();
	cbreak();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
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
	intro(_big);
	wrefresh(_retro);
	wrefresh(_menu);
}

void	N_vis::intro(WINDOW *big)
{
	big = newwin(W_R, W_R + W_M, 0, 0);
	std::string		intro;
	std::string		file_data;
	int 			y = H_R / 3;
	int 			x = 18;

	wbkgd(big, COLOR_PAIR(3) | A_BOLD);
	std::ifstream	file("text_intro");
	if (file.is_open())
	{
		while (getline(file, file_data))
			intro += (file_data + '\n');
	}
	else
	{
		std::cout << "Could not open a file.\n";
		exit(0);
	}
	for (int i = 0; i < intro.size(); i++)
	{
		if (intro[i] == '\n')
		{
			y++;
			x = 18;
			wrefresh(big);
			napms(100);
		}
		mvwaddch(big, y, x++, intro[i]);
	}
	napms(1500);
	start = std::time(0);
}

void	N_vis::end()
{
	WINDOW *old;
	old = newwin(W_R, W_R + W_M, 0, 0);
	std::string end;
	std::string file_data;
	int 			y = H_R / 3;
	int 			x = W_R / 4;
	int 			c = -1;

	wattron(old, COLOR_PAIR(3));
	wbkgd(old, COLOR_PAIR(3) | A_BOLD | A_BLINK);
	wrefresh(old);
	std::ifstream	file("text_end");
	if (file.is_open())
	{
		while (getline(file, file_data))
			end += (file_data + '\n');
	}
	else
	{
		std::cout << "Could not open a file.\n";
		exit(0);
	}
	for (int i = 0; i < end.size(); i++)
	{
		if (end[i] == '\n')
		{
			y++;
			x = W_R / 4;
			wrefresh(old);
		}
		mvwaddch(old, y, x++, end[i]);
	}
	while (c != 'q')
	{
		c = (wgetch(old));
	}
}

void	N_vis::menu_bar(WINDOW *menu, int score, int lives, int enemy)
{
	wattrset(menu, COLOR_PAIR(1) | A_BOLD);
	mvwprintw(_menu,5, 5, "TIME: %02d : %02d", (time(0) - start) / 60, (time(0) - start) % 60);
	mvwprintw(menu, 10 , 5, "STORE: %d", score);
	mvwprintw(menu, 15 , 5, "KILL ENEMY: %d", enemy);
	mvwprintw(menu, 20 , 5, "LIVE: %d", lives);
	wrefresh(menu);
}

N_vis::N_vis(N_vis const &copy)
{
	_retro = copy._retro;
	_menu = copy._menu;
	_big = copy._big;
	start = copy.start;
}

N_vis &N_vis::operator=(const N_vis &copy)
{
	_retro = copy._retro;
	_menu = copy._menu;
	_big = copy._big;
	start = copy.start;
	return (*this);
}
