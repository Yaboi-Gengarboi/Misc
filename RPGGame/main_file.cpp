// RPGGame
// main.cpp
// Justyn Durnford
// Created on 4/27/2020
// Last updated on 6/16/2020

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

#include <fstream>
using std::ofstream;

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

	string file = "";

	for (unsigned int i = 1; i <= 621; ++i)
	{
		if (i < 10)
			file += '0';

		if (i < 100)
			file += '0';

		file += to_string(i);

		ofstream fout(file + ".txt");

		file = "";
	}

	return 0;
}