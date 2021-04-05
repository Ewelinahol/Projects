#include<iostream>
#include<vector>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System\Clock.hpp>
#include <SFML\Graphics\Text.hpp>

#include<iterator>
#include<memory>
#include"Playing.h"
#include"Title_picture.h"
#include"Draw.h"

using namespace std;

sf::Text Playing::get_score()
{
	return this->score;
}
void Playing::play()
{
	Draw_score scorik;
	Draw_map mapik;
	Titlepng* title = new Titlepng();
	grid* gridd = new grid();
	forward_list<point> xd;
	Title ojej;
	xd = ojej.get_list(title->get_kind(), xd);

	bool  test = false;
	bool found = false;
	this->Szejpik=title->set_shape("tile1.png",0);// wstawienie klocka o kolorze pocz¹tkowym
	
	sf::RenderWindow window(sf::VideoMode{ 700, 900 }, "Tetris");
	sf::Event event;
	forward_list<point> s;


	while (window.isOpen())
	{
		if (test)
		{
			title->set_kind(0 + rand() % 7);
			Title new_tilte;
			xd = new_tilte.get_list(title->get_kind(), xd);


			title->set_colour(0 + rand() % 9);
			this->Szejpik=title->set_shape("tile1.png", title->get_colour());
		
			gridd->set_colour(title->get_colour());
		}
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		window.pollEvent(event);// interakcja ze strony u¿ytkownika 

		if (event.type == sf::Event::Closed)// zamykanie okna
		{
			window.close();
			break;
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			xd = title->update(title->get_kind(), xd, event, gridd);
			title->change_hold(true);// po naciœniêciu klawisza, przyjmujemy ¿e zosta³ on przytrzymany

		}
		else if (event.type == sf::Event::KeyReleased) // sprawdzenie czy uzytkownik upuœci³ klawisz
		{
			title->change_hold(false); //zwalniamy klawisz- mo¿liwosæ jego obrotu lub przesuniêcia w lewo lub prawo

		}
		window.clear();
		window.draw(mapik.draw());

		
		forward_list<point>::iterator iterek = xd.begin();
		test = gridd->checkvalue(xd);
		found = gridd->checkline();
		gridd->collision(xd);
		gridd->checkline();
		title->draw(gridd->get_map(), this->Szejpik, window);
		
		
	

		for (; iterek != xd.end(); iterek++)
		{
			if (timer > far)
			{
				if (test||found)
					break;
				iterek->x += 1;
			}

			this->Szejpik.setPosition(iterek->y * 32, iterek->x * 32);

			window.draw(this->Szejpik);

		}
		scores(window, gridd);
		scorik.draww(window, this->result);

		if (timer > far)
			timer = 0;
		if (gridd->theEnd()) // koniec gry
			break;

		window.display();
		
	}
	delete gridd;
	delete title;
}
void Playing::scores(sf::RenderWindow &window, grid *gridek)// przeliczanie punktów
{
	int temp = gridek->get_found();
	if (temp > 1)
	{
		if(result == 0)
		this->result += 37;
		this->result *= temp;
	}
	else if(temp ==1)
		this->result += 37;
}


