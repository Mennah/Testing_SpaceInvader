#ifndef ENEMY_H
#define ENEMY_H

#include<iostream>
using namespace std;

class Enemy
{
private:
	int x, y;
public:
	Enemy(int x, int y);
	void SetX(int x);
	int GetX() const;
	void SetY(int y);
	int GetY() const;
	void DisplayData() const;
};

#endif