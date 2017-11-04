

#ifndef CPP_RUSH_00_BULLETCLASS_H
#define CPP_RUSH_00_BULLETCLASS_H


#include "Obstacle.h"

class BulletClass : public Obstacle
{
public:
				BulletClass(int **map, int y, int x);
				BulletClass();
			 	~BulletClass();
				BulletClass(const BulletClass &bul);
	BulletClass	&operator=(const BulletClass &bul);
	void		moveObstacle(int **map);
};


#endif //CPP_RUSH_00_BULLETCLASS_H
