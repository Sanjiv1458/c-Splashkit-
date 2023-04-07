#include "splashkit.h"

#define MINRADIUS 10
#define MAXRADIUS 100

int main()
{
    double x;
    double y;
    int radius;
    color circle_color = COLOR_GREEN;
    color background_color = COLOR_WHITE;
    load_sound_effect("london", "london.wav");

    open_window("shape shifter", 800, 600);

    y = screen_height()/2;
    x = screen_width()/2;
    radius = 50;

    while(not quit_requested())
    {
        process_events();

        if(key_typed(EQUALS_KEY))
        {
            radius = radius + 5;
            if(radius > MAXRADIUS)
            {
                radius = MAXRADIUS;
            }
        }

        if(key_typed(MINUS_KEY))
        {
            radius = radius - 5;
            if(radius < MINRADIUS)
            {
                radius = MINRADIUS;
            }
        }

        if(key_typed(C_KEY))
        {
            circle_color = random_color();
        }

        if(key_typed(R_KEY))
        {
            background_color = random_color();
        }

        if(key_typed(L_KEY))
        {
            play_sound_effect("london");
        }

        if(key_down(RIGHT_KEY))
        {
            x = x + 2;
        }

        if(key_down(LEFT_KEY))
        {
            x = x - 2;
        }

        if(key_down(DOWN_KEY))
        {
            y = y + 2;
        }

        if(key_down(UP_KEY))
        {
            y = y - 2;
        }

        if(x + radius > screen_width())
        {
            x = screen_width() - radius;
        }

        if(x - radius < 0)
        {
            x = radius;
        }

        if (y + radius > screen_height())
        {
            y = screen_height() - radius;
        }

        if(y - radius < 0)
        {
            y = radius;
        }

        clear_screen(COLOR_WHITE);
        fill_circle(COLOR_GREEN, x, y, radius);
        refresh_screen(60);
    }
    return 0;
}
