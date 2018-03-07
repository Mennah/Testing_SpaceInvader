#pragma once

#ifndef BULLET_H
#define BULLET_H

#include<iostream>
using namespace std;

class Bullet
{
private:
	int x, y;
public:
	Bullet(int x, int y);
	void SetX(int x);
	int GetX() const;
	void SetY(int y);
	int GetY() const;
	void Move();
	void DisplayData() const;
};

#endif