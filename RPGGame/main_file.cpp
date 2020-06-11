// RPGGame
// main.cpp
// Justyn Durnford
// Created on 4/27/2020
// Last updated on 6/10/2020

#include "Matrix.hpp"

#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::VideoMode;
using sf::Style::Resize;
using sf::Style::Close;
using sf::Event;
using sf::Color;
using sf::Texture;
using sf::Sprite;

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

	UChar_Matrix matrix(5, 5);
	unsigned char i = 0;

	for (unsigned int r = 0; r < matrix.row(); ++r)
	{
		for (unsigned int c = 0; c < matrix.col(); ++c)
		{
			matrix.set(r, c, i);
			++i;
		}
	}

	cout << matrix.toString() << endl;

	return 0;
}