#include "BulletClass.h"

BulletClass::BulletClass()
{
	posX = 0;
	posY = 0;
	hp = 0;
	map_nb = 7;
}

BulletClass::BulletClass(int **map, int y, int x)
{
	hp = 1;
	map_nb = 7;
	if (y - 1 != 0 && map[y - 1][x] == 0)
	{
		posY = y - 1;
		posX = x;
		map[posY][posX] = map_nb;
	}
}

BulletClass::~BulletClass()
{

}

BulletClass::BulletClass(const BulletClass &ob)
{
	posX = ob.posX;
	posY = ob.posY;
	hp = ob.hp;
	map_nb = ob.map_nb;
}

BulletClass	&BulletClass::operator=(const BulletClass &ob)
{
	hp = ob.hp;
	posY = ob.posY;
	posX = ob.posX;
	map_nb = ob.map_nb;
	return (*this);
}

void		BulletClass::moveObstacle(int **map)
{
	map[posY][posX] = 0;
	posY--;
	map[posY][posX] = map_nb;
}