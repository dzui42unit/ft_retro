/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:32:47 by dzui              #+#    #+#             */
/*   Updated: 2017/11/05 21:32:53 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_RUSH_00_OBSTACLE_H
#define CPP_RUSH_00_OBSTACLE_H

#include <cstdlib>
#include <ctime>

class 			Obstacle
{
protected:
	int 		posX;
	int 		posY;
	int 		hp;
	int 		map_nb;
public:
	int 				getX();
	int 				getY();
	virtual void		moveObstacle(int **map);
						Obstacle();
	virtual		 		~Obstacle();
						Obstacle(const Obstacle &ob);
	void 				takeDamage();
	virtual void		generatePosition(int **map);
	int 				getHP() const;
	virtual void		setHP();
	Obstacle			&operator=(const Obstacle &ob);
};


#endif //CPP_RUSH_00_OBSTACLE_H
