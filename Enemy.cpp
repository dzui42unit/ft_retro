/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:33:03 by dzui              #+#    #+#             */
/*   Updated: 2017/11/05 21:33:04 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Enemy.hpp"
#include "GameClass.hpp"

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
	posY = 2 + std::rand() % HEIGHT / 2;
	posX = 2 + std::rand() % (WIDTH - 2);
	while (map[posY][posX] != 0)
	{
		posY = 2 + std::rand() % HEIGHT / 2;
		posX = 2 + std::rand() % (WIDTH - 2);
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
