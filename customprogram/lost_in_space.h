#ifndef LOST_IN_SPACE
#define LOST_IN_SPACE

#include "splashkit.h"
using std::vector;
#include "player.h"
#include "power_up.h"
#include <vector>

using namespace std;

#define LEVEL_TIME 20000.00

struct game_data
{
    player_data player;
    vector<power_up_data> power_ups;
    timer game_timer;
};

game_data new_game();
void update_game(game_data &game);
void draw_game(game_data &game);
point_2d mini_map(const power_up_data &power_up);
point_2d player_mini_map(const player_data &player);
void draw_mini_map(const vector<power_up_data> power_ups);
void draw_mini_map_player(const game_data &game);
#endif