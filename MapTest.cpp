#include "stdio.h"
#include "gtest/gtest.h"
#include "Map.h"

struct mapTest : testing::Test
{
	Map* map;

	mapTest()
	{
		map = new Map(1,1);
	}

	~mapTest()
	{
		delete map;
	}
};

TEST_F(mapTest, PCtest)
{

}
