#include "splashkit.h"

void draw_anime_scene()
{
    //first opened a big block with clear screen
    //load anime and song anime
    open_window("lit's Scene Drawing", 1000, 1000);
    clear_screen(COLOR_WHITE);
    load_bitmap("mario", "mario.png");
    load_bitmap("car", "car.png");
    load_sound_effect("Prague", "Prague.wav");
    refresh_screen(60);
    // now drawing my animation and play with song
    clear_screen(COLOR_BLACK);
    draw_bitmap("mario", 100, 100);
    refresh_screen(60);
    draw_bitmap("car", 500, 500);
    refresh_screen(60);
    play_sound_effect("Prague");
    delay(5000);
    refresh_screen(50);
}
int main()
{
   draw_anime_scene();
   write_line("made by litesh grover");
   write_line("the end");
   return 0;
}