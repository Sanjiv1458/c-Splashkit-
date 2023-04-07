#include "splashkit.h"

#define PRICEDONUT 3.0
#define PRICEMILKSHAKE 4.0
#define PRICEICECREAM 2.0
#define PRICEFRIES 3.5
#define PRICEGULABJAMUN 150

double calculate_combo1_price(int donut, int milkshake, double gulabjamun)
{
    double result;
    result = donut * PRICEDONUT + milkshake * PRICEMILKSHAKE + gulabjamun * PRICEGULABJAMUN;
    return result;
}

double calculate_combo2_price(int icecream, int fries, double gulabjamun)
{
    double result;
    result = icecream * PRICEICECREAM + fries * PRICEFRIES + gulabjamun * PRICEGULABJAMUN;
    return result;
}

double calculate_total_price(int donut, int milkshake, int icecream, int fries, double gulabjamun)
{
    double result;
    result = donut * PRICEDONUT + milkshake * PRICEMILKSHAKE + icecream * PRICEICECREAM+ fries * PRICEFRIES + gulabjamun * PRICEGULABJAMUN;
    return result;
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
    int num_donut;
    int num_milkshake;
    int num_icecream;
    int num_fries;
    double gulabjamun;

    write_line("wlcome to accountant tarunpal singh");
    
    name = read_string("Bill name; ");
    num_donut = read_integer("PLEASE enter the number of donut requested; ");
    num_milkshake = read_integer("PLEASE enter the number of milkshake requested; ");
    num_icecream = read_integer("PLEASE enter the number of icecream requested; ");
    num_fries = read_integer("PLEASE enter the number of fries requested; ");
    gulabjamun = read_double("PLEASE enter the WEIGHT OF gulabjamun in KG; ");
    
    write("Name; ");
    write_line(name);

    write("Total Price; ");
    write_line(calculate_total_price(num_donut, num_milkshake, num_icecream, num_fries, gulabjamun));
    
    write("price of combo1; ");
    write_line(calculate_combo1_price(num_donut, num_milkshake, gulabjamun));
    
    write("Price of combo2; ");
    write_line(calculate_combo2_price(num_icecream, num_fries, gulabjamun));

    write_line("thanks for using food; cashier!");
    return 0;
}