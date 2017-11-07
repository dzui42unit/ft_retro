/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:30:58 by dzui              #+#    #+#             */
/*   Updated: 2017/11/05 21:32:38 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"
#include "GameClass.hpp"

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

int 	Obstacle::getHP() const
{
	return (hp);
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



void	Obstacle::takeDamage()
{
	hp--;
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
