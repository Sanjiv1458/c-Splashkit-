#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include "lost_in_space.h"
#include <vector>

using namespace std;

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
    load_bitmap("empty", "empty.png");
    load_bitmap("space", "space.jpg");
    load_bitmap("map", "map.jpeg");
    load_bitmap("purple_bar", "purple_bar.png");
    load_bitmap("green_bar_lines", "green_bar_lines.png");
}

void draw_resources()
{
    draw_bitmap("space", 0,0, option_to_screen(option_scale_bmp(1.95, 1.95)));
    draw_bitmap("map", 700, 10, option_to_screen(option_scale_bmp(0.75, 0.75)));
    draw_bitmap("coin", 5, 190, option_to_screen());
    draw_bitmap("heart", 5, 260, option_to_screen());
    draw_bitmap("diamond", 5, 330, option_to_screen());
    draw_bitmap("shield", 5, 400, option_to_screen());
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

    game_data game;
    game = new_game();
    

    while (not quit_requested())
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(game.player);

        // Perform movement and update the camera
        update_game(game);

        // Redraw everything
        clear_screen(COLOR_BLACK);
        
        draw_resources();
    
        double percentage = (LEVEL_TIME - timer_ticks("TIMER"));
        double percentage_remaining = percentage / LEVEL_TIME;
        if(percentage < 0)
        {
            percentage = 0;
        }
        double bar_width = bitmap_width("green_bar_lines") * percentage_remaining;
        
        //drawing_options option_part_bmp(double x, double y, double w, double h)
        
        draw_text("SCORE: " + to_string(game.player.score), COLOR_ORANGE, 5, 150, option_to_screen());
        draw_text("LOCATION: " + point_to_string(center_point(game.player.player_sprite)), COLOR_RED, 0, 10, option_to_screen());
        draw_text("LEVEL: " + to_string(game.player.level), COLOR_ORANGE, 5, 140, option_to_screen());
        draw_text("FUEL: " + to_string(game.player.fuel_pct), COLOR_ORANGE, 5, 160, option_to_screen());

        draw_text(to_string(game.player.coin), COLOR_WHITE, "FONT" , 40, 40, 230, option_to_screen(option_scale_bmp(5, 5)));
        draw_text(to_string(game.player.heart), COLOR_WHITE, "FONT" , 40, 40, 300, option_to_screen(option_scale_bmp(5, 5)));
        draw_text(to_string(game.player.diamond), COLOR_WHITE, "FONT" , 40, 40, 370, option_to_screen(option_scale_bmp(5, 5)));
        draw_text(to_string(game.player.shield), COLOR_WHITE, "FONT" , 40, 40, 440, option_to_screen(option_scale_bmp(5, 5)));


        draw_bitmap("empty", 20, 20 , option_to_screen());
        draw_bitmap("empty", 20, 60, option_to_screen());
        draw_bitmap("purple_bar", 20, 20, option_part_bmp(0, 0, bitmap_width("purple_bar")*game.player.fuel_pct, bitmap_height("purple_bar"),option_to_screen()));
        draw_bitmap("green_bar_lines", 20, 60, option_part_bmp(0, 0, bar_width, bitmap_height("green_bar_lines"), option_to_screen()));
        
        // including something stationary - it doesn't move
        fill_rectangle(COLOR_WHITE, 400, 400, 10, 10);

        // as well as the player who can move
        draw_game(game);

        if(game.player.fuel_pct == 0)
        {
            close_window("Lost In Space");
        }
        refresh_screen(60);
    }
    return 0;
}
