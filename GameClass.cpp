
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
					mvwprintw(win, i, j, "%c", PL_CH);
				else if (map[i][j] == 2)
					mvwprintw(win, i, j, "%c", LO_CH);
				else if (map[i][j] == 7)
					mvwprintw(win, i, j, "%c", BUL_CH);
				else if (map[i][j] == 3)
					mvwprintw(win, i, j, "%c", HO_CH);
				else if (map[i][j] == 4)
					mvwprintw(win, i, j, "%c", EN_CH);
				else
					map[i][j] != 1 ? mvwprintw(win, i, j, " ") : 0;
			}
		}
		nv->menu_bar(menu, score, pl->getLives(), kill);
		moveObjects();
		wrefresh(win);
		cycles++;
		e = static_cast<clock_t>((st - clock()) / (double) CLOCKS_PER_SEC);
		delay = static_cast<useconds_t>(e) / 110000;
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
			lo[i]->generatePosition(map);
		}
//		if (ho[i]->getX() == pl->getX() && ho[i]->getY() == pl->getY())
//		{
//			pl->decrLives(map);
//			ho[i]->generatePosition(map);
//		}
		for (int j = 0; j < BULL_NB; j++)
		{
			if (bul[j] && bul[j]->getX() == l_enem[i]->getX() && bul[j]->getY() == l_enem[i]->getY())
			{
				bul[j]->generatePosition(map, pl->getY(), pl->getX());
				l_enem[i]->takeDamage();
				if (l_enem[i]->getHP() == 0)
				{
					map[l_enem[i]->getY()][l_enem[i]->getX()] = 0;
					l_enem[i]->generatePosition(map);
				}
			}
			if (bul[j] && (lo[i]->getX() == bul[j]->getX() && lo[i]->getY() == bul[j]->getY()))
			{
				map[bul[j]->getY()][bul[j]->getX()] = 0;
				map[lo[i]->getY()][lo[i]->getX()] = 0;
				lo[i]->generatePosition(map);
				bul[j]->generatePosition(map, pl->getY(), pl->getX());
			}
//			if (bul[j] && (ho[i]->getX() == bul[j]->getX() && ho[i]->getY() == bul[j]->getY()))
//			{
//				map[bul[j]->getY()][bul[j]->getX()] = 0;
//				bul[j]->generatePosition(map, pl->getY(), pl->getX());
//				ho[i]->takeDamage();
//				if (ho[i]->getHP() == 0)
//				{
//					ho[i]->generatePosition(map);
//					score += 20;
//				}
//				else
//					map[ho[i]->getY()][ho[i]->getX()] = ho[i]->getMap_Nb();
//			}
		}
//		for (int j = 0; j < OBST_NB; j++)
//		{
//			if (lo[i]->getX() == l_enem[j]->getX() && lo[i]->getY() == l_enem[j]->getY())
//			{
//				lo[i]->generatePosition(map);
//				l_enem[j]->takeDamage();
//				if (l_enem[j]->getHP() == 0)
//				{
//					map[l_enem[j]->getY()][l_enem[j]->getX()] = 0;
//					l_enem[j]->generatePosition(map);
//				}
//			}
//			if (ho[i]->getX() == l_enem[j]->getX() && ho[i]->getY() == l_enem[j]->getY())
//			{
//				ho[i]->generatePosition(map);
//				l_enem[j]->takeDamage();
//				if (l_enem[j]->getHP() == 0)
//				{
//					map[l_enem[j]->getY()][l_enem[j]->getX()] = 0;
//					l_enem[j]->generatePosition(map);
//				}
//			}
//		}
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
		if (l_enem[i]->getY() == HEIGHT - 1)
		{
			map[l_enem[i]->getY()][l_enem[i]->getX()] = 1;
			l_enem[i]->generatePosition(map);
		}
		if (lo[i]->getY() == HEIGHT - 1)
		{
			map[lo[i]->getY()][lo[i]->getX()] = 1;
			lo[i]->generatePosition(map);
		}
//		if (ho[i]->getY() == HEIGHT - 1)
//		{
//			map[ho[i]->getY()][ho[i]->getX()] = 1;
//			ho[i]->generatePosition(map);
//		}
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
	{
		lo[i]->moveObstacle(map);
		checkIntersect();
//		ho[i]->moveObstacle(map);
		if (cycles % 10 == 0)
		{
			l_enem[i]->moveObstacle(map);
			checkIntersect();
		}
	}
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
	l_enem = new Enemy *[OBST_NB];
	lo = new LightObstacle *[OBST_NB];
	bul = new BulletClass *[BULL_NB];
//	ho = new HeavyObstacle *[OBST_NB];
	for (int i = 0; i < OBST_NB; i++)
	{
		lo[i] = new LightObstacle(map);
//		ho[i] = new HeavyObstacle(map);
		l_enem[i] = new Enemy(map);
	}
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