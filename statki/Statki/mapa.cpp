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
