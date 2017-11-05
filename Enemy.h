#ifndef CPP_RUSH_00_ENEMY_H
#define CPP_RUSH_00_ENEMY_H

#include "Obstacle.h"


class Enemy : public Obstacle
{
public:
						Enemy();
				 		~Enemy();
						Enemy(const Enemy &ob);
	void				setHP();
	explicit			Enemy(int **map);
	void				generatePosition(int **map);
	Enemy				&operator=(const Enemy &ob);
};


#endif //CPP_RUSH_00_ENEMY_H
