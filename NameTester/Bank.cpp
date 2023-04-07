#include "splashkit.h"
#include <string>
using std::string;

#define BUSINESS 12
#define EDUCATION 10

double calculate_interest_Business(double principle, int time)
{
    double result;
    result = principle * time * BUSINESS / 100;
    return result;
}

double calculate_interest_Education(double principle, int time)
{
    double result;
    result = principle * time * EDUCATION / 100;
    return result;
}

double calculate_compound_money_Business(double principle, int time)
{
    double result;
    result = principle * time * BUSINESS / 100 + principle;
    return result;
}

double calculate_compound_money_Education(double principle, int time)
{
    double result; 
    result = principle * time * EDUCATION / 100 + principle;
    return result;
}

void Education_option(double principle, int time)
{
    write("interest for Education: ");
    write_line(calculate_interest_Business(principle, time));
    write("compond money for Education: ");
    write_line(calculate_compound_money_Education(principle, time));
}
void Business_option(double principle, int time)
{
    write("interest for Business: ");
    write_line(calculate_interest_Business(principle, time));
    write("compound money for Business: ");
    write_line(calculate_compound_money_Business(principle, time));  
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
    double principle;
    int time;
    int age;
    int earning;
    int option;
    
    write_line("wlcome to accountant sanjiv");
    
    name = read_string("Customer's name: ");
    principle = read_double("PLEASE enter the pricipal amount requested from bank: ");
    time = read_integer("PLEASE enter the time period for what time you want loan: ");
    age = read_integer("PLEASE enter the age: ");
    earning = read_integer("PLEASE enter the your monthly income: ");
    
    write("customer's name: ");
    write_line(name);
    
    if(to_lowercase(name) == "sanjiv kumar")
    {
        write_line("welcome! our customer");
        write_line("we are waiting for you");
    }
    else if(to_lowercase(name) == "tarunpal singh")
    {
        write_line("welcome! our customer");
        write_line("we have some great offers for you please visit to branch office");
    }
    else
    {
        write_line("welcome! our new expected customer");
    }
    if(age >= 18 && age <= 45)
    {
        write_line("great you are " + std::to_string(age));
    }
    else
    {
        write_line("your age is not elligible for loan");
    }
    if((principle <= 500000 && earning >= 30000) || (principle <= 1000000 && earning >= 50000))
    {
        write_line("thanks for giving opportunity to serve you");
        write_line("your salary is elligible for loan");
    }
    else
    {
        write_line("your are not elligible for loan");
    }
    do
    {
        write_line("1: loan for Education");
        write_line("2: loan for Business");
        write_line("3: quit");
        option = read_integer("PLEASE choose an OPTION for loan type: ");
        switch(option)
        {
            case 1:
                   Education_option(principle, time);
                break;
            case 2:
                   Business_option(principle, time);
                break;
            case 3:
                   write_line("see you letter!");
                break;
                default:
                write_line("see you again");
        }
    } while (option != 3);

    write_line("thanks for using this service : Online Bank!");

    return 0;
}
