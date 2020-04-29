#include "statek.h"

statek::statek(unsigned int a, unsigned int b, unsigned int c, bool d) :
	x(a), y(b), ilosc_modulow(c), stoi(d)
{
	ustawienie = PION;
}

unsigned int statek::getX() const
{
	return x;
}
unsigned int statek::getY() const
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
