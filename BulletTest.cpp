#include "stdafx.h"
#include "stdio.h"
#include "gtest/gtest.h"
#include "Map.h"

struct bulletTest : testing::Test
{
	Bullet* bullet;

	bulletTest()
	{
		bullet = new Bullet(1,1);
	}

	~bulletTest()
	{
		delete bullet;
	}
};

TEST_F(bulletTest, StatementCoverage1)
{
	bullet->DisplayData();
	EXPECT_EQ(1, bullet->GetX());
	EXPECT_EQ(1, bullet->GetY());
}

TEST_F(bulletTest, StatementCoverage2)
{
	bullet->Move();
	bullet->DisplayData();
	EXPECT_EQ(1, bullet->GetX());
	EXPECT_EQ(0, bullet->GetY());
}

TEST_F(bulletTest, StatementCoverage3)
{
	bullet->SetX(10);
	bullet->DisplayData();
	EXPECT_EQ(10, bullet->GetX());
}

TEST_F(bulletTest, StatementCoverage4)
{
	bullet->SetX(10);
	bullet->SetY(0);
	bullet->Move();
	bullet->DisplayData();
	EXPECT_EQ(10, bullet->GetX());
	EXPECT_EQ(-1, bullet->GetY());
}

TEST_F(bulletTest, InputSpacePartition1)
{
	Bullet *bullet2 = new Bullet(0, 0);
	EXPECT_EQ(0, bullet2->GetX());
}

TEST_F(bulletTest, InputSpacePartition2)
{
	Bullet *bullet2 = new Bullet(100000000, 0);
	EXPECT_EQ(100000000, bullet2->GetX());
}

TEST_F(bulletTest, InputSpacePartition3)
{
	Bullet *bullet2 = new Bullet(-10000000, 0);
	EXPECT_EQ(-10000000, bullet2->GetX());
}

TEST_F(bulletTest, InputSpacePartition4)
{
	Bullet *bullet2 = new Bullet(0, 100000000);
	EXPECT_EQ(100000000, bullet2->GetY());
}

TEST_F(bulletTest, InputSpacePartition5)
{
	Bullet *bullet2 = new Bullet(0, -10000000);
	EXPECT_EQ(-10000000, bullet2->GetY());
}

TEST_F(bulletTest, InputSpacePartition6)
{
	bullet->SetX(1256);
	EXPECT_EQ(1256, bullet->GetX());
}

TEST_F(bulletTest, InputSpacePartition7)
{
	bullet->SetX(-1256);
	EXPECT_EQ(-1256, bullet->GetX());
}


TEST_F(bulletTest, InputSpacePartition8)
{
	bullet->SetX(0);
	EXPECT_EQ(0, bullet->GetX());
}


TEST_F(bulletTest, InputSpacePartition9)
{
	bullet->SetY(265);
	EXPECT_EQ(265, bullet->GetY());
}


TEST_F(bulletTest, InputSpacePartition10)
{
	bullet->SetY(-3265);
	EXPECT_EQ(-3265, bullet->GetY());
}


TEST_F(bulletTest, InputSpacePartition11)
{
	bullet->SetY(0);
	EXPECT_EQ(0, bullet->GetY());
}

