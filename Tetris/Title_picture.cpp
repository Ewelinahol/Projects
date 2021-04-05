#include<iostream>
#include<vector>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<memory>
#include<time.h>
#include"Title_picture.h"


using namespace std;
int Titlepng::get_kind()
{
	return this->kind;
}
int Titlepng::get_colour()
{
	return this->colour;
}
void Titlepng::set_kind(int temp)
{
	this->kind = temp;
}
void Titlepng::set_colour(int temp)
{
	this->colour = temp;
}

void Titlepng::change_hold(bool new_hold)
{
	this->hold = new_hold;
}
sf::Sprite Titlepng::set_shape(string name, int colour)
{
	square.loadFromFile(name);
	
	shape.setTexture(square);
	shape.setTextureRect(sf::IntRect(colour * 32, 0, 32, 32));
	 
	return shape;
}

forward_list<point> Titlepng::update(int figure, forward_list<point>axs, sf::Event event, grid* gridek)
{
														
	int collis = gridek->collision(axs);
	gridek->checkline();
	forward_list<point>::iterator element = axs.begin();

	if (event.key.code == sf::Keyboard::Right)
	{
		if(gridek->get_set()!=1 && gridek->get_right()!=3)
		if (!hold)
		{

			for (; element != axs.end(); element++)
			{
				element->y += 1;
			}
			
		}
		
	}
	else if (event.key.code == sf::Keyboard::Left)
	{
		if (gridek->get_set()!=1 && gridek->get_left()!=2)
		if (!hold)
		{

			for (; element != axs.end(); element++)
				element->y -= 1;
		}

	}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))// u¿yte spowodu wolniejszego przesuwania w dó³ ni¿ w przypadku u¿ycie event
	{

		if (gridek->get_set() != 1 && gridek->get_down()!= 4 )
		{

			for (; element != axs.end(); element++)
				element->x += 1;
		}
		

	}	
	else if (event.key.code == sf::Keyboard::Up)
	{

		if (gridek->get_set() != 1&& gridek->get_down()!=4)
		if (!hold)
		axs=rotation(figure,axs,gridek->get_map());
		

	}
	gridek->set_int();
	
	return axs;
	
}
void Titlepng:: draw(vector<vector<int>> map, sf::Sprite temp, sf::RenderWindow &window)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 0)
				continue;
			temp.setTextureRect(sf::IntRect((map[i][j]-1) * 32, 0, 32, 32));
			temp.setPosition(j * 32, i * 32);
			window.draw(temp);
		}

	}
}

Titlepng::Titlepng() {};