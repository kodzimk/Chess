#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Main.hpp>

#include<math.h>
#include<iostream>
#include<map>
#include<vector>
#include<string>

class Cor {
public:
	int x;
	int y;

	Cor(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};