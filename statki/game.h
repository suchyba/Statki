#include "mapa.h"
#include "statek.h"

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

enum gracze { G1, G2 };

class game
{
private:
	mapa mTR_G1, mST_G1, mTR_G2, mST_G2, duchy;
	statek s_g1[10], s_g2[10];
	int punkty_G1, punty_G2;

	bool przygotowanieGry(gracze);
	void turaGry(gracze);
	void umiescStatek(unsigned int, unsigned int, gracze, unsigned int, kat, bool);
	void umiescPuste(unsigned int, unsigned int, gracze, unsigned int, kat, bool);
	bool sprawdzCzyMozliwyRuch(unsigned int, unsigned int, gracze, unsigned int, kat);
	void wyswietlWrunkowo(mapa, mapa, char);
	void resetujDane(gracze);

public:
	/** @name constructor */
	game()
	{
		s_g1[0] = statek(-1, -1, 1);
		s_g1[1] = statek(-1, -1, 1);
		s_g1[2] = statek(-1, -1, 1);
		s_g1[3] = statek(-1, -1, 1);

		s_g1[4] = statek(-1, -1, 2);
		s_g1[5] = statek(-1, -1, 2);
		s_g1[6] = statek(-1, -1, 2);

		s_g1[7] = statek(-1, -1, 3);
		s_g1[8] = statek(-1, -1, 3);

		s_g1[9] = statek(-1, -1, 4);


		s_g2[0] = statek(-1, -1, 1);
		s_g2[1] = statek(-1, -1, 1);
		s_g2[2] = statek(-1, -1, 1);
		s_g2[3] = statek(-1, -1, 1);

		s_g2[4] = statek(-1, -1, 2);
		s_g2[5] = statek(-1, -1, 2);
		s_g2[6] = statek(-1, -1, 2);

		s_g2[7] = statek(-1, -1, 3);
		s_g2[8] = statek(-1, -1, 3);

		s_g2[9] = statek(-1, -1, 4);

		mTR_G1 = mapa();
		mST_G1 = mapa();
		mTR_G2 = mapa();
		mST_G2 = mapa();

		duchy = mapa();

		punkty_G1 = 0;
		punty_G2 = 0;
	}
	/** @name main game thread */
	void watekGry();

};




#endif // GAME_H_INCLUDED
