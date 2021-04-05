#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include"Grid.h"


using namespace std;
grid::grid()
{
	
	for (int i = 0; i < 20; i++)
	{
		vector<int> u;
		for (int j = 0; j < 10; j++)
			u.push_back(0);
		this->map.push_back(u);
	}

}

void grid::set_colour(int colour)
{
	this->colour = colour;
}
void grid::set_int()
{
	set = 0;
	down = 0;
	right = 0;
	left = 0;
}
int grid::get_mapij(int i, int j)
{
	return this->map[i][j];
}
int grid::get_colour()
{
	return this->colour;
}
int grid::get_down()
{
	return this->down;
}
int grid::get_set()
{
	return this->set;
}
int grid::get_right()
{
	return this->right;
}
int grid::get_left()
{
	return this->left;
}
bool grid::theEnd()
{
	if (this->map[0][0] != 0)
		return true;
	return false;
}
void grid::set_piece(forward_list<point>shape)
{
	forward_list<point>::iterator i = shape.begin();
	for(;i!=shape.end();i++)
		this->map[i->x][i->y] = this->get_colour()+1; 
	
}
int grid::get_found()
{
	return this->found;
}


bool grid::checkline()// po znalezieniu ca³ej lini zwaraca wartoœæ true
{
	
	int temp = 19;
	this->found = 0;
	int count;
	for (int i=19; i>=0; i--)
	{
		count=0;
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j])
				count++;
			this->map[temp][j] = this->map[i][j];
		}
		if (count < 10)
			temp--;
		else
			this->found++;
	}
	if (this->found == 0)
		return false;
	return true;
}
int grid::collision(forward_list<point>shape)// po przesuniêciu w bok wchodzi w klocka obok
{

	forward_list<point>::iterator i=shape.begin();
	
	for (; i != shape.end(); i++)
	{
		if (i->x == 19)
		{
			set_piece(shape);
			
			this->down = 4;

		}
		else if (this->map[(i->x) + 1][i->y] != 0)
		{
			set_piece(shape);
			
			this->set = 1;

		}

		else if (i->y == 9 || this->map[i->x][i->y + 1] != 0)
			this->right = 3;
		else if (i->y == 0 || this->map[i->x][i->y - 1] != 0)
			this->left = 2;
		else if (down == 4 && i->x == 0) // zape³nienie ca³ej planszy- koniec gry!!
			this->end = 1;
		

	}
	
	
	return 0;
}
bool grid::checkvalue(forward_list<point> shape)
{

	forward_list<point>::iterator i=shape.begin();
	for (; i != shape.end(); i++)
	{
		if (i->x == 19)
			return true;
		else if (this->map[i->x+1][i->y]!=0)
			return true;
		
	}
	return false;
}

vector<vector<int>> grid::get_map()
{
	return this->map;
}