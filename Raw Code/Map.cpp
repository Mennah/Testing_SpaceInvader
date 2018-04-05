#include "Map.h"

Map ::Map (int w, int h)
	: width (w), height(h), player ((w /2), (h -1))
{
	int c =0;
	int d=0;
	bullets = new Bullet *[10];
	while (c <10)
	{
		bullets[c] = NULL;
		c++;
	}
	enemies = new Enemy *[10];
	while (d <10)
	{
		enemies[d] = NULL;
		d++;
	}
}

void Map ::AddBullet (Bullet* bullet)
{
	int i =0;
	while (bullets[i] != NULL)
		i++;

	bullets[i] = bullet;

}

void Map ::AddEnemy (int x, int y)
{
	int j = 0;
	Enemy* temp = new Enemy(x,y);
	while (enemies[j] != NULL)
		j++;

	enemies[j] = temp;
}

void Map ::MoveLeft()
{
	DoNothing();
	player.MoveLeft();
	
}

void Map ::MoveRight()
{
	DoNothing();
	player.MoveRight(width);
	
	
}

void Map ::Shoot()
{
	DoNothing();
	AddBullet(player.Shoot());
	
}

void Map :: UpdateBullets()
{
	int k =0;
	int l =0;
	int m=0;
	int y = k+1;
	int x = l+1;
	Bullet* tempB;
	Enemy* tempE;

	while (bullets[m] != NULL)
	{
		bullets[m]->Move();
		m++;
	}

	while (bullets[k] != NULL)
	{
		
		if (bullets[k]->GetY() <0)
		{
			while (bullets[y] != NULL)
			  y++;

			swap(*bullets[k],*bullets[y-1]);

			delete bullets[y-1];
			bullets[y-1] = NULL;
			//break;
		}
		
		while (enemies[l] != NULL)
		{
			if (bullets[k] != NULL && enemies[l] != NULL)
			{
			if ((bullets[k]->GetX() == enemies[l]->GetX()) && (bullets[k]->GetY() == enemies[l]->GetY()))
			{
				cout <<"Bullet kill an enemy at position ("<< enemies[l]->GetX() <<","<< enemies[l]->GetY()<<")"<<endl;
				while (bullets[y] != NULL)
			      y++;

				swap (*bullets[y-1], *bullets[k]);

				delete bullets[y-1];
			    bullets[y-1] = NULL;

				 
				while (enemies[x] != NULL)
				x++;

				
				swap (*enemies[x-1], *enemies[l]);


				delete enemies[x-1];
				enemies[x-1] = NULL;

				int s=player.GetScore();
				s = s+1;
				player.SetScore(s);
			}
         
		}
			  l++;
		}
	k++;	
	}
}

void Map ::DoNothing()
{
	UpdateBullets();
}


void Map ::DisplayData()const
{
	int g=0;
	int f=0;
	cout << "____________________________________"<<endl;
	cout << "Player at position (" << player.GetX() << "," << player.GetY() <<") with score " << player.GetScore()<<endl;

	while (enemies[g] != NULL)
	{
		enemies[g]->DisplayData();
		g++;
	}

	while (bullets[f] != NULL)
	{
		bullets[f]->DisplayData();
		f++;
	}
}

Map :: ~Map()
{
	int a = 0;
	int b = 0;
	while (enemies[a] != NULL)
	{
		delete enemies[a];
		enemies[a] = NULL;
		a++;
	}
	while (bullets[b] != NULL)
	{
		delete bullets[b];
		bullets[b] = NULL;
		b++;
	}
	delete[] enemies;
	delete[] bullets;
}
/*
Map(int width, int height);
	~Map();
	void MoveLeft();
	void MoveRight();
	void Shoot();
	void DoNothing();
	void DisplayData() const;
	*/