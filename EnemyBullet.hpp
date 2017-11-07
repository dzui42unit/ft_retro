/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBullet.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:35:44 by dzui              #+#    #+#             */
/*   Updated: 2017/11/05 21:35:45 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPP_RUSH_00_ENEMYBULLET_H
#define CPP_RUSH_00_ENEMYBULLET_H

#include "Obstacle.hpp"

class EnemyBullet : public Obstacle
{
public:
				EnemyBullet(int **map, int y, int x);
				EnemyBullet();
				~EnemyBullet();
				EnemyBullet(const EnemyBullet &bul);
				EnemyBullet	&operator=(const EnemyBullet &bul);
	void		moveObstacle(int **map);
	void		generatePosition(int **map, int y, int x);
	void		setHP();
};


#endif //CPP_RUSH_00_ENEMYBULLET_H
