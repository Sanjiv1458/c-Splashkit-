#ifndef PLAYER_UP
#define PLAYER_UP
#include "splashkit.h"
#include <vector>

using namespace std;

enum power_up
{
    SHIELD,
    COIN,
    FUEL,
    HEART,
    DIAMOND,
    TIME
    
};

struct power_up_data
{
    sprite power_up_sprite;
    power_up kind;  
    bool power; 
};

bitmap power_up_bitmap(power_up kind);
power_up_data new_power_up(double x, double y);
void draw_power_up(const power_up_data &power_up_data_to_draw);
void update_power_up(const power_up_data &power_up_to_update);

#endif