#include "Player.h"
#include "GameClass.h"

void	Player::resetPlayer(int **map)
{
	map[posY][posX] = 0;
	posY = HEIGHT - 2;
	posX = WIDTH / 2;
	map[posY][posX] = 5;
	lives = LIVES;
}

Player::Player(const Player &pl)
{
	posX = pl.posX;
	posY = pl.posY;
	lives = pl.lives;
	map_nb = pl.map_nb;
}

Player	&Player::operator=(const Player &pl)
{
	lives = pl.lives;
	map_nb = pl.map_nb;
	posX = pl.posX;
	posY = pl.posY;
	return (*this);
}

Player::Player()
{
	lives = LIVES;
	posY = HEIGHT - 2;
	posX = WIDTH / 2;
	map_nb = 5;
}

Player::~Player()
{

}

int 	Player::getX() const
{
	return (posX);
}

int 	Player::getY() const
{
	return (posY);
}

int 	Player::checkMove(int i, int j)
{
	if (i == 0 || i == HEIGHT - 1
			|| j == WIDTH - 1 || j == 0)
		return (0);
	return (1);
}

void	Player::movePlayer(WINDOW *win, int **map)
{
	int ch;

	ch = wgetch(win);

	if (ch == 'w')
	{
		if (checkMove(posY - 1, posX)
				&& map[posY - 1][posX] != 7)
		{
			map[posY][posX] = 0;
			posY--;
			map[posY][posX] = map_nb;

		}
	}
	if (ch == 'a')
	{
		if (checkMove(posY, posX - 1)
			&& map[posY][posX - 1] != 7)
		{
			map[posY][posX] = 0;
			posX--;
			map[posY][posX] = map_nb;
		}
	}
	if (ch == 's')
	{
		if (checkMove(posY + 1, posX)
			&& map[posY + 1][posX] != 7)
		{
			map[posY][posX] = 0;
			posY++;
			map[posY][posX] = map_nb;
		}
	}
	if (ch == 'd')
	{
		if (checkMove(posY, posX + 1)
			&& map[posY][posX + 1] != 7)
		{
			map[posY][posX] = 0;
			posX++;
			map[posY][posX] = map_nb;
		}
	}
	if (ch == 'r')
	{
		resetPlayer(map);
	}
}

int 	Player::getLives() const
{
	return (lives);
}

void	Player::decrLives(int **map)
{
	map[posY][posX] = 0;
	lives--;
	posY = HEIGHT - 2;
	posX = WIDTH / 2;
	map[posY][posX] = map_nb;
}