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
   
    load_bitmap("space", "space.jpg");
    load_bitmap("map", "map.jpeg");
    load_bitmap("fuel_bar", "purple_bar.png");
    load_bitmap("green_bar_lines", "green_bar_lines.png");
}

void draw_resources()
{
    
    draw_bitmap("space", 0,0, option_to_screen(option_scale_bmp(1.95, 1.95)));
    draw_bitmap("map", 700, 10, option_to_screen(option_scale_bmp(0.75, 0.75)));
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

    while ( not quit_requested() )
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(game.player);

        // Perform movement and update the camera
        update_game(game);

        // Redraw everything
        clear_screen(COLOR_BLACK);
        
        draw_resources();
        
        draw_text("SCORE: " + to_string(game.player.score), COLOR_RED, 5, 120, option_to_screen());
        draw_text("LOCATION: " + point_to_string(center_point(game.player.player_sprite)), COLOR_RED, 0, 10, option_to_screen());
        draw_text("FUEL: " + to_string(game.player.fuel_pct), COLOR_RED, 5, 130, option_to_screen());
        draw_bitmap("fuel_bar", 20, 20, option_part_bmp(0, 0, bitmap_width("fuel_bar")*game.player.fuel_pct, bitmap_height("fuel_bar"),option_to_screen()));
    
        // including something stationary - it doesn't move
        fill_rectangle(COLOR_WHITE, 400, 400, 10, 10);

        // as well as the player who can move
        draw_game(game);
        refresh_screen(60);
    }

    return 0;
}

/*
 point_2d mini_map(const power_up_data &power_up)
 {
     double x_pos, y_pos;
     x_pos = (sprite_x(power_up.power_up_sprite)+ (1500))/3000 * 100 + 60;
     y_pos = (sprite_y(power_up.power_up_sprite)+ (1500))/3000 * 100 + 60;
     return point_at(x_pos, y_pos);
 }

 point_2d player_mini_map(const player_data &player)
 {
     double x_pos, y_pos;
     x_pos = (sprite_x(player.player_sprite)+ (1500))/3000 * 100 + 60;
     y_pos = (sprite_y(player.player_sprite)+ (1500))/3000 * 100 + 60;
     return point_at(x_pos, y_pos);
 }

 void draw_mini_map(const vector<power_up_data> power_ups)
 {
     for(int i = 0; i< power_ups.size(); i++)
     {
         draw_pixel(COLOR_WHITE, mini_map(power_ups[i]), option_to_screen());
     }
 }

 void draw_mini_map_player(const game_data &game)
 {
     draw_pixel(COLOR_RED, player_mini_map(game.player), option_to_screen());
 }
 */
