// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   N_vis.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 21:15:36 by yzakharc          #+#    #+#             //
//   Updated: 2017/11/04 21:15:37 by yzakharc         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef N_VIS_HPP
# define N_VIS_HPP

# include <ncurses.h>
# include <iostream>
# include <ctime>
# include <string>
# include "Player.h"

#define H_R 80
#define W_R 80

#define H_M 80
#define W_M 30

class N_vis
{
private:

	WINDOW	*_retro;
	WINDOW	*_menu;
	time_t 	start;
public:

	~N_vis();
	N_vis();
	N_vis(N_vis const &copy);

	void	exit();
	void	init_vis();
	void	create_win();
	void	intro();
	void	menu_bar(WINDOW *menu, int score, int lives, int enemy);
	WINDOW	*getWin() const;
	WINDOW	*getMenu() const;

};

#endif //N_VIS_HPP
