/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LightObstacle.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:34:05 by dzui              #+#    #+#             */
/*   Updated: 2017/11/05 21:34:07 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CPP_RUSH_00_LIGHTOBSTACLE_H
#define CPP_RUSH_00_LIGHTOBSTACLE_H

#include "Obstacle.hpp"

class LightObstacle : public Obstacle
{
public:
					LightObstacle();
	explicit		LightObstacle(int **map);
					~LightObstacle();
					LightObstacle(const LightObstacle &lo);
	void			setHP();
	void			generatePosition(int **map);
	LightObstacle	&operator=(const LightObstacle &lo);
};


#endif //CPP_RUSH_00_LIGHTOBSTACLE_H
