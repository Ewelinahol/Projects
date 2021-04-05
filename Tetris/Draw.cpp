#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include <SFML\Graphics\Text.hpp>
#include<vector>
#include <sstream>
#include"Draw.h"
#pragma warning(disable : 4996)// bo uwa¿a mój setColor jako przestarza³y
using namespace std;


 void Draw_score::draww(sf::RenderWindow& window, int result)
{
	 sf::Text score;
	 stringstream ss;
	 ss << "Zdobyte punkty:\n" << result;
	 sf::Font arial;
	 arial.loadFromFile("arial.ttf");
	 score.setFont(arial);
	 score.setString(ss.str());
	 score.setPosition(400, 80);
	 score.setColor(sf::Color::White);
	 window.draw(score);
}
 
 
 sf::Sprite Draw_map::draw()
 {
	 background.loadFromFile("background1.png");
	 sf::Sprite spr(background);
	 return spr;
	
 }
