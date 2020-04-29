#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

enum pole { PUSTE = 32, STATEK = 219, PUDLO = 79, TRAFIENIE = 15, USTAWIANY = 176 };


class mapa
{
private:
	pole mapaTablica[10][10];
public:
	mapa();
	pole getPole(unsigned int x, unsigned int y)    const;
	void setPole(unsigned int x, unsigned int y, pole a);
	void wyswietlMape();
	void czysc();
};


#endif // MAPA_H_INCLUDED
