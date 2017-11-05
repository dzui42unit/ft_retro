
#ifndef CPP_RUSH_00_GAMECLASS_H
#define CPP_RUSH_00_GAMECLASS_H

#define	WIDTH	80
#define	HEIGHT  80
#define OBST_NB 10
#define BULL_NB 8
#define LIVES	3
#define PL_CH	'^'
#define	LO_CH	'*'
#define BUL_CH	'|'
#define HO_CH	'#'
#define EN_CH 	'$'

#include <iostream>
#include <string>
#include <iomanip>
#include <ncurses.h>
#include <curses.h>

#include "Player.h"
#include "LightObstacle.h"
#include "HeavyObstacle.h"
#include "N_vis.hpp"
#include "BulletClass.h"
#include "Enemy.h"

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
