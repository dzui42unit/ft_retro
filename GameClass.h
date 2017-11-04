
#ifndef CPP_RUSH_00_GAMECLASS_H
#define CPP_RUSH_00_GAMECLASS_H

#define	WIDTH	80
#define	HEIGHT  80
#define OBST_NB 10
#define BULL_NB 25
#define LIVES	3

#include <iostream>
#include <string>
#include <iomanip>
#include <ncurses.h>
#include <curses.h>

#include "Player.h"
#include "LightObstacle.h"
#include "BulletClass.h"

class 			GameClass
{
private:
	int 				**map;
	Player				*pl;
	LightObstacle		**lo;
	WINDOW				*win;
	BulletClass			**bul;
	unsigned long long 	cycles;
public:
				GameClass();
				~GameClass();
				GameClass(const GameClass &gc);
	GameClass   &operator=(const GameClass &gc);
	void		moveObjects();
	void 		printMap() const;
	void		runGame();
	void		checkIntersect();
};


#endif //CPP_RUSH_00_GAMECLASS_H
