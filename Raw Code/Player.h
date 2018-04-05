#ifndef PLAYER_H
#define PLAYER_H

#include "Bullet.h"
#include<iostream>
using namespace std;

class Player
{
private:
	int x, y;
	int score;
public:
	Player(int x, int y);
	void SetX(int x);
	int GetX() const;
	void SetY(int y);
	int GetY() const;
	void SetScore(int score);
	int GetScore() const;
	void MoveLeft();
	void MoveRight(int screenWidth);
	Bullet* Shoot();
	void DisplayData() const;
};

#endif