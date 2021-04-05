#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<vector>
#include"Title.h"

using namespace std;

class grid
{
protected:
	sf::Texture background;
	vector<vector<int>> map;
	int set=0, left = 0, right = 0, down=0, end=0;
	sf::RenderWindow windoww;
	int colour = 0;
	int found = 0;

public:
	grid();
	grid( grid& nowy) = default;
	bool checkline();
	void set_piece(forward_list<point>shape);
	int collision(forward_list<point>shape); // 0- idziemy dalej, return 1-zapisanie klocka na planszy, brak mo¿liwoœci obrotu 2-nie porusza sie w lewo, 3-nie porusza sie w prawo, 4 nie spada w dó³
	void set_colour(int colour);
	int get_colour();
	int get_set();
	int get_right();
	int get_left();
	int get_down();
	int get_mapij(int i, int j);
	int get_found();
	bool theEnd();
	void set_int();// zeruje zmienne oznaczaj¹ce po³o¿enie klocka wzgledem planszy
	vector<vector<int>>  get_map();
	bool checkvalue(forward_list<point>shape);
};								

