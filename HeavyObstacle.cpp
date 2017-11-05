#include "HeavyObstacle.h"
#include "GameClass.h"

HeavyObstacle::HeavyObstacle()
{
	posX = 0;
	posY = 0;
	hp = 0;
	map_nb = 3;
}

HeavyObstacle::~HeavyObstacle()
{

}

void		HeavyObstacle::generatePosition(int **map)
{
	posY = 1 + std::rand() % HEIGHT / 8;
	posX = 1 + std::rand() % WIDTH;
	while (map[posY][posX] != 0)
	{
		posY = 1 + std::rand() % HEIGHT / 8;
		posX = 1 + std::rand() % WIDTH;
	}
	map[posY][posX] = map_nb;
	setHP();
}

void		HeavyObstacle::setHP()
{
	hp = 2;
}

int 	HeavyObstacle::getMap_Nb() const
{
	return (map_nb);
}

HeavyObstacle::HeavyObstacle(int **map)
{
	hp = 2;
	map_nb = 3;
	generatePosition(map);
}

HeavyObstacle::HeavyObstacle(const HeavyObstacle &ho)
{
	hp = ho.hp;
	posY = ho.posY;
	posX = ho.posX;
	map_nb = ho.map_nb;
}

HeavyObstacle	&HeavyObstacle::operator=(const HeavyObstacle &ho)
{
	posX = ho.posX;
	posY = ho.posY;
	map_nb = ho.map_nb;
	hp = ho.hp;
	return (*this);
}
