#ifndef STATEK_H_INCLUDED
#define STATEK_H_INCLUDED
enum kat { PION, POZIOM };

class statek
{
private:
	int x, y;
	unsigned int ilosc_modulow;
	kat ustawienie;
	bool stoi;
public:
	statek(int a = -1, int b = -1, unsigned int c = 0, bool d = false);
	int getX() const;
	int getY() const;
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
