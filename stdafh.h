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

	Cor(int y, int x)
	{
		this->x = x;
		this->y = y;
	}
};