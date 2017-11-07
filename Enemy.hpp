/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:33:11 by dzui              #+#    #+#             */
/*   Updated: 2017/11/05 21:33:13 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPP_RUSH_00_ENEMY_H
#define CPP_RUSH_00_ENEMY_H

#include "Obstacle.hpp"


class Enemy : public Obstacle
{
public:
						Enemy();
				 		~Enemy();
						Enemy(const Enemy &ob);
	void				setHP();
	explicit			Enemy(int **map);
	void				generatePosition(int **map);
	Enemy				&operator=(const Enemy &ob);
};


#endif //CPP_RUSH_00_ENEMY_H
