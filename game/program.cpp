#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include <vector>

using namespace std;

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
   
    load_bitmap("space", "space.jpg");
    load_bitmap("star", "star.png");
    load_bitmap("coin", "coin.png");
    load_bitmap("full", "full.png");
    load_bitmap("fuel", "fuel.png");
    load_bitmap("map", "map.jpeg");
    load_sound_effect("spacesound", "spacesound.mp3");
}

void draw_resources()
{
    
    draw_bitmap("space", 0,0, option_to_screen(option_scale_bmp(1.95, 1.95)));


    draw_bitmap("star", 453, 876);
    draw_bitmap("star", 846, 874);
    draw_bitmap("star", 235, 460);
    draw_bitmap("star", 765, 645);
    draw_bitmap("star", 400, 134);
    draw_bitmap("star", 525, 758);

    draw_bitmap("fuel", 450, 250, option_to_screen(option_scale_bmp(1, 1)));
    draw_bitmap("fuel", 200, 230);
    draw_bitmap("fuel", 456, 950, option_to_screen(option_scale_bmp(1, 1)));
    draw_bitmap("fuel", 573, 323, option_to_screen(option_scale_bmp(1, 1)));
    draw_bitmap("fuel", 183, 483);
    draw_bitmap("fuel", 472, 574, option_to_screen(option_scale_bmp(1, 1)));

    draw_bitmap("coin", 544, 766, option_to_screen(option_scale_bmp(1, 1)));
    draw_bitmap("coin", 789, 123);
    draw_bitmap("coin", 145, 135, option_to_screen(option_scale_bmp(1, 1)));
    draw_bitmap("coin", 644, 787, option_to_screen(option_scale_bmp(1, 1)));
    draw_bitmap("coin", 789, 878);
    draw_bitmap("coin", 354, 578, option_to_screen(option_scale_bmp(1, 1)));

    draw_bitmap("map", 700, 10, option_to_screen(option_scale_bmp(0.75, 0.75)));
    draw_bitmap("full", 20, 20, option_to_screen(option_scale_bmp(1, 1)));

    draw_text("COIN: ", COLOR_RED, 5, 60, option_to_screen(option_scale_bmp(2, 2)));
    draw_text("LEVEL: ", COLOR_RED, 5, 70, option_to_screen(option_scale_bmp(2, 2)));
    play_sound_effect("spacesound");
}

/**
 * Entry point.
 * 
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Lost In Space", 800, 800);
    load_resources();

    player_data player;
    player = new_player();

    while ( not quit_requested() )
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(player);

        // Perform movement and update the camera
        update_player(player);

        // Redraw everything
        clear_screen(COLOR_BLACK);
        
        load_resources();
        draw_resources();

        draw_text("SCORE: ", COLOR_WHITE, 0, 0, option_to_screen());
        draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_WHITE, 0, 10, option_to_screen());

        // including something stationary - it doesn't move
        fill_rectangle(COLOR_WHITE, 400, 400, 10, 10);

        // as well as the player who can move
        draw_player(player);

        refresh_screen(60);
    }

    return 0;
}
