/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeavyObstacle.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:36:20 by dzui              #+#    #+#             */
/*   Updated: 2017/11/05 21:36:22 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Obstacle.hpp"

#ifndef CPP_RUSH_00_HEAVYOBSTACLE_H
#define CPP_RUSH_00_HEAVYOBSTACLE_H


class HeavyObstacle : public Obstacle
{
public:
					HeavyObstacle();
	explicit		HeavyObstacle(int **map);
					~HeavyObstacle();
					HeavyObstacle(const HeavyObstacle &lo);
	void			setHP();
	void			generatePosition(int **map);
	int				getMap_Nb() const;
					HeavyObstacle	&operator=(const HeavyObstacle &lo);
};


#endif //CPP_RUSH_00_HEAVYOBSTACLE_H
