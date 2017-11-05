#include "LightObstacle.h"
#include "GameClass.h"

LightObstacle::LightObstacle()
{
	posX = 0;
	posY = 0;
	hp = 0;
	map_nb = 2;
}

LightObstacle::~LightObstacle()
{

}

void		LightObstacle::generatePosition(int **map)
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

void		LightObstacle::setHP()
{
	hp = 2;
}

LightObstacle::LightObstacle(int **map)
{
	hp = 1;
	map_nb = 2;
	generatePosition(map);
}

LightObstacle::LightObstacle(const LightObstacle &lo)
{
	hp = lo.hp;
	posY = lo.posY;
	posX = lo.posX;
	map_nb = lo.map_nb;
}

LightObstacle	&LightObstacle::operator=(const LightObstacle &lo)
{
	posX = lo.posX;
	posY = lo.posY;
	map_nb = lo.map_nb;
	hp = lo.hp;
	return (*this);
}
