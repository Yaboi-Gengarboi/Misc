// RPGGame
// main.cpp
// Justyn Durnford
// Created on 4/27/2020
// Last updated on 5/30/2020

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
using std::size_t;
using std::to_string;

#include <cctype>
using std::isdigit;

#include <memory>
using std::unique_ptr;
using std::make_unique;

#include <iostream>
using std::cout;
using std::endl;



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

	for (unsigned int i = 42; i <= 649; ++i)
	{
		if (i < 100)
			cout << '0';

		cout << i << " | " << endl;
	}

	return 0;
}