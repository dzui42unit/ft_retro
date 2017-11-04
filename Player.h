
#ifndef CPP_RUSH_00_PLAYER_H
#define CPP_RUSH_00_PLAYER_H

#include <ncurses.h>
#include <curses.h>
#include <ctime>

class 	Player
{
private:
	int 	posX;
	int 	posY;
	int 	lives;
public:
			Player();
			~Player();
			Player(const Player &pl);
	Player	&operator=(const Player &pl);
	int 	getLives() const;
	void	decrLives(int **map);
	int 	getX() const;
	int 	getY() const;
	void	movePlayer(WINDOW *win, int **map);
	int 	checkMove(int i, int j);
	void 	resetPlayer(int **map);
};


#endif //CPP_RUSH_00_PLAYER_H
