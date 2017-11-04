#include "Obstacle.h"

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

int 	Obstacle::getY()
{
	return (posY);
}

void	Obstacle::moveObstacle(int **map)
{
	map[posY][posX] = 0;
	posY++;
	map[posY][posX] = map_nb;
}