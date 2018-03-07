#ifndef MAP_H
#define MAP_H

#include"Bullet.h"
#include"Player.h"
#include"Enemy.h"
#include<iostream>
using namespace std;

class Map
{
private:
	int width, height;
	Bullet** bullets;
	Enemy** enemies;
	Player player;
	void UpdateBullets();
public:
	Map(int width, int height);
	~Map();
	void AddEnemy(int x, int y);
	void AddBullet(Bullet* bullet);
	void MoveLeft();
	void MoveRight();
	void Shoot();
	void DoNothing();
	void DisplayData() const;
};

#endif

