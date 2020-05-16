// Chess
// main.cpp
// Justyn Durnford
// Created on 5/14/2020
// Last updated on 5/14/2020

#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::VideoMode;
using sf::Texture;
using sf::Sprite;
using sf::Event;
using sf::Vector2i;
using sf::Vector2f;
using sf::Mouse;
using sf::IntRect;

#include <string>
using std::string;

#include <array>
using std::array;

#include <ctime>

#include <cmath>
using std::abs;

#include <iostream>
using std::cout;
using std::endl;

unsigned char size = 56;
Vector2f offset(28, 28);

array<Sprite, 32> sprites;
string position = "";

array<array<char, 8>, 8> board =
{
	-1, -2, -3, -4, -5, -3, -2, -1,
	-6, -6, -6, -6, -6, -6, -6, -6,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 6,  6,  6,  6,  6,  6,  6,  6,
	 1,  2,  3,  4,  5,  3,  2,  1
};

string toChessNote(Vector2f p)
{
	string str = "";
	str += char(p.x / size + 97);
	str += char(7 - p.y / size + 49);
	return str;
}

Vector2f toCoord(char a, char b)
{
	int x = int(a) - 97;
	int y = 7 - int(b) + 49;
	return Vector2f(x * size, y * size);
}

void move(string str)
{
	Vector2f oldPos = toCoord(str[0], str[1]);
	Vector2f newPos = toCoord(str[2], str[3]);

	for (int i = 0; i < 32; ++i)
		if (sprites[i].getPosition() == newPos) sprites[i].setPosition(-100, -100);

	for (int i = 0; i < 32; ++i)
		if (sprites[i].getPosition() == oldPos) sprites[i].setPosition(newPos);

	// castling        // if the king didn't move
	if (str == "e1g1") if (position.find("e1") == -1) move("h1f1");
	if (str == "e8g8") if (position.find("e8") == -1) move("h8f8");
	if (str == "e1c1") if (position.find("e1") == -1) move("a1d1");
	if (str == "e8c8") if (position.find("e8") == -1) move("a8d8");
}

void loadPosition()
{
	int k = 0;
	for (char i = 0; i < 8; ++i)
	{
		for (char j = 0; j < 8; ++j)
		{
			char n = board[i][j];

			if (!n)
				continue;

			char x = abs(n) - 1;
			char y = n > 0 ? 1 : 0;

			sprites[k].setTextureRect(IntRect(size * x, size * y, size, size));
			sprites[k].setPosition(size * j, size * i);
			++k;
		}
	}

	for (int i = 0; i < position.length(); i += 5)
		move(position.substr(i, 4));
}

int main()
{
	RenderWindow window(VideoMode(500, 500), "Chess");

	Texture t1;
	if (!t1.loadFromFile("Pieces/Pawn_White.png"))
	{
		cout << "Error: Could not find file: Pawn_White.png\n";
		return -1;
	}

	Sprite s1(t1);

	bool isMove = false;
	float dx = 0, dy = 0;

	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			if (e.type == Event::MouseButtonPressed)
			{
				if (e.key.code == Mouse::Left)
				{
					if (s1.getGlobalBounds().contains(pos.x, pos.y))
					{
						isMove = true;
						dx = pos.x - s1.getPosition().x;
						dy = pos.y - s1.getPosition().y;
					}
				}
			}

			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					isMove = false;
				}
			}
		}

		if (isMove)
		{
			s1.setPosition(pos.x - dx, pos.y - dy);
		}

		window.clear();
		window.draw(s1);
		window.display();
	}

	return 0;
}