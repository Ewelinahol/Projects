#include<iostream>
#include<forward_list>
#include"Title.h"

using namespace std;


forward_list<point> Title::rotation(int figure, forward_list<point> axi, vector<vector<int>>map)
{
	int x, y;
	int min = 0;
	int max = 9;
	
	int check=0;
	int sub = 0;
	int count = 0;
	int left = 0;// czy przy rotacji moøna przesunπÊ w prawo
	int right = 0;
	int minus = 0;
	forward_list<point>::iterator iter=axi.begin();// wskaünik do iteracji po ca≥ym klocku
	forward_list<point>::iterator firstIndex=axi.begin();
	// przeliczenie wymiarÛw klocka
	int min_t = firstIndex->x;
	int max_t =min_t ;
	for (; firstIndex != axi.end(); firstIndex++)
	{
		if (firstIndex->x < min_t)
			min_t = firstIndex->x;
		if (firstIndex->x > max_t)
			max_t = firstIndex->x;
	}
	sub = (max_t - min_t)+1;
	int temp = 0;

	// rotacja w pobliøu innych klockÛw
	for (firstIndex = axi.begin(); firstIndex != axi.end(); firstIndex++)
	{
		// sprawdzenie tablicy po prawej stronie klocka
		temp = firstIndex->y;
		check = firstIndex->y + sub-1;
		if (check > 9)
			break;
		while (temp <=check )
		{
			if (map[firstIndex->x][temp] != 0)
			{
				left=1;
				break;
			}
			else if (map[firstIndex->x][temp] == 0)
				count++;
			temp++;
		}
		temp = firstIndex->y;
		check = firstIndex->y - sub-1;
		if (check <0)
			break;
		// sprawdzenie tablicy po lewej stronie klocka
		while (temp >=check)
		{
			if (map[firstIndex->x][temp] != 0)
			{
				right=1;
				break;
			}
			else if (map[firstIndex->x][temp] == 0)
				count++;
			temp--;
		}
		if (count < sub)
			return axi;
	}

	// zwyk≥y obrÛt
	firstIndex = axi.begin();
	for (; iter != axi.end(); iter++)
	{
		if (count >= sub)// jeúli siÍ da to przesuÒ klocka, a potem przejdü do obritu
		{
			if (left)
				iter->y -= sub - 1;
			if (right)
				iter->y += sub - 1;

		}
		
		y = iter->x - firstIndex->x;
		x = iter->y - firstIndex->y;
		iter->x = firstIndex->x - x;
		iter->y = firstIndex->y + y;
		if (iter->x<= 0)
			minus = 1;
		if (iter->y < min)
			min = iter->y;
		if(iter->y > max)
			max = iter->y;
	}
	//dzia≥anie jeúli rotacja wyjdzie poza zakres tablicy
	for (; firstIndex != axi.end(); firstIndex++)
	{
		//gdy zechcemy rotacjÍ przy gÛrnych rogach tablicy
		if (minus)
		{
			firstIndex->x++;
			firstIndex->x++;
		}
		
	  firstIndex->y -= min;
	  if (max >=9)
	  {
		  int temp = max - 9;
		  firstIndex->y -= temp;
	  } 
	}
	
	return axi;
}

forward_list<point> Title::get_list(int x, forward_list<point>b)
{
	b=axis[x];
	return b;
}
Title::Title() {};






