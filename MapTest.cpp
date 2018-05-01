#include "stdafx.h"
#include "stdio.h"
#include "gtest/gtest.h"
#include "Map.h"

struct mapTest : testing::Test
{
	Map* map;

	mapTest()
	{
		map = new Map(10,10);
	}

	~mapTest()
	{
		delete map;
	}
};

TEST_F(mapTest, StatementCoverage_DoNothing)
{
	//Shoot
	Bullet* bullet  = new Bullet(1, 2);
	Player* player = map->GetPlayerInfo();

	map->AddBullet(bullet);
	map->AddEnemy(1, 1);

	map->DoNothing();
	map->DisplayData();

	EXPECT_EQ(1, player->GetScore());
}


TEST_F(mapTest, StatementCoverage_MoveLeft)
{
	Player* player = map->GetPlayerInfo();

	map->MoveLeft();
	map->DisplayData();
	EXPECT_EQ(4, player->GetX());
}

TEST_F(mapTest, StatementCoverage_MoveRight)
{
	Player* player = map->GetPlayerInfo();

	map->MoveRight();
	map->DisplayData();
	EXPECT_EQ(6, player->GetX());
}

TEST_F(mapTest, StatementCoverage_AddBullet)
{
	Bullet* bullet = new Bullet(10,10);
	map->AddBullet(bullet);
	Bullet***p = map->GetBullets();
	map->DisplayData();
	EXPECT_EQ(10, p[0][0][0].GetX());
}

TEST_F(mapTest, StatementCoverage_AddEnemy)
{
	map->AddEnemy(10, 10);
	Enemy***p = map->GetEnemies();
	map->DisplayData();
	EXPECT_EQ(10, p[0][0][0].GetX());
}

TEST_F(mapTest, StatementCoverage_Shoot)
{
	map->Shoot();
	Bullet***p = map->GetBullets();
	map->DisplayData();
	EXPECT_EQ(5, p[0][0][0].GetX());
}

TEST_F(mapTest, EdgePairCoverage_DoNothing_T1)
{
	//two Bullets -ve no enemies
	Map* map2 = map;
	map = new Map(10, 1);
	Player* player = map->GetPlayerInfo();

	map->Shoot();
	map->Shoot();
	map->Shoot();
	map->DisplayData();
	EXPECT_EQ(0, player->GetScore());
	map = map2;
}

TEST_F(mapTest, EdgePairCoverage_DoNothing_T2)
{
	//two Bullets -ve - two enemies
	Map* map2 = map;
	map = new Map(10, 1);
	Player* player = map->GetPlayerInfo();

	map->AddEnemy(0, 0);
	map->AddEnemy(1, 1);
	map->Shoot();
	map->Shoot();
	map->Shoot();
	map->DisplayData();
	EXPECT_EQ(0, player->GetScore());
	map = map2;
}

TEST_F(mapTest, EdgePairCoverage_DoNothing_T3)
{
	//two Bullets - two enemies - no score
	Player* player = map->GetPlayerInfo();

	map->AddEnemy(0, 0);
	map->AddEnemy(1, 1);
	map->Shoot();
	map->Shoot();
	map->DisplayData();
	EXPECT_EQ(0, player->GetScore());
}

TEST_F(mapTest, EdgePairCoverage_DoNothing_T4)
{
	//two Bullets - two enemies - two score
	Map* map2 = map;
	map = new Map(6, 5);
	Player* player = map->GetPlayerInfo();

	map->AddEnemy(3, 1);
	map->AddEnemy(4, 0);

	map->Shoot();
	map->MoveRight();
	map->Shoot();
	map->Shoot();
	map->DoNothing();
	map->MoveLeft();
	map->DisplayData();
	EXPECT_EQ(2, player->GetScore());
	map = map2;
}

TEST_F(mapTest, InputSpacePartitioning1)
{
	Map* map2 = new Map(0, 10);
	EXPECT_EQ(0, map2->GetPlayerInfo()->GetX());
	EXPECT_EQ(9, map2->GetPlayerInfo()->GetY());
}

TEST_F(mapTest, InputSpacePartitioning2)
{
	Map* map2 = new Map(20, 10);
	EXPECT_EQ(10, map2->GetPlayerInfo()->GetX());
	EXPECT_EQ(9, map2->GetPlayerInfo()->GetY());
}

TEST_F(mapTest, InputSpacePartitioning3)
{
	Map* map2 = new Map(-10, 10);
	EXPECT_EQ(-5, map2->GetPlayerInfo()->GetX());
	EXPECT_EQ(9, map2->GetPlayerInfo()->GetY());
}

TEST_F(mapTest, InputSpacePartitioning4)
{
	Map* map2 = new Map(10, 10);
	EXPECT_EQ(5, map2->GetPlayerInfo()->GetX());
	EXPECT_EQ(9, map2->GetPlayerInfo()->GetY());
}

TEST_F(mapTest, InputSpacePartitioning5)
{
	Map* map2 = new Map(-10, 10);
	EXPECT_EQ(-5, map2->GetPlayerInfo()->GetX());
	EXPECT_EQ(9, map2->GetPlayerInfo()->GetY());
}

TEST_F(mapTest, InputSpacePartitioning6)
{
	Map* map2 = new Map(0, 10);
	EXPECT_EQ(0, map2->GetPlayerInfo()->GetX());
	EXPECT_EQ(9, map2->GetPlayerInfo()->GetY());
}

TEST_F(mapTest, InputSpacePartitioning7)
{
	map->AddEnemy(100, 7);
	Enemy*** e = map->GetEnemies();
	EXPECT_EQ(100, e[0][0][0].GetX());
	EXPECT_EQ(7, e[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartitioning8)
{
	map->AddEnemy(-100, 7);
	Enemy*** e = map->GetEnemies();
	EXPECT_EQ(-100, e[0][0][0].GetX());
	EXPECT_EQ(7, e[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartitioning9)
{
	map->AddEnemy(0, 7);
	Enemy*** e = map->GetEnemies();
	EXPECT_EQ(0, e[0][0][0].GetX());
	EXPECT_EQ(7, e[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartitioning10)
{
	map->AddEnemy(5, 7);
	Enemy*** e = map->GetEnemies();
	EXPECT_EQ(5, e[0][0][0].GetX());
	EXPECT_EQ(7, e[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartitioning11)
{
	map->AddEnemy(7, 100);
	Enemy*** e = map->GetEnemies();
	EXPECT_EQ(7, e[0][0][0].GetX());
	EXPECT_EQ(100, e[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartitioning12)
{
	map->AddEnemy(7, -100);
	Enemy*** e = map->GetEnemies();
	EXPECT_EQ(7, e[0][0][0].GetX());
	EXPECT_EQ(-100, e[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartitioning13)
{
	map->AddEnemy(7, 0);
	Enemy*** e = map->GetEnemies();
	EXPECT_EQ(7, e[0][0][0].GetX());
	EXPECT_EQ(0, e[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartitioning14)
{
	map->AddEnemy(7, 5);
	Enemy*** e = map->GetEnemies();
	EXPECT_EQ(7, e[0][0][0].GetX());
	EXPECT_EQ(5, e[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartition15)
{
	Bullet *bullet2 = new Bullet(0, 0);
	Bullet*** b = map->GetBullets();
	map->AddBullet(bullet2);
	EXPECT_EQ(0, b[0][0][0].GetX());
	EXPECT_EQ(0, b[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartition16)
{
	Bullet *bullet2 = new Bullet(100000000, 0);
	Bullet*** b = map->GetBullets();
	map->AddBullet(bullet2);
	EXPECT_EQ(100000000, b[0][0][0].GetX());
	EXPECT_EQ(0, b[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartition17)
{
	Bullet *bullet2 = new Bullet(-10000000, 0);
	Bullet*** b = map->GetBullets();
	map->AddBullet(bullet2);
	EXPECT_EQ(-10000000, b[0][0][0].GetX());
	EXPECT_EQ(0, b[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartition18)
{
	Bullet *bullet2 = new Bullet(0, 100000000);
	Bullet*** b = map->GetBullets();
	map->AddBullet(bullet2);
	EXPECT_EQ(0, b[0][0][0].GetX());
	EXPECT_EQ(100000000, b[0][0][0].GetY());
}

TEST_F(mapTest, InputSpacePartition19)
{
	Bullet *bullet2 = new Bullet(0, -10000000);
	Bullet*** b = map->GetBullets();
	map->AddBullet(bullet2);
	EXPECT_EQ(0, b[0][0][0].GetX());
	EXPECT_EQ(-10000000, b[0][0][0].GetY());
}


/********************************Predicate Coverage*********************************/

TEST_F(mapTest, PredicateCoverage_AddBullet)
{
	Bullet* bullet1 = new Bullet(8, 8);
	map->AddBullet(bullet1);
	Bullet* bullet2 = new Bullet(9, 9);
	map->AddBullet(bullet2);
	Bullet***p = map->GetBullets();

	EXPECT_EQ(NULL, p[0][2]);
	EXPECT_TRUE(p[0][1] != NULL);
}

TEST_F(mapTest, PredicateCoverage_AddEnemy)
{
	map->AddEnemy(3,3);
	map->AddEnemy(5,7);
	map->AddEnemy(7,5);
	Enemy***p = map->GetEnemies();

	EXPECT_EQ(NULL, p[0][3]);
	EXPECT_TRUE(p[0][2] != NULL);
}

TEST_F(mapTest, PredicateCoverage_DoNothing1)
{
	Bullet* bullet = new Bullet(1, -2);
	map->AddBullet(bullet);
	map->DoNothing();

	Bullet***p = map->GetBullets();
	EXPECT_EQ(NULL, p[0][0]);
}

TEST_F(mapTest, PredicateCoverage_DoNothing2)
{
	Bullet* bullet = new Bullet(1, 0);
	map->AddBullet(bullet);
	map->DoNothing();

	Bullet***p = map->GetBullets();
	EXPECT_EQ(NULL, p[0][0]);
}

TEST_F(mapTest, PredicateCoverage_DoNothing3)
{
	Bullet* bullet = new Bullet(1, 2);
	map->AddBullet(bullet);
	map->DoNothing();

	Bullet***p = map->GetBullets();
	EXPECT_TRUE(p[0][0] != NULL);
}

TEST_F(mapTest, PredicateCoverage_DoNothing4)
{
	map->AddEnemy(1, 1);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(0, player->GetScore());

	Enemy***e = map->GetEnemies();
	EXPECT_TRUE(e[0][0] != NULL);
}

TEST_F(mapTest, PredicateCoverage_DoNothing5)
{
	map->AddEnemy(1, 1);
	Bullet* bullet = new Bullet(1, 5);
	map->AddBullet(bullet);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(0, player->GetScore());

	Bullet***p = map->GetBullets();
	EXPECT_TRUE(p[0][0] != NULL);

	Enemy*** e = map->GetEnemies();
	EXPECT_TRUE(e[0][0] != NULL);
}

TEST_F(mapTest, PredicateCoverage_DoNothing6)
{
	map->AddEnemy(1, 1);
	Bullet* bullet = new Bullet(1, 2);
	map->AddBullet(bullet);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(1, player->GetScore());

	Bullet*** p = map->GetBullets();
	EXPECT_EQ(NULL, p[0][0]);

	Enemy*** e = map->GetEnemies();
	EXPECT_EQ(NULL, e[0][0]);
}

/********************************General Active Clause Coverage*********************************/

TEST_F(mapTest, GACC_DoNothing1)
{
	map->AddEnemy(1, 1);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(0, player->GetScore());

	Enemy***e = map->GetEnemies();
	EXPECT_TRUE(e[0][0] != NULL);
}

TEST_F(mapTest, GACC_DoNothing2)
{
	map->AddEnemy(1, 1);
	Bullet* bullet = new Bullet(1, 3);
	map->AddBullet(bullet);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(0, player->GetScore());

	Bullet***p = map->GetBullets();
	EXPECT_TRUE(p[0][0] != NULL);

	Enemy*** e = map->GetEnemies();
	EXPECT_TRUE(e[0][0] != NULL);
}

TEST_F(mapTest, GACC_DoNothing3)
{
	map->AddEnemy(1, 1);
	Bullet* bullet = new Bullet(3, 1);
	map->AddBullet(bullet);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(0, player->GetScore());

	Bullet***p = map->GetBullets();
	EXPECT_TRUE(p[0][0] != NULL);

	Enemy*** e = map->GetEnemies();
	EXPECT_TRUE(e[0][0] != NULL);
}

TEST_F(mapTest, GACC_DoNothing4)
{
	map->AddEnemy(1, 1);
	Bullet* bullet = new Bullet(1, 2);
	map->AddBullet(bullet);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(1, player->GetScore());

	Bullet*** p = map->GetBullets();
	EXPECT_EQ(NULL, p[0][0]);

	Enemy*** e = map->GetEnemies();
	EXPECT_EQ(NULL, e[0][0]);
}

/********************************General Inactive Clause Coverage*******************************/

TEST_F(mapTest, GICC_DoNothing1)
{
	map->AddEnemy(1, 1);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(0, player->GetScore());

	Enemy***e = map->GetEnemies();
	EXPECT_TRUE(e[0][0] != NULL);
}

TEST_F(mapTest, GICC_DoNothing2)
{
	map->AddEnemy(1, 1);
	Bullet* bullet = new Bullet(1, 3);
	map->AddBullet(bullet);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(0, player->GetScore());

	Bullet***p = map->GetBullets();
	EXPECT_TRUE(p[0][0] != NULL);

	Enemy*** e = map->GetEnemies();
	EXPECT_TRUE(e[0][0] != NULL);
}

TEST_F(mapTest, GICC_DoNothing3)
{
	map->AddEnemy(1, 1);
	Bullet* bullet = new Bullet(3, 1);
	map->AddBullet(bullet);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(0, player->GetScore());

	Bullet***p = map->GetBullets();
	EXPECT_TRUE(p[0][0] != NULL);

	Enemy*** e = map->GetEnemies();
	EXPECT_TRUE(e[0][0] != NULL);
}

TEST_F(mapTest, GICC_DoNothing4)
{
	map->AddEnemy(1, 1);
	Bullet* bullet = new Bullet(3, 3);
	map->AddBullet(bullet);
	Player* player = map->GetPlayerInfo();
	map->DoNothing();
	EXPECT_EQ(0, player->GetScore());

	Bullet***p = map->GetBullets();
	EXPECT_TRUE(p[0][0] != NULL);

	Enemy*** e = map->GetEnemies();
	EXPECT_TRUE(e[0][0] != NULL);
}

