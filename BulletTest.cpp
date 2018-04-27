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

TEST_F(bulletTest, PCtest)
{
	
}
