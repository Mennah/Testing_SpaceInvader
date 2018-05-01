#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Enemy::SetX(int x)
{
	this->x = x;
}

int Enemy::GetX() const
{
	return this->x;
}

void Enemy::SetY(int y)
{
	this->y = y;
}

int Enemy::GetY() const
{
	return this->y;
}

void Enemy::DisplayData() const
{
	cout << "Enemy at position (" << this->x << ", " << this->y << ")"<<endl;
}