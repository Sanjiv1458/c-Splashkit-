#ifndef LOST_IN_SPACE
#define LOST_IN_SPACE

#include "splashkit.h"
using std::vector;
#include "player.h"
#include "power_up.h"
#include <vector>

using namespace std;


struct game_data
{
    player_data player;
    vector<power_up_data> power_ups;
    timer game_timer;
};

game_data new_game();
void update_game(game_data &game);
void draw_game(const game_data &game);
#endif