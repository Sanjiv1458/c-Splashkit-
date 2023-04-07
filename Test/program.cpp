#include "splashkit.h"

#define FORPOUNDS 2.2
#define FORKILO 0.4

double calculate_kilogram_to_pounds(double kilo)
{
    double result;
    result = kilo * FORPOUNDS;
    return result;
}

double calculate_pounds_to_kilogram(double pounds)
{
    double result;
    result = pounds * FORKILO;
    return result;
}
void option_1(double kilo)
{
    write("calculation of kilo to pounds: ");
    write_line(calculate_kilogram_to_pounds(kilo));
}

void option_2(double pounds)
{
    write("calculation of pounds to kilo: ");
    write_line(calculate_pounds_to_kilogram(pounds));
}
    
string read_string(string prompt)
{    
    string result;
    write(prompt);
    result = read_line();
    return result;
}
double read_double(string prompt)
{   
    string line;
    line = read_string(prompt);
    return convert_to_double(line);
}

int read_integer(string prompt)
{   
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

int main()
{
    string name;
    double kilo;
    double pounds;
    int option;
    
    write_line("wlcome to calculator");
    
    name = read_string("user's name: ");
    
    do
    {
        write_line("1: kilo to pouds");
        write_line("2: pouds to kilo");
        write_line("3: quit");
        option = read_integer("please choose an OPTION for calculation type: ");
        switch(option)
        {
            case 1:
                pounds = read_double("please enter the weight in kilogram: ");
                option_1(pounds);
                break;
            case 2: 
                kilo = read_double("please enter the weight in pounds: ");
                option_2(kilo);
                break;
            case 3:
                   write_line("see you letter!");
                break;
                default:
                write_line("see you again");
        }
    } while (option != 3);

    write_line("thanks for using this service : Online calculator!");

    return 0;
}
