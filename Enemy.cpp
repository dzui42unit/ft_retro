#include "Enemy.h"
#include "GameClass.h"

Enemy::Enemy()
{
	posX = 0;
	posY = 0;
	hp = 0;
	map_nb = 0;
}

Enemy::~Enemy()
{

}

Enemy::Enemy(int **map)
{
	hp = 1;
	map_nb = 4;
	generatePosition(map);
}

void		Enemy::setHP()
{
	hp = 1;
}

void		Enemy::generatePosition(int **map)
{
	posY = 1 + std::rand() % HEIGHT / 15;
	posX = 1 + std::rand() % WIDTH;
	while (map[posY][posX] != 0)
	{
		posY = 1 + std::rand() % HEIGHT / 15;
		posX = 1 + std::rand() % WIDTH;
	}
	map[posY][posX] = map_nb;
	setHP();
}

Enemy::Enemy(const Enemy &ob)
{
	posX = ob.posX;
	posY = ob.posY;
	hp = ob.hp;
	map_nb = ob.map_nb;
}

Enemy	&Enemy::operator=(const Enemy &ob)
{
	hp = ob.hp;
	posY = ob.posY;
	posX = ob.posX;
	map_nb = ob.map_nb;
	return (*this);
}