#include <windows.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <allegro5/events.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include "game.hpp"
#include "allegro_display.hpp"

using namespace std;

void game::watekGry()
{
    w = new allegro_display();
    w->create_display(1280, 671);
    w->load_bitmap(w->load_bitmap_at_size("resources/backgrounds/back2.png", wielkosc_pola * 11, wielkosc_pola * 11));
    for(int i = 1; i < 5; ++i)
    {
        string scierzka = "resources/boats/statek";
        scierzka += i + 48;
        scierzka += ".png";
        w->load_bitmap(w->load_bitmap_at_size(scierzka.c_str(), wielkosc_pola, wielkosc_pola * i));
        scierzka = "resources/boats/statek";
        scierzka += i + 48;
        scierzka += "_duch.png";
        w->load_bitmap(w->load_bitmap_at_size(scierzka.c_str(), wielkosc_pola, wielkosc_pola * i));
    }

    for(;;)
    {
        if(przygotowanieGry(gracze(G1)))    break;
        else resetujDane(G1);
    }
    for(;;)
    {
        if(przygotowanieGry(gracze(G2)))    break;
        else resetujDane(G2);
    }
}
bool game::przygotowanieGry(gracze a)
{
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());


    int blokada2 = 1;
    for(int i = 0; i < 10; ++i)
    {
        if(blokada2 == 1)
        {
            cout << "ile sie wykonuje" << endl;
            umiescStatek(0, 0, a, i, kat(PION), true);

        if(blokada2 >= 3)    blokada2 = 0;

        bool gotowe = false;
        bool nacisniety = false;
        int blokada = 0;

        while(!gotowe)
        {
            if(blokada == 3)
            {
                blokada = 0;
                nacisniety = false;
            }
            w->clear_to_color(68, 158, 255);
            wyswietlMapeAllegro(a);

            ALLEGRO_EVENT ev;

            al_wait_for_event(event_queue, &ev);

            if(blokada == 0)
            {
                if(ev.type = ALLEGRO_EVENT_KEY_DOWN)
                {
                    switch(ev.keyboard.keycode)
                    {
                    case ALLEGRO_KEY_DOWN:
                    {
                        if(nacisniety == false)
                        {
                            umiescPuste((a == G1 ? s_g1[i] : s_g2[i]).getX(),
                                        (a == G1 ? s_g1[i] : s_g2[i]).getY(), a, i,
                                        (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie(), true);
                            umiescStatek((a == G1 ? s_g1[i] : s_g2[i]).getX(),
                                         (a == G1 ? s_g1[i] : s_g2[i]).getY() + 1, a, i,
                                         (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie(), true);
                            nacisniety = true;
                        }
                        break;
                    }
                    case ALLEGRO_KEY_UP:
                    {
                        if(!nacisniety)
                        {
                            umiescPuste((a == G1 ? s_g1[i] : s_g2[i]).getX(),
                                        (a == G1 ? s_g1[i] : s_g2[i]).getY(), a, i,
                                        (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie(), true);
                            umiescStatek((a == G1 ? s_g1[i] : s_g2[i]).getX(),
                                         (a == G1 ? s_g1[i] : s_g2[i]).getY() - 1, a, i,
                                         (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie(), true);

                            nacisniety = true;
                        }
                        break;
                    }
                    case ALLEGRO_KEY_LEFT:
                    {
                        if(!nacisniety)
                        {
                            umiescPuste((a == G1 ? s_g1[i] : s_g2[i]).getX(),
                                        (a == G1 ? s_g1[i] : s_g2[i]).getY(), a, i,
                                        (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie(), true);
                            umiescStatek((a == G1 ? s_g1[i] : s_g2[i]).getX() - 1,
                                         (a == G1 ? s_g1[i] : s_g2[i]).getY(), a, i,
                                         (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie(), true);
                            nacisniety = true;
                        }
                        break;
                    }
                    case ALLEGRO_KEY_RIGHT:
                    {
                        if(!nacisniety)
                        {
                            umiescPuste((a == G1 ? s_g1[i] : s_g2[i]).getX(),
                                        (a == G1 ? s_g1[i] : s_g2[i]).getY(), a, i,
                                        (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie(), true);
                            umiescStatek((a == G1 ? s_g1[i] : s_g2[i]).getX() + 1,
                                         (a == G1 ? s_g1[i] : s_g2[i]).getY(), a, i,
                                         (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie(), true);
                            nacisniety = true;
                        }
                        break;
                    }
                    case ALLEGRO_KEY_ENTER:
                    {
                        if(!nacisniety)
                        {
                            if(sprawdzCzyMozliwyRuch((a == G1 ? s_g1[i] : s_g2[i]).getX(),
                                                     (a == G1 ? s_g1[i] : s_g2[i]).getY(), a, i,
                                                     (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie()))
                            {
                                umiescPuste((a == G1 ? s_g1[i] : s_g2[i]).getX(),
                                            (a == G1 ? s_g1[i] : s_g2[i]).getY(), a, i,
                                            (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie(), true);
                                umiescStatek((a == G1 ? s_g1[i] : s_g2[i]).getX(),
                                             (a == G1 ? s_g1[i] : s_g2[i]).getY(), a, i,
                                             (a == G1 ? s_g1[i] : s_g2[i]).getUstawienie(), false);
                                nacisniety = true;
                            }
                        }
                        gotowe = true;
                        break;
                    }
                    }
                }
            }
            ++blokada;
        }
        ++blokada2;
        //getch();
        w->clear_to_color(68, 158, 255);
        wyswietlMapeAllegro(a);
    }
    }

    /*w->clear_to_color(68, 158, 255);
    wyswietlMapeAllegro(a);
    getch();*/

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
            (a == gracze(G1) ? mST_G1 : mST_G2).setPole(wspolrzedna_x, wspolrzedna_y, pole(STATEK));
        else
            duchy.setPole(wspolrzedna_x, wspolrzedna_y, pole(USTAWIANY));
    }
    (a == gracze(G1) ? s_g1[indeksStatku] : s_g2[indeksStatku]).setXYUS(x, y, r, !duch);
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

            /**<BLOK III>
            *   sprawdzanie czy obecnie sprawdzane pole nie jest rogiem wspolnym dla polozen -> niesprawdzane   */
            if ((int)x - 1 >= 0 && (int)y - 1 >= 0 && ix == (x - 1) && iy == (y - 1))
                continue;
            /** </BLOK III>   */

            /** <BLOK IV>
            *   sprawdzanie czy obecne pole nie jest rogiem statku -> niesprawdzane */
            if (r == kat(PION))
            {
                if ((int)y - 1 >= 0 && ix == (x + 1) && iy == (y - 1))
                {
                    continue;
                }
                else if ((int)x - 1 >= 0 && ix == (x - 1) && iy == (y + n))
                {
                    continue;
                }
                else if (ix == (x + 1) && iy == (y + n))
                {
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

            /** <BLOK V>
            *   sprawdzanie czy obecnie sprawdzane pole jest puste  */
            if (ix >= 0 && iy >= 0 && ix < 10 && iy < 10 && (a == gracze(G1) ? mST_G1 : mST_G2).getPole(ix, iy) != pole(PUSTE))
                return false;
            /** </BLOK V>*/
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
void game::resetujDane(gracze a)
{
    for(int i = 0; i < 10; ++i)
    {
        (a == G1 ? s_g1[i] : s_g2[i]).setXYUS(-1, -1, PION, false);
        (a == G1 ? mTR_G1 : mTR_G2).czysc();
        (a == G1 ? mST_G1 : mST_G2).czysc();
    }
}
int game::getIloscModulowByXY(unsigned int x, unsigned int y, bool ustawiony, gracze a)  const
{
    for(int i = 0; i < 10; ++i)
    {
        if(((a == gracze(G1) ? s_g1[i] : s_g2[i]).getX() == x) && ((a == gracze(G1) ? s_g1[i] : s_g2[i]).getY() == y) && ((a == gracze(G1) ? s_g1[i] : s_g2[i]).getStoi() == ustawiony))
            return (a == gracze(G1) ? s_g1[i] : s_g2[i]).getIlosc_modulow();
    }
    return -1;
}
int game::getRotationByXY(unsigned int x, unsigned int y, bool ustawiony, gracze a) const
{
    for(int i = 0; i < 10; ++i)
    {
        if(((a == gracze(G1) ? s_g1[i] : s_g2[i]).getX() == x) && ((a == gracze(G1) ? s_g1[i] : s_g2[i]).getY() == y) && ((a == gracze(G1) ? s_g1[i] : s_g2[i]).getStoi() == ustawiony))
            return (a == gracze(G1) ? s_g1[i] : s_g2[i]).getUstawienie();
    }
    return -1;
}
void game::wyswietlMapeAllegro(gracze a)
{
    w->display_bitmap(0, 304, 0);
    for(int iy = 0; iy < 10; ++iy)
    {
        for(int ix = 0; ix < 10; ++ix)
        {
            if((a == gracze(G1) ? mST_G1 : mST_G2).getPole(ix, iy) == pole(STATEK))
            {
                switch(getIloscModulowByXY(ix, iy, true, a))
                {
                case 1:
                {
                    if(getRotationByXY(ix, iy, true, a) == kat(PION))
                    {
                        w->display_bitmap(1, p_x + (ix * wielkosc_pola), p_y + (iy * wielkosc_pola));
                        w->pokarz();
                    }
                    else
                    {
                        int srodekX = (wielkosc_pola / 2), srodekY = (wielkosc_pola / 2);
                        w->display_bitmap(1, srodekX, srodekY, p_x + (ix * wielkosc_pola) + srodekX + 1, p_y + (iy * wielkosc_pola) + srodekY + 1, 2);
                        w->pokarz();
                    }
                    break;
                }
                case 2:
                {
                    if(getRotationByXY(ix, iy, true, a) == kat(PION))
                    {
                        w->display_bitmap(3, p_x + (ix * wielkosc_pola), p_y + (iy * wielkosc_pola));
                        w->pokarz();
                    }
                    else
                    {
                        int srodekX = wielkosc_pola, srodekY = (wielkosc_pola / 2);
                        w->display_bitmap(3, srodekX, srodekY, p_x + (ix * wielkosc_pola) + srodekX + 1 + wielkosc_pola / 2, p_y + (iy * wielkosc_pola) + srodekY * 2 + 1, 2);
                        w->pokarz();
                    }
                    break;
                }
                case 3:
                {
                    if(getRotationByXY(ix, iy, true, a) == kat(PION))
                    {
                        w->display_bitmap(5, p_x + (ix * wielkosc_pola), p_y + (iy * wielkosc_pola));
                        w->pokarz();
                    }
                    else
                    {
                        int srodekX = (wielkosc_pola / 2) * 3, srodekY = (wielkosc_pola / 2);
                        w->display_bitmap(5, srodekX, srodekY, p_x + (ix * wielkosc_pola) + srodekX + 1 + wielkosc_pola + 1, p_y + (iy * wielkosc_pola) + srodekY * 3, 2);
                        w->pokarz();
                    }
                    break;
                }
                case 4:
                {
                    if(getRotationByXY(ix, iy, true, a) == kat(PION))
                    {
                        w->display_bitmap(7, p_x + (ix * wielkosc_pola), p_y + (iy * wielkosc_pola));
                        w->pokarz();
                    }
                    else
                    {
                        int srodekX = wielkosc_pola * 2, srodekY = (wielkosc_pola / 2);
                        w->display_bitmap(7, srodekX, srodekY, p_x + (ix * wielkosc_pola) + srodekX + 1 + (wielkosc_pola / 2) * 3 + 1, p_y + (iy * wielkosc_pola) + srodekY * 4 + 2, 2);
                        w->pokarz();
                    }
                    break;
                }
                case -1:
                {
                    //oznacza ze jest to jakis kolejny element statku
                    break;
                }
                }
            }
        }
    }
    for(int iy = 0; iy < 10; ++iy)
    {
        for(int ix = 0; ix < 10; ++ix)
        {
            if(duchy.getPole(ix, iy) == pole(USTAWIANY))
            {
                switch(getIloscModulowByXY(ix, iy, false, a))
                {
                case 1:
                {
                    if(getRotationByXY(ix, iy, false, a) == kat(PION))
                    {
                        w->display_bitmap(2, p_x + (ix * wielkosc_pola), p_y + (iy * wielkosc_pola));
                        w->pokarz();
                    }
                    else
                    {
                        int srodekX = (wielkosc_pola / 2), srodekY = (wielkosc_pola / 2);
                        w->display_bitmap(2, srodekX, srodekY, p_x + (ix * wielkosc_pola) + srodekX + 1, p_y + (iy * wielkosc_pola) + srodekY + 1, 2);
                        w->pokarz();
                    }
                    break;
                }
                case 2:
                {
                    if(getRotationByXY(ix, iy, false, a) == kat(PION))
                    {
                        w->display_bitmap(4, p_x + (ix * wielkosc_pola), p_y + (iy * wielkosc_pola));
                        w->pokarz();
                    }
                    else
                    {
                        int srodekX = wielkosc_pola, srodekY = (wielkosc_pola / 2);
                        w->display_bitmap(4, srodekX, srodekY, p_x + (ix * wielkosc_pola) + srodekX + 1 + wielkosc_pola / 2, p_y + (iy * wielkosc_pola) + srodekY * 2 + 1, 2);
                        w->pokarz();
                    }
                    break;
                }
                case 3:
                {
                    if(getRotationByXY(ix, iy, false, a) == kat(PION))
                    {
                        w->display_bitmap(6, p_x + (ix * wielkosc_pola), p_y + (iy * wielkosc_pola));
                        w->pokarz();
                    }
                    else
                    {
                        int srodekX = (wielkosc_pola / 2) * 3, srodekY = (wielkosc_pola / 2);
                        w->display_bitmap(6, srodekX, srodekY, p_x + (ix * wielkosc_pola) + srodekX + 1 + wielkosc_pola + 1, p_y + (iy * wielkosc_pola) + srodekY * 3, 2);
                        w->pokarz();
                    }
                    break;
                }
                case 4:
                {
                    if(getRotationByXY(ix, iy, false, a) == kat(PION))
                    {
                        w->display_bitmap(8, p_x + (ix * wielkosc_pola), p_y + (iy * wielkosc_pola));
                        w->pokarz();
                    }
                    else
                    {
                        int srodekX = wielkosc_pola * 2, srodekY = (wielkosc_pola / 2);
                        w->display_bitmap(8, srodekX, srodekY, p_x + (ix * wielkosc_pola) + srodekX + 1 + (wielkosc_pola / 2) * 3 + 1, p_y + (iy * wielkosc_pola) + srodekY * 4 + 2, 2);
                        w->pokarz();
                    }
                    break;
                }
                case -1:
                {
                    //oznacza ze jest to jakis kolejny element statku
                    break;
                }
                }
            }
        }
    }
}
