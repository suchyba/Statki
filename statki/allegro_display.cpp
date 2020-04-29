#include "allegro_display.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <iostream>

using namespace std;


allegro_display::allegro_display()
{
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();

    for(int i = 0; i < 10; ++i)
        bitmapy[i] = NULL;
}
bool allegro_display::create_display(unsigned int sz, unsigned int wy)
{
    cout << "Creating display at size " << sz << "/" << wy << "...";
    display = al_create_display(sz, wy);
    if(display)
    {
        cout << " done" << endl;
        return true;
    }
    else
    {
        cout << " failed" << endl;
    }
}
int allegro_display::load_bitmap(string file)
{
    cout << "Loading bitmap from file : " << file << " ...";
    for(int i = 0; i < 20; ++i)
        if(!bitmapy[i])
        {
            bitmapy[i] = al_load_bitmap(file.c_str());
            cout << "done" << endl;
            return i;
        }
    cout << "failed" << endl;
    return -1;
}
ALLEGRO_BITMAP* allegro_display::load_bitmap_at_size(const char *filename, int w, int h)
{
    cout << "Scaling bitmap to bitmap object (file: " << filename << "; " << w << "/" << h << " ...";
  ALLEGRO_BITMAP *resized_bmp, *loaded_bmp, *prev_target;

  // 1. create a temporary bitmap of size we want
  resized_bmp = al_create_bitmap(w, h);
  if (!resized_bmp) return NULL;

  // 2. load the bitmap at the original size
  loaded_bmp = al_load_bitmap(filename);
  if (!loaded_bmp)
  {
     al_destroy_bitmap(resized_bmp);
     return NULL;
  }

  // 3. set the target bitmap to the resized bmp
  prev_target = al_get_target_bitmap();
  al_set_target_bitmap(resized_bmp);

  // 4. copy the loaded bitmap to the resized bmp
  al_draw_scaled_bitmap(loaded_bmp,
     0, 0,                                // source origin
     al_get_bitmap_width(loaded_bmp),     // source width
     al_get_bitmap_height(loaded_bmp),    // source height
     0, 0,                                // target origin
     w, h,                                // target dimensions
     0                                    // flags
  );

  // 5. restore the previous target and clean up
  al_set_target_bitmap(prev_target);
    cout << "done" << endl;
  return resized_bmp;
}
ALLEGRO_BITMAP* allegro_display::get_bitmapa(int i) const
{
    return bitmapy[i];
}
void allegro_display::pokarz()
{
    cout << "Showing..." << endl;
    al_flip_display();
}
int allegro_display::load_bitmap(ALLEGRO_BITMAP* bitmapa)
{
    cout << "Loading bitmap from bitmap object...";
    for(int i = 0; i < 20; ++i)
    {
        if(!bitmapy[i])
        {
            bitmapy[i] = bitmapa;
            cout << "done" << endl;
            return i;
        }
    }
    cout << "failed" << endl;
    return -1;
}
void allegro_display::display_bitmap(unsigned int id, unsigned int x, unsigned int y)
{
    cout << "Displaying bitmap with ID : " << id << ", on position [" << x << ", " << y << "]...";
    al_draw_bitmap(bitmapy[id], x, y, 0);
    cout << "done" << endl;
}
void allegro_display::display_bitmap(unsigned int id, unsigned int sr_x, unsigned int sr_y, unsigned int x, unsigned int y, unsigned int r)
{
    cout << "Displaying bitmap (ID: " << id << "), with rotation: " << r << ", with axis on position [" << sr_x << ", " << sr_y << "], on position [" << x << ", " << y << "]...";
    al_draw_rotated_bitmap(bitmapy[id], sr_x, sr_y, x, y, ALLEGRO_PI / r, 0);
    cout << "done" << endl;
}
void allegro_display::clear_to_color(unsigned int r, unsigned int g, unsigned int b)
{
    cout << "Cleaning to color (" << r << ", " << g << ", " << b << ")...";
    al_clear_to_color(al_map_rgb(r, g, b));
    cout << "done" << endl;
}
