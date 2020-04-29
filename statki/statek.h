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
	If you want to contact me write: suchyba.bq@gmail.com
*/
#ifndef STATEK_H_INCLUDED
#define STATEK_H_INCLUDED
enum kat { PION, POZIOM };

class statek
{
private:
	unsigned int x, y, ilosc_modulow;
	kat ustawienie;
	bool stoi;
public:
	statek(unsigned int a = 0, unsigned int b = 0, unsigned int c = 0, bool d = false);
	unsigned int getX() const;
	unsigned int getY() const;
	unsigned int getIlosc_modulow() const;
	kat getUstawienie() const;
	bool getStoi() const;

	void setX(unsigned int a);
	void setY(unsigned int a);
	void setXY(unsigned int a, unsigned int b);
	void setXYU(unsigned int a, unsigned int b, kat r);
	void setXYUS(unsigned int a, unsigned int b, kat r, bool s);
	void setIlosc_modulow(unsigned int a);
	void setUstawienie(kat r);
	void setStoi(bool a);
};


#endif // STATEK_H_INCLUDED
