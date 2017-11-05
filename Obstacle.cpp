#include "Obstacle.h"
#include "GameClass.h"

Obstacle::Obstacle()
{
	posX = 0;
	posY = 0;
	hp = 0;
	map_nb = 0;
}

Obstacle::~Obstacle()
{

}

Obstacle::Obstacle(const Obstacle &ob)
{
	posX = ob.posX;
	posY = ob.posY;
	hp = ob.hp;
	map_nb = ob.map_nb;
}

Obstacle	&Obstacle::operator=(const Obstacle &ob)
{
	hp = ob.hp;
	posY = ob.posY;
	posX = ob.posX;
	map_nb = ob.map_nb;
	return (*this);
}

int 	Obstacle::getX()
{
	return (posX);
}

void	Obstacle::setHP()
{
	hp = 0;
}

int 	Obstacle::getY()
{
	return (posY);
}



void	Obstacle::takeDamage(int **map)
{
	hp--;
	if (hp == 0)
		generatePosition(map);

}

void	Obstacle::generatePosition(int **map)
{
	posX = 0;
	posY = 0;
	map[posY][posX] = 0;
}

void	Obstacle::moveObstacle(int **map)
{
	map[posY][posX] = 0;
	posY++;
	if (posY != HEIGHT - 1)
		map[posY][posX] = map_nb;
}