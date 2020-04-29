#include <windows.h>
#include <iostream>
#include <conio.h>
#include "game.h"

using namespace std;

void game::watekGry()		///TODO zrobiæ pod ESC restowanie ca³ej mapy i ustawianie od nowa :P
{
	bool ok = true;
	do 	{
		ok = przygotowanieGry(gracze(G1));
	} while (!ok);
	do {
		ok = przygotowanieGry(gracze(G2));
	} while (!ok);
}

bool game::przygotowanieGry(gracze a)
{
	duchy.czysc();
	for (int j = 0; j < 10; ++j)
	{
		system("cls");
		if (a == gracze(G1))
		{
			cout << " Graczu 1 ustaw swoj statek na mapie : " << endl;
			cout << endl;
		}
		else
		{
			cout << " Graczu 2 ustaw swoj statek na mapie : " << endl;
			cout << endl;
		}

		int miejsce_ustawienia = 10 - (a == gracze(G1) ? s_g1[j] : s_g2[j]).getIlosc_modulow();

		umiescStatek(9, miejsce_ustawienia, a, j, kat(PION), true);

		wyswietlWrunkowo(duchy, (a == gracze(G1) ? mST_G1 : mST_G2), ' ');

		cout << endl;
		cout << "Poruszaj sie STRZALKAMI. \nZatwierdzaj ENTEREM. \nObracaj R \nAnuluj cale ustawienie ESC." << endl;

		for (;;)
		{
			int xo, yo;
			if ((a == gracze(G1) ? s_g1[j] : s_g2[j]).getX() < 0)
				xo = 9;
			else
				xo = (a == gracze(G1) ? s_g1[j] : s_g2[j]).getX();
			if ((a == gracze(G1) ? s_g1[j] : s_g2[j]).getY() < 0)
				yo = 9;
			else
				yo = (a == gracze(G1) ? s_g1[j] : s_g2[j]).getY();

			kat r = (a == gracze(G1) ? s_g1[j] : s_g2[j]).getUstawienie();

			bool ustawiony = false;
			int lawisz = 0;
			lawisz = getch();
			switch (lawisz)
			{
			case 72:	//góra
			{
				if (yo - 1 >= 0)
				{
					duchy.czysc();
					umiescStatek(xo, yo - 1, a, j, r, true);
				}
				break;
			}
			case 80:	//dó³
			{
				if (r == kat(POZIOM) && yo + 1 < 10)
				{
					duchy.czysc();
					umiescStatek(xo, yo + 1, a, j, r, true);
				}
				else if (r == kat(PION) && yo + (a == gracze(G1) ? s_g1[j] : s_g2[j]).getIlosc_modulow() < 10)
				{
					duchy.czysc();
					umiescStatek(xo, yo + 1, a, j, r, true);
				}
				break;
			}
			case 77:	//prawo
			{
				if (r == kat(PION) && xo + 1 < 10)
				{
					duchy.czysc();
					umiescStatek(xo + 1, yo, a, j, r, true);
				}
				else if(r == kat(POZIOM) && xo + (a == gracze(G1) ? s_g1[j] : s_g2[j]).getIlosc_modulow() < 10)
				{
					duchy.czysc();
					umiescStatek(xo + 1, yo, a, j, r, true);
				}
				break;
			}
			case 75:	//lewo
			{
				if (xo - 1 >= 0)
				{
					duchy.czysc();
					umiescStatek(xo - 1, yo, a, j, r, true);
				}
				break;
			}
			case 114:	//obrót
			{
				if (r == kat(PION) && xo + (a == gracze(G1) ? s_g1[j] : s_g2[j]).getIlosc_modulow() <= 10)
				{
					duchy.czysc();
					r = kat(POZIOM);
					umiescStatek(xo, yo, a, j, r, true);
				}
				else if (r == kat(POZIOM) && yo + (a == gracze(G1) ? s_g1[j] : s_g2[j]).getIlosc_modulow() <= 10)
				{
					duchy.czysc();
					r = kat(PION);
					umiescStatek(xo, yo, a, j, r, true);
				}
				break;
			}
			case 13:	//postawienie
			{
				duchy.czysc();
				if (sprawdzCzyMozliwyRuch(xo, yo, a, j, r))
				{
					umiescStatek(xo, yo, a, j, r, false);
					ustawiony = true;
				}
				else
				{
					cout << "Ruch niemozliwy!!!" << endl;
					umiescStatek(xo, yo, a, j, r, true);
				}

				break;
			}
			case 27:	//anulowanie dodawania
			{
				return false;
			}
			}

			if (ustawiony)
				break;

			system("cls");
			if (a == gracze(G1))
			{
				cout << " Graczu 1 ustaw swoj statek na mapie : " << endl;
				cout << endl;
			}
			else
			{
				cout << " Graczu 2 ustaw swoj statek na mapie : " << endl;
				cout << endl;
			}
			wyswietlWrunkowo(duchy, (a == gracze(G1) ? mST_G1 : mST_G2), ' ');

			cout << endl;
			cout << "Poruszaj sie STRZALKAMI. \nZatwierdzaj ENTEREM. \nObracaj R. \nAnuluj cale ustawienie ESC." << endl;
		}
	}


	cout << endl;
	return true;
}
void game::umiescStatek(unsigned int x, unsigned int y, gracze a, unsigned int indeksStatku, kat r, bool duch)
{
	int n, wiodaca, niewiodaca;
	n = (a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).getIlosc_modulow();
	if (r == kat(PION))
	{
		wiodaca = y;
		niewiodaca = x;
	}
	else
	{
		wiodaca = x;
		niewiodaca = y;
	}

	for (int i = wiodaca; i < (wiodaca + n); ++i)
	{
		int wspolrzedna_x, wspolrzedna_y;
		if (r == kat(PION))
		{
			wspolrzedna_x = x;
			wspolrzedna_y = i;
		}
		else
		{
			wspolrzedna_x = i;
			wspolrzedna_y = y;
		}
		if (!duch)
			(a == gracze(G1) ? mST_G1 : mST_G2).setPole(wspolrzedna_y, wspolrzedna_x, pole(STATEK));
		else
			duchy.setPole(wspolrzedna_y, wspolrzedna_x, pole(USTAWIANY));
	}
	(a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).setXYUS(x, y, r, duch);
}
void game::umiescPuste(unsigned int x, unsigned int y, gracze a, unsigned int indeksStatku, kat r, bool duch)
{
	int n, wiodaca, niewiodaca;
	if (r == 0)
	{
		n = (a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).getIlosc_modulow();
		wiodaca = y;
		niewiodaca = x;
	}
	else
	{
		n = (a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).getIlosc_modulow();
		wiodaca = x;
		niewiodaca = y;
	}

	for (int i = wiodaca; i < (wiodaca + n); ++i)
	{
		int wspolrzedna_x, wspolrzedna_y;
		if (r == 0)
		{
			wspolrzedna_x = x;
			wspolrzedna_y = i;
		}
		else
		{
			wspolrzedna_x = i;
			wspolrzedna_y = y;
		}
		(a == gracze(G1) ? mST_G1 : mST_G2).setPole(wspolrzedna_x, wspolrzedna_y, pole(PUSTE));
	}
}
bool game::sprawdzCzyMozliwyRuch(unsigned int x, unsigned int y, gracze a, unsigned int indeksStatku, kat r)
{

	//cout << "tutaj" << endl;
	/** <BLOK PRE>  *
	*   sprawdzanie czy nie wyszlismy za mape u gory   */
	if (x > 9 || y > 9)
		return false;
	cout << "BLOK PRE -> KONIEC" << endl;
	/** </BLOK PRE>*/

	unsigned int n = 0;
	unsigned int tym_dl = 1;
	unsigned int tym_sz = 1;

	if (r == kat(PION))
	{
		tym_dl = (a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).getIlosc_modulow();
		n = tym_dl;
	}
	else
	{
		tym_sz = (a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).getIlosc_modulow();
		n = tym_sz;
	}

	int ix_start = ((int)x - 1);
	int ix_warunek = x + tym_sz;

	for (int ix = ix_start; ix <= ix_warunek; ++ix)
	{
		int iy_start = ((int)y - 1);
		int iy_warunek = y + tym_dl;

		for (int iy = iy_start; iy <= iy_warunek; ++iy)
		{

			///cout << "POLE [" << ix << "][" << iy << "]" << endl;
			if (ix == x + 1 && iy == y + 1) cout << "to mnie interesuje!" << endl;
			if (ix > 9 || iy > 9)
				continue;
			/** <BLOK I>
			*   sprawdanie czy nie wyjdziemy za mape    */
			for (int k = 0; k < n; ++k)
			{
				if (r == kat(PION))
				{
					if (y + k > 9 || y + k < 0)
						return false;

					if (x > 9 || x < 0)
						return false;
				}
				else
				{
					if (x + k > 9 || x + k < 0)
						return false;

					if (y > 9 || y < 0)
						return false;
				}
			}
			/** </BLOK I>  */
			///cout << "Blok I -> KONIEC" << endl;


			/** <BLOK II>
			*   sprawdzanie czy pole nie jest poprzednim polozeniem tego samego statku  */
			/*bool b = false;
			for(int k = 0; k < n; ++k)
			{
			if(r == kat(PION))
			{
			if(ix == (a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).getX()
			&& iy == ((a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).getY() + k))
			b = true;
			}
			else
			{
			if(ix == ((a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).getX() + k)
			&& iy == (a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).getY())
			b = true;
			}
			}
			if(b)
			continue;*/
			/** </BLOK II> */
			///cout << "Blok II -> KONIEC" << endl;

			/**<BLOK III>
			*   sprawdzanie czy obecnie sprawdzane pole nie jest rogiem wspolnym dla polozen -> niesprawdzane   */
			if ((int)x - 1 >= 0 && (int)y - 1 >= 0 && ix == (x - 1) && iy == (y - 1))
				continue;
			/** </BLOK III>   */
			///cout << "Blok III -> KONIEC" << endl;

			/** <BLOK IV>
			*   sprawdzanie czy obecne pole nie jest rogiem statku -> niesprawdzane */
			if (r == kat(PION))
			{
				if ((int)y - 1 >= 0 && ix == (x + 1) && iy == (y - 1))
				{
					///cout << "Pierwszy" << endl;
					continue;
				}
				else if ((int)x - 1 >= 0 && ix == (x - 1) && iy == (y + n))
				{
					///cout << "y = " << y << " n = " << n << "y + n = " << y + n << " Drugi" << endl;
					continue;
				}
				else if (ix == (x + 1) && iy == (y + n))
				{
					///cout << "Trzeci" << endl;
					continue;
				}
			}
			if (r == kat(POZIOM))
			{
				 if ((int)y - 1 >= 0 && ix == (x + n) && iy == (y - 1))
					continue;
				else if (ix == (x + n) && iy == (y + 1))
					continue;
				else if ((int)x - 1 >= 0 && (ix == (x - 1) && iy == (y + 1)))
					continue;
			}
			/** </BLOK IV>*/
			///cout << "Blok IV -> KONIEC" << endl;

			/** <BLOK V>
			*   sprawdzanie czy obecnie sprawdzane pole jest puste  */
			if (ix >= 0 && iy >= 0 && ix < 10 && iy < 10 && (a == gracze(G1) ? mST_G1 : mST_G2).getPole(iy, ix) != pole(PUSTE))
				return false;
			/** </BLOK V>*/
			///cout << "Blok V -> KONIEC" << endl;
		}
	}

	return true;
}
void game::wyswietlWrunkowo(mapa m1, mapa m2, char warunek)
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
				if (m1.getPole(i, j) != warunek)
					cout << (char)m1.getPole(i, j) << endl;
				else
					cout << (char)m2.getPole(i, j) << endl;

			}
			else if (m1.getPole(i, j) != warunek)
				cout << (char)m1.getPole(i, j) << "|";
			else
				cout << (char)m2.getPole(i, j) << "|";

		}
	}
}
