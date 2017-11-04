//
// Created by Dmytro Zui on 11/4/17.
//

#ifndef CPP_RUSH_00_LIGHTOBSTACLE_H
#define CPP_RUSH_00_LIGHTOBSTACLE_H

#include "Obstacle.h"

class LightObstacle : public Obstacle
{
public:
					LightObstacle();
	explicit		LightObstacle(int **map);
					~LightObstacle();
					LightObstacle(const LightObstacle &lo);
	LightObstacle	&operator=(const LightObstacle &lo);
};


#endif //CPP_RUSH_00_LIGHTOBSTACLE_H
