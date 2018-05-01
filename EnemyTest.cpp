#include "stdafx.h"
#include "stdio.h"
#include "gtest/gtest.h"
#include "Map.h"

struct enemyTest : testing::Test
{
	Enemy* enemy;

	enemyTest()
	{
		enemy = new Enemy(1,1);
	}

	~enemyTest()
	{
		delete enemy;
	}
};

TEST_F(enemyTest, StatementCoverage1)
{
	enemy->DisplayData();
	EXPECT_EQ(1, enemy->GetX());
	EXPECT_EQ(1, enemy->GetY());
}

TEST_F(enemyTest, StatementCoverage2)
{
	enemy->SetX(10);
	enemy->DisplayData();
	EXPECT_EQ(10, enemy->GetX());
}

TEST_F(enemyTest, StatementCoverage3)
{
	enemy->SetY(1000);
	enemy->DisplayData();
	EXPECT_EQ(1000, enemy->GetY());
}

TEST_F(enemyTest, InputSpacePartition1)
{
	Enemy *enemy2 = new Enemy(0, 0);
	EXPECT_EQ(0, enemy2->GetX());
}

TEST_F(enemyTest, InputSpacePartition2)
{
	Enemy *enemy2 = new Enemy(100000000, 0);
	EXPECT_EQ(100000000, enemy2->GetX());
}

TEST_F(enemyTest, InputSpacePartition3)
{
	Enemy *enemy2 = new Enemy(-10000000, 0);
	EXPECT_EQ(-10000000, enemy2->GetX());
}

TEST_F(enemyTest, InputSpacePartition4)
{
	Enemy *enemy2 = new Enemy(0, 100000000);
	EXPECT_EQ(100000000, enemy2->GetY());
}

TEST_F(enemyTest, InputSpacePartition5)
{
	Enemy *enemy2 = new Enemy(0, -10000000);
	EXPECT_EQ(-10000000, enemy2->GetY());
}

TEST_F(enemyTest, InputSpacePartition6)
{
	enemy->SetX(1256);
	EXPECT_EQ(1256, enemy->GetX());
}

TEST_F(enemyTest, InputSpacePartition7)
{
	enemy->SetX(-1256);
	EXPECT_EQ(-1256, enemy->GetX());
}


TEST_F(enemyTest, InputSpacePartition8)
{
	enemy->SetX(0);
	EXPECT_EQ(0, enemy->GetX());
}


TEST_F(enemyTest, InputSpacePartition9)
{
	enemy->SetY(265);
	EXPECT_EQ(265, enemy->GetY());
}


TEST_F(enemyTest, InputSpacePartition10)
{
	enemy->SetY(-3265);
	EXPECT_EQ(-3265, enemy->GetY());
}


TEST_F(enemyTest, InputSpacePartition11)
{
	enemy->SetY(0);
	EXPECT_EQ(0, enemy->GetY());
}
