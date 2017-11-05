
#include "Obstacle.h"

#ifndef CPP_RUSH_00_HEAVYOBSTACLE_H
#define CPP_RUSH_00_HEAVYOBSTACLE_H


class HeavyObstacle : public Obstacle
{
public:
					HeavyObstacle();
	explicit		HeavyObstacle(int **map);
					~HeavyObstacle();
					HeavyObstacle(const HeavyObstacle &lo);
	void			setHP();
	void			generatePosition(int **map);
	int				getMap_Nb() const;
					HeavyObstacle	&operator=(const HeavyObstacle &lo);
};


#endif //CPP_RUSH_00_HEAVYOBSTACLE_H
