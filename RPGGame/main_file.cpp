// RPGGame
// main.cpp
// Justyn Durnford
// Created on 4/27/2020
// Last updated on 5/27/2020

#include "Type.hpp"

#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::VideoMode;
using sf::Style::Resize;
using sf::Style::Close;
using sf::Event;
using sf::Color;
using sf::Texture;
using sf::Sprite;

#include <string>
using std::string;
using std::to_string;

#include <cctype>
using std::isdigit;

#include <iostream>
using std::cout;
using std::endl;

string modify(string& str)
{
	string new_str = "";

	for (unsigned char i = 0; i < 4; ++i)
	{
		if (isdigit(str[i]))
		{
			new_str += str[i];
		}
		else
		{
			new_str += " || ";
			break;
		}
	}

	for (unsigned char i = 0; i < types.size(); ++i)
	{

	}


}

int main()
{
	/*RenderWindow window(VideoMode(1000, 800), "Pokemon", Resize + Close);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			
		}

		window.clear(Color::Black);



		window.display();
	}*/



	return 0;
}