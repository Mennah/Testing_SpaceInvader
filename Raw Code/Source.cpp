#include"Map.h"

void main()
{
	Map map(6, 5);
	map.AddEnemy(0, 0);
	map.AddEnemy(1, 1);
	map.AddEnemy(2, 0);
	map.AddEnemy(3, 1);
	map.AddEnemy(4, 0);
	map.AddEnemy(5, 1);
	map.DisplayData();

	map.Shoot();
	map.DisplayData();

	map.MoveRight();
	map.DisplayData();

	map.Shoot();
	map.DisplayData();

	map.Shoot();
	map.DisplayData();

	map.DoNothing();
	map.DisplayData();

	map.MoveLeft();
	map.DisplayData();

	map.MoveLeft();
	map.DisplayData();

	map.MoveLeft();
	map.DisplayData();

	map.Shoot();
	map.DisplayData();
}