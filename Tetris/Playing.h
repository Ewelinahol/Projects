#pragma once
#include<iostream>
#include<forward_list>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System\Clock.hpp>
#include"Title_picture.h"


using namespace std;

class Playing
{
protected:
	sf::Sprite Szejpik;
	sf::Clock clock;
	float time;
	float far = 0.4;
	float timer = 0;
	int found = 0;
	sf::Text score;
	int result = 0;
public:
	void scores(sf::RenderWindow &window,grid *gridek);
	void play();
	sf::Text get_score();

};
