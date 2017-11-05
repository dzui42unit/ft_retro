
#include "GameClass.h"
#include <unistd.h>

void	GameClass::runGame()
{
	clock_t st;
	clock_t e;
	useconds_t delay;

	wrefresh(win);
	nodelay(win, 1);
	while (pl->getLives() > 0)
	{
		st = clock();
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (map[i][j] == 5)
					mvwprintw(win, i, j, "%c", '^');
				else if (map[i][j] == 2)
					mvwprintw(win, i, j, "%c", '@');
				else if (map[i][j] == 7)
					mvwprintw(win, i, j, "%c", '|');
				else
					map[i][j] != 1 ? mvwprintw(win, i, j, " ") : 0;
			}
		}
		nv->menu_bar(menu, score, pl->getLives(), kill);
		moveObjects();
		wrefresh(win);
		cycles++;
		e = static_cast<clock_t>((st - clock()) / (double) CLOCKS_PER_SEC);
		delay = static_cast<useconds_t>(e) / 100000;
		usleep(delay);
	}
	nv->exit();
}

void	GameClass::checkIntersect()
{
	for (int i = 0; i < OBST_NB; i++)
	{
		if (lo[i]->getX() == pl->getX() && lo[i]->getY() == pl->getY())
		{
			pl->decrLives(map);
			lo[i]->takeDamage(map);
		}
		for (int j = 0; j < BULL_NB; j++)
		{
			if (bul[j] && (lo[i]->getX() == bul[j]->getX() && lo[i]->getY() == bul[j]->getY()))
			{
				map[bul[j]->getY()][bul[j]->getX()] = 0;
				map[lo[i]->getY()][lo[i]->getX()] = 0;
				lo[i]->generatePosition(map);
				bul[j]->generatePosition(map, pl->getY(), pl->getX());
			}
		}
	}
}

void	GameClass::moveObjects()
{
	for (int i = 0; i < BULL_NB; i++)
	{
		if (!bul[i] && pl->getY() > 2  && ((cycles % ((i + 1) * 10) == 0))
			&& map[pl->getY() - 1][pl->getX()] == 0)
			bul[i] = new BulletClass(map, pl->getY(), pl->getX());
	}
	for (int i = 0; i < OBST_NB; i++)
	{
		if (lo[i]->getY() == HEIGHT - 1)
		{
			map[lo[i]->getY()][lo[i]->getX()] = 1;
			lo[i]->generatePosition(map);
		}
	}
	for (int i = 0; i < BULL_NB; i++)
	{
		if (bul[i])
		{
			bul[i]->moveObstacle(map);
			if (bul[i]->getY() == 0 )
				bul[i]->generatePosition(map, pl->getY(), pl->getX());
		}
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
	nv = new N_vis();
	nv->init_vis();
	win = nv->getWin();
	menu = nv->getMenu();
	cycles = 0;
	std::srand(time(0));
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
	kill = 0;
	score = 0;
	map[pl->getY()][pl->getX()] = 5;
	lo = new LightObstacle *[OBST_NB];
	bul = new BulletClass *[BULL_NB];
	for (int i = 0; i < OBST_NB; i++)
		lo[i] = new LightObstacle(map);
	for (int i = 0; i < BULL_NB; i++)
		bul[i] = 0;
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