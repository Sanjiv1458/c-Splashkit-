#include "splashkit.h"
#include "power_up.h"
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
    bitmap default_bitmap = power_up_bitmap(TIME);
    result.kind = TIME;
    result.kind = static_cast<power_up>(rnd(6));
    result.power_up_sprite = create_sprite(power_up_bitmap(result.kind));

    sprite_add_layer(result.power_up_sprite, power_up_bitmap(SHIELD), "shield");
    sprite_add_layer(result.power_up_sprite, power_up_bitmap(COIN), "coin");
    sprite_add_layer(result.power_up_sprite, power_up_bitmap(FUEL), "fuel");
    sprite_add_layer(result.power_up_sprite, power_up_bitmap(HEART), "heart");
    sprite_add_layer(result.power_up_sprite, power_up_bitmap(DIAMOND), "diamond");

    sprite_hide_layer(result.power_up_sprite, 1);
    sprite_hide_layer(result.power_up_sprite, 2);
    sprite_hide_layer(result.power_up_sprite, 3);
    sprite_hide_layer(result.power_up_sprite, 4);
    sprite_hide_layer(result.power_up_sprite, 5);


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