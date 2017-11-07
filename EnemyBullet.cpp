/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBullet.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:35:25 by dzui              #+#    #+#             */
/*   Updated: 2017/11/05 21:35:27 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyBullet.hpp"
#include "GameClass.hpp"

EnemyBullet::EnemyBullet()
{
	posX = 0;
	posY = 0;
	hp = 0;
	map_nb = 6;
}

EnemyBullet::EnemyBullet(int **map, int y, int x)
{
	hp = 1;
	map_nb = 6;
	if (y + 1 != HEIGHT - 1)
	{
		posY = y + 1;
		posX = x;
		map[posY][posX] = map_nb;
	}
}

EnemyBullet::~EnemyBullet()
{

}

EnemyBullet::EnemyBullet(const EnemyBullet &ob)
{
	posX = ob.posX;
	posY = ob.posY;
	hp = ob.hp;
	map_nb = ob.map_nb;
}

EnemyBullet	&EnemyBullet::operator=(const EnemyBullet &ob)
{
	hp = ob.hp;
	posY = ob.posY;
	posX = ob.posX;
	map_nb = ob.map_nb;
	return (*this);
}

void		EnemyBullet::moveObstacle(int **map)
{
	map[posY][posX] = 0;
	posY++;
	map[posY][posX] = map_nb;
}

void		EnemyBullet::generatePosition(int **map, int y, int x)
{
	if (y < HEIGHT - 3)
	{
		map[posY][posX] = 0;
		posY = y + 1;
		posX = x;
		map[posY][posX] = map_nb;
	}
	else
	{
		map[posY][posX] = 0;
		posY = HEIGHT - 1;
		posX = x;
		map[posY][posX] = 1;
	}
	if (posY == HEIGHT - 1)
		map[posY][posX] = 1;
}

void		EnemyBullet::setHP()
{
	hp = 1;
}
