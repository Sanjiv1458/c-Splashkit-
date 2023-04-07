#include "splashkit.h"
#define VISUAL 20

void draw_values(const int values[], int size)
{
    int x = 0;
    int y = 0;
    int rect_height;
    int rect_width = screen_width()/size;

    for(int i = 0; i < size; i++)
    {
        rect_height = values[i];
        y = screen_height() - rect_height;
        fill_rectangle(COLOR_RED, x, y, rect_width, rect_height);
        draw_rectangle(COLOR_RED, x, y, rect_width, rect_height);
        x += rect_width;
    }
}

void draw_sort(int values[], int size)
{
    clear_screen(COLOR_WHITE);
    draw_values(values, size);
    refresh_screen(60);
}

void swap(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void bubble_sort(int values[], int size)
{
    for(int j = 0; j < size; j++)
    {
       for(int i = 0; i < size - 1; i++)
       {
           if(values[i] > values[i + 1])
           {
               swap(values[i], values[i + 1]);
               draw_sort(values, size);
           }
       }
    }
}

void sort_quickly(int values[], int size, int a, int b)
{
    if(a < b)
    {
        int i = a -1;
        int pin = values[b];
        draw_sort(values, size);
        for(int j = a; j <= b -1; j++)
        {
            if(values[j] <= pin)
            {
                i++;
                swap (values[i], values[i +1]);
            }
        }
        swap(values[b], values[i + i]);

        int pin_index = i + 1;
        sort_quickly(values, size, a, pin_index - 1);
        sort_quickly(values, size, pin_index + 1, b);
    }
}

void random_fill_arrays(int values[], int size)
{
    for(int i = 0; i < size; i++)
    {
        values[i] = rnd(screen_height()) + 1;
    }
}

void handle_input(int values[], int size)
{
    if(key_typed(R_KEY))
    {
        random_fill_arrays(values, size);
    }
    else if(key_typed(S_KEY))
    {
        bubble_sort(values, size);
    }
    else if(key_typed(D_KEY))
    {
        sort_quickly(values, size, 0, size - 1);
    }
}

int main()
{
    int values[VISUAL];

    open_window("sort visualiser", 800, 800);

    random_fill_arrays(values, VISUAL);

    while(not quit_requested())
    {
        process_events();
        handle_input(values, VISUAL);
        draw_sort(values, VISUAL);
    }

    return 0;
}
