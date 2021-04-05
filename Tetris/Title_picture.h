#pragma once
#include<iostream>
#include<vector>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System\Clock.hpp>
#include"Grid.h"

using namespace std;

class Titlepng: public Title, public grid
{
protected:

	bool hold = false;
	sf::Texture square;
	sf::Sprite shape;
	int colour=0;
	int kind=0;
public:

	Titlepng();
	int get_kind();
	int get_colour();
	void set_kind(int kindik);
	void set_colour(int color);
	sf::Sprite set_shape(string name,int colour);
	forward_list<point> update(int figure, forward_list<point>axis, sf::Event event, grid *gridek);
	void change_hold(bool new_hold);
	void draw(vector<vector<int>>map, sf::Sprite temp, sf::RenderWindow &window);
};
