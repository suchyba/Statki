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
#include "statek.hpp"

statek::statek(int a, int b, unsigned int c, bool d) :
	x(a), y(b), ilosc_modulow(c), stoi(d)
{
	ustawienie = PION;
}

int statek::getX() const
{
	return x;
}
int statek::getY() const
{
	return y;
}
unsigned int statek::getIlosc_modulow() const
{
	return ilosc_modulow;
}
kat statek::getUstawienie() const
{
	return ustawienie;
}
bool statek::getStoi()  const
{
	return stoi;
}

void statek::setX(unsigned int a)
{
	x = a;
}
void statek::setY(unsigned int a)
{
	y = a;
}
void statek::setXY(unsigned int a, unsigned int b)
{
	x = a;
	y = b;
}
void statek::setXYU(unsigned int a, unsigned int b, kat r)
{
	setXY(a, b);
	ustawienie = r;
}
void statek::setIlosc_modulow(unsigned int a)
{
	ilosc_modulow = a;
}
void statek::setUstawienie(kat r)
{
	ustawienie = r;
}
void statek::setStoi(bool a)
{
	stoi = a;
}
void statek::setXYUS(unsigned int a, unsigned int b, kat r, bool s)
{
	setXYU(a, b, r);
	stoi = s;
}
