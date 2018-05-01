#include "stdafx.h"
#include"Bullet.h"

Bullet::Bullet(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Bullet::SetX(int x)
{
	this->x = x;
}

int Bullet::GetX() const
{
	return this->x;
}

void Bullet::SetY(int y)
{
	this->y = y;
}

int Bullet::GetY() const
{
	return this->y;
}

void Bullet::Move()
{
	this->y--;
}

void Bullet::DisplayData() const
{
	cout << "Bullet at position (" << this->x << ", " << this->y << ")" << endl;
}