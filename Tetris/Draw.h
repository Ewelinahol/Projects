#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<vector>

// wyœwietlanie punktacji i planszy w oknie
class Draw
{
protected:
	sf::Sprite sprit;
public:
	virtual void draww(sf::RenderWindow& window, int integer) {};
	virtual sf::Sprite draw() { return sprit; };
};
class Draw_score : public Draw
{
public:
	 void draww(sf::RenderWindow& window, int result);
};
class Draw_map : public Draw
{
private:
	sf::Texture background;
public:
	 sf::Sprite draw();
	
};