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

TEST_F(enemyTest, PCtest)
{
	
}
