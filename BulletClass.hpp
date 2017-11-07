/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:33:35 by dzui              #+#    #+#             */
/*   Updated: 2017/11/05 21:34:54 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPP_RUSH_00_BULLETCLASS_H
#define CPP_RUSH_00_BULLETCLASS_H


#include "Obstacle.hpp"

class BulletClass : public Obstacle
{
public:
				BulletClass(int **map, int y, int x);
				BulletClass();
			 	~BulletClass();
				BulletClass(const BulletClass &bul);
	BulletClass	&operator=(const BulletClass &bul);
	void		moveObstacle(int **map);
	void		generatePosition(int **map, int y, int x);
	void		setHP();
};


#endif //CPP_RUSH_00_BULLETCLASS_H
