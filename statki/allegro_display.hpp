#ifndef ALLEGRO_DISPLAY_H_INCLUDED
#define ALLEGRO_DISPLAY_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <string>
using namespace std;

class allegro_display
{
private:
    ALLEGRO_BITMAP* bitmapy[20];
    ALLEGRO_DISPLAY* display;
public:
    allegro_display(void);
    bool create_display(unsigned int, unsigned int);
    int load_bitmap(string); // <- zwraca indeks w którym zapisana jest bitmapa
    int load_bitmap(ALLEGRO_BITMAP*);
    ALLEGRO_BITMAP* load_bitmap_at_size(const char*, int, int);
    void pokarz(void);
    void display_bitmap(unsigned int, unsigned int, unsigned int);
    void display_bitmap(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    void clear_to_color(unsigned int, unsigned int, unsigned int);

    ALLEGRO_BITMAP* get_bitmapa(int) const;
};





#endif // ALLEGRO_DISPLAY_H_INCLUDED
