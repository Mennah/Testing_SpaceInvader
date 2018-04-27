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
