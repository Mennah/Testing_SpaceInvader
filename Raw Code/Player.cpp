#include"Player.h"

Player::Player(int x, int y)
{
	this->x = x;
	this->y = y;
	this->score = 0;
}

void Player::SetX(int x)
{
	this->x = x;
}

int Player::GetX() const
{
	return this->x;
}

void Player::SetY(int y)
{
	this->y = y;
}

int Player::GetY() const
{
	return this->y;
}

void Player::SetScore(int score)
{
	this->score = score;
}

int Player::GetScore() const
{
	return this->score;
}

void Player::MoveLeft()
{
	this->x -= 1;
	if (this->x < 0)
	{
		this->x = 0;
	}
}

void Player::MoveRight(int screenWidth)
{
	this->x += 1;
	if (this->x > screenWidth - 1)
	{
		this->x = screenWidth - 1;
	}
}

Bullet* Player::Shoot()
{
	Bullet* bullet = new Bullet(this->x, this->y - 1);
	return bullet;
	
}

void Player::DisplayData() const
{
	cout << "Player at position (" << this->x << ", " << this->y << ") with score: " << this->score << endl;
}