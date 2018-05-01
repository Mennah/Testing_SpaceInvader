#include "stdafx.h"
#include "stdio.h"
#include "gtest/gtest.h"
#include "Map.h"

struct playerTest : testing::Test
{
	Player* player;

	playerTest()
	{
		player = new Player(1,1);
	}

	~playerTest()
	{
		delete player;
	}
};

TEST_F(playerTest, StatementCoverage)
{
	player->DisplayData();
	EXPECT_EQ(1, player->GetX());
	EXPECT_EQ(1, player->GetY());

	Bullet *bullet = player->Shoot();
	player->DisplayData();
	EXPECT_EQ(player->GetX(), bullet->GetX());
	int dummy = bullet->GetY() + 1;
	EXPECT_EQ(player->GetY(), dummy);

	player->SetX(10);
	player->DisplayData();
	EXPECT_EQ(10, player->GetX());

	bullet = player->Shoot();
	player->DisplayData();
	EXPECT_EQ(player->GetX(), bullet->GetX());
	dummy = (bullet->GetY() + 1);
	EXPECT_EQ(player->GetY(), dummy);

	player->SetX(1000);
	player->DisplayData();
	EXPECT_EQ(1000, player->GetX());

	bullet = player->Shoot();
	player->DisplayData();
	EXPECT_EQ(player->GetX(), bullet->GetX());
	dummy = (bullet->GetY() + 1);
	EXPECT_EQ(player->GetY(), dummy);

	player->DisplayData();
	EXPECT_EQ(0, player->GetScore());

	player->SetScore(1);
	player->DisplayData();
	EXPECT_EQ(1, player->GetScore());

	//statement coverage of move left and move right are already achieved since it's one clause predicate coverage (branch coverage)
	//since branch coverage subsumes statement coverage
}

TEST_F(playerTest, PCtest)
{
	player->SetX(0);
	player->MoveLeft();
	EXPECT_EQ(0, player->GetX());

	player->SetX(2);
	player->MoveLeft();
	EXPECT_NE(0, player->GetX());

	player->SetX(10);
	player->MoveRight(100);
	EXPECT_NE(99, player->GetX());

	player->SetX(100);
	player->MoveRight(100);
	EXPECT_EQ(99, player->GetX());
}
