/*
	Statki game on Allegro 5 game engine
	Copyright (C) 2020  Bart³omiej Suchecki

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Affero General Public License as
	published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <iostream>
#include "mapa.h"

using namespace std;

mapa::mapa()
{
	for (int i = 0; i < 10; ++i)\
	{
		for (int j = 0; j < 10; ++j)
			mapaTablica[i][j] = pole(PUSTE);
	}
}

pole mapa::getPole(unsigned int x, unsigned int y)  const
{
	return mapaTablica[y][x];
}

void mapa::setPole(unsigned int x, unsigned int y, pole a)
{
	mapaTablica[y][x] = a;
}

void mapa::wyswietlMape()
{
	cout << endl;
	cout << " |0|1|2|3|4|5|6|7|8|9" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << (char)(65 + i) << "|";
		for (int j = 0; j < 10; ++j)
		{
			if (j == 9)
			{
				cout << (char)mapaTablica[i][j] << endl;
			}
			else            cout << (char)mapaTablica[i][j] << "|";
		}
	}
}
void mapa::czysc()
{
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			mapaTablica[i][j] = pole(PUSTE);
}
