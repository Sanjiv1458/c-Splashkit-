#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include "lost_in_space.h"
#include <vector>

using namespace std;

game_data new_game()
{
    game_data game;
    game.player = new_player();
    game.game_timer = create_timer("TIMER");
    start_timer(game.game_timer);
    return game;
}

void add_power_up(game_data &game)
{
    game_data add_power_up;
    int value = rnd(-1500,1500);
    game.power_ups.push_back(new_power_up(value,value));
}

void remove_power_up(game_data &game, int &index)
{
    int last_index = game.power_ups.size() -1;
    game.power_ups[index] = game.power_ups[last_index];
    game.power_ups.pop_back();
}

void bitmap_score(game_data &game, int &index)
{
    power_up x = game.power_ups[index].kind;
    
    if(x == TIME)
    {
        reset_timer("TIMER");
    }
    else if(x == COIN)
    {
        game.player.coin += 1;
    }
    else if(x == HEART)
    {
        game.player.heart += 1;
    }
    else if(x == DIAMOND)
    {
        game.player.diamond += 2;
    }
    else if(x == SHIELD)
    {
        game.player.shield += 3;
    }
    else if(x == FUEL)
    {
        game.player.fuel_pct = game.player.fuel_pct + 0.25;
        if(game.player.fuel_pct > 1)
        {
            game.player.fuel_pct = 1;
        }
    }
}

void game_level(game_data &game)
{    
    for(int i = 0; i < 100; i++)
    {
        if(game.player.score > i * 100)
        {
            game.player.level = i;
        }
    }
}

void check_collisions(game_data &game)
{
    for (int i = 0; i < game.power_ups.size(); i++)
    {
        if (sprite_collision(game.player.player_sprite, game.power_ups[i].power_up_sprite))
        {
            bitmap_score(game, i);
            game.player.score++;
            load_sound_effect("coin", "coin.wav");
            play_sound_effect("coin");
            remove_power_up(game, i);
            game_level(game);
        } 
    }
}

void update_game(game_data &game)
{
    if (rnd() < 0.05)
    {
        add_power_up(game);
    }
    check_collisions(game);
    update_player(game.player);
    for (int i = 0; i < game.power_ups.size(); i++)
    {
        update_power_up(game.power_ups[i]);
    } 
}

void draw_game(game_data &game)
{
    draw_player(game.player);
    for(int i = 0; i< game.power_ups.size(); i++) 
    {
        draw_power_up(game.power_ups[i]);
    }
    refresh_screen(60);
}
