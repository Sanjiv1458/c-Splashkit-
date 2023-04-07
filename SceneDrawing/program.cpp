#include "splashkit.h"

void draw_anime_scene()
{
    //first opened a big block with clear screen
    //load anime and song anime
    open_window("Sanjiv's Scene Drawing", 1500, 1500);
    clear_screen(COLOR_WHITE);
    load_bitmap("apple", "apple.png");
    load_bitmap("car", "car.png");
    load_sound_effect("Laughing", "Laughing.wav");
    // now drawing my animation and play with song
    clear_screen(COLOR_BLACK);
    draw_bitmap("apple", 500, 800);
    refresh_screen(60);
    draw_bitmap("car", 100, 100);
    refresh_screen(60);
    play_sound_effect("Laughing");
    delay(5000);
}
    // drawing another scene with sound
    void draw_another_scene()
{
    load_sound_effect("Laughing", "Laughing.wav");
    clear_screen(COLOR_WHITE);
    fill_ellipse(COLOR_BRIGHT_GREEN, 0, 400, 800, 400);
    fill_rectangle(COLOR_GRAY, 300, 300, 200, 200);
    fill_triangle(COLOR_RED, 250, 300, 400, 150, 550, 300);
    refresh_screen(60);
    play_sound_effect("Laughing");
    delay(5000);
}
    // combining both function or declaration to main function
    int main()
{
    draw_anime_scene();
    draw_another_scene();
    write_line("The End");
    write_line("Made by Sanjiv");
    return 0;
}

// Bitmap Scene Play video: https://drive.google.com/file/d/1dFISXJzQH9pOaLmsbMX2zzdKPJN5B2Pj/view?usp=sharing