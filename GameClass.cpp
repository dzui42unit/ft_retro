
#include "GameClass.h"
#include "Player.h"
#include <unistd.h>

void	GameClass::runGame()
{
	while (pl->getLives() > 0)
	{
		usleep(32000);
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (map[i][j] == 1)
					mvprintw(i, j, "%c", '*');
				else if (map[i][j] == 5)
					mvprintw(i, j, "%c", '^');
				else if (map[i][j] == 2)
					mvprintw(i, j, "%c", '@');
				else if (map[i][j] == 7)
					mvprintw(i, j, "%c", '|');
				else
					mvprintw(i, j, " ");
			}
		}
		moveObjects();
		refresh();
		cycles++;
	}
	endwin();
}

void	GameClass::checkIntersect()
{
	for (int i = 0; i < OBST_NB; i++)
	{
		if (lo[i]->getX() == pl->getX() && lo[i]->getY() == pl->getY())
		{
			pl->decrLives(map);
			delete lo[i];
			lo[i] = new LightObstacle(map);
		}
		for (int j = 0; j < BULL_NB; j++)
		{
			if (bul[j] && (lo[i]->getX() == bul[j]->getX() && lo[i]->getY() == bul[j]->getY()))
			{
				map[bul[j]->getY()][bul[j]->getX()] = 0;
				map[lo[i]->getY()][lo[i]->getX()] = 0;
				delete lo[i];
				lo[i] = new LightObstacle(map);
				delete bul[j];
				bul[j] = 0;
			}
		}
	}
}

void	GameClass::moveObjects()
{
	for (int i = 0; i < BULL_NB; i++)
	{
		if (!bul[i] && pl->getY() > 2
			&& ((cycles % ((i + 1) * 10) == 0))
			&& map[pl->getY() - 1][pl->getX()] == 0)
			bul[i] = new BulletClass(map, pl->getY(), pl->getX());
		if (bul[i] && bul[i]->getY() == 0)
		{
			map[bul[i]->getY()][bul[i]->getX()] = 1;
			delete bul[i];
			if (pl->getY() > 2 && map[pl->getY() - 1][pl->getX()] == 0
				&& ((cycles % ((i + 1) * 10) == 0)))
				bul[i] = new BulletClass(map, pl->getY(), pl->getX());
			else
				bul[i] = 0;
		}
	}
	for (int i = 0; i < OBST_NB; i++)
	{
		if (lo[i]->getY() == HEIGHT - 1)
		{
			map[lo[i]->getY()][lo[i]->getX()] = 1;
			delete lo[i];
			lo[i] = new LightObstacle(map);
		}
	}
	for (int i = 0; i < BULL_NB; i++)
	{
		if (bul[i])
			bul[i]->moveObstacle(map);
	}
	checkIntersect();
	for(int i = 0; i < OBST_NB; i++)
		lo[i]->moveObstacle(map);
	checkIntersect();
	pl->movePlayer(win, map);
	checkIntersect();
}

GameClass::GameClass()
{
	cycles = 0;
	std::srand(time(0));
	win = initscr();
	noecho();
	refresh();
	keypad(win, true);
	curs_set(0);
	pl = new Player;
	nodelay(stdscr, true);
	map = new int *[HEIGHT];
	for (int i = 0; i < HEIGHT; i++)
	{
		map[i] = new int[WIDTH];
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == 0 || i == HEIGHT - 1
				|| j == 0 || j == WIDTH - 1)
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
	map[pl->getY()][pl->getX()] = 5;
	lo = new LightObstacle *[OBST_NB];
	bul = new BulletClass *[BULL_NB];
	for (int i = 0; i < OBST_NB; i++)
		lo[i] = new LightObstacle(map);
	for (int i = 0; i < BULL_NB; i++)
		bul[i] = 0;
}

void 	GameClass::printMap() const
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

GameClass::~GameClass()
{
	for (int i = 0; i < HEIGHT; i++)
		delete map[i];
	delete []map;
	delete pl;
}

GameClass::GameClass(const GameClass &gc)
{
	pl = new Player;
	win = gc.win;
	*pl = *(gc.pl);
//	*lo = *(gc.lo);
	map = new int *[HEIGHT];
	for (int i = 0; i < HEIGHT; i++)
	{
		map[i] = new int[WIDTH];
		for (int j = 0; j < WIDTH; j++)
			map[i][j] = gc.map[i][j];
	}
}

GameClass	&GameClass::operator=(const GameClass &gc)
{
	*pl = *(gc.pl);
	win = gc.win;
//	*lo = *(gc.lo);
	for (int i = 0; i < HEIGHT; i++)
	{
		map[i] = new int[WIDTH];
		for (int j = 0; j < WIDTH; j++)
			map[i][j] = gc.map[i][j];
	}
	return (*this);
}