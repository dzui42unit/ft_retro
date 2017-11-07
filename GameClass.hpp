/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameClass.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:30:15 by dzui              #+#    #+#             */
/*   Updated: 2017/11/05 21:30:19 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_RUSH_00_GAMECLASS_H
#define CPP_RUSH_00_GAMECLASS_H

#define	WIDTH	80
#define	HEIGHT  80
#define OBST_NB 10
#define BULL_NB 8
#define LIVES	3
#define PL_CH	'A'
#define	LO_CH	'*'
#define BUL_CH	'|'
#define HO_CH	'W'
#define EN_CH 	'V'
#define	EN_BUL	'!'

#include <iostream>
#include <string>
#include <iomanip>
#include <ncurses.h>
#include <curses.h>

#include "Player.hpp"
#include "LightObstacle.hpp"
#include "HeavyObstacle.hpp"
#include "N_vis.hpp"
#include "BulletClass.hpp"
#include "Enemy.hpp"
#include "EnemyBullet.hpp"

class 			GameClass
{
private:
	int 				**map;
	Player				*pl;
	LightObstacle		**lo;
	HeavyObstacle		**ho;
	N_vis				*nv;
	WINDOW				*win;
	WINDOW				*menu;
	BulletClass			**bul;
	EnemyBullet			**en_bul;
	Enemy				**l_enem;
	unsigned long 		score;
	unsigned long		kill;
	unsigned long long 	cycles;
public:
				GameClass();
				~GameClass();
				GameClass(const GameClass &gc);
	GameClass   &operator=(const GameClass &gc);
	void		moveObjects();
	void		runGame();
	void		checkIntersect();
};


#endif //CPP_RUSH_00_GAMECLASS_H
