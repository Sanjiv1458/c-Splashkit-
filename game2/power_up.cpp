#include "splashkit.h"
#include "power_up.h"
#include "lost_in_space.h"
#include <vector>

using namespace std;

bitmap power_up_bitmap(power_up kind)
{
    switch (kind)
    {
    case SHIELD:
        bitmap_named("shield");
        return bitmap_named("shield");
    case COIN:
        bitmap_named("coin");
        return bitmap_named("coin");
    case FUEL:
        bitmap_named("fuel");
        return bitmap_named("fuel");
    case HEART:
        bitmap_named("heart");
        return bitmap_named("heart");
    case DIAMOND:
        bitmap_named("diamond");
        return bitmap_named("diamond");
    default:
        bitmap_named("time");
        return bitmap_named("time");
    }
}

power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    
    result.kind = static_cast<power_up>(rnd(6));
    
    result.power_up_sprite = create_sprite(power_up_bitmap(result.kind));

                                     
    draw_power_up(result);


    sprite_set_x(result.power_up_sprite, x);
    sprite_set_y(result.power_up_sprite, y);


    sprite_set_dx(result.power_up_sprite, rnd() * 4 - 2);
    sprite_set_dy(result.power_up_sprite, rnd() * 4 - 2);
    return result;
}

void draw_power_up(const power_up_data &power_up_data_to_draw)
{
    draw_sprite(power_up_data_to_draw.power_up_sprite);
}

void update_power_up(const power_up_data &power_up_to_update)
{
    update_sprite(power_up_to_update.power_up_sprite);
}