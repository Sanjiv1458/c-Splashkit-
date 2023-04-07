#include "splashkit.h"
#include "terminal_user_input.h"
using namespace std;

#define BUSINESS 12
#define EDUCATION 10

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
    double result = 0;

    line = read_string(prompt);
    while(not is_double(line))
    {
        write_line("PLEASE Enter a whole number: ");
        line = read_string(prompt);
    }
    result = convert_to_double(line);
    return result;
}

int read_integer(string prompt)
{   
    string line;
    int result = 0;

    line = read_string(prompt);
    while(not is_integer(line))
    {
        write_line("PLEASE Enter a whole number: ");
        line = read_string(prompt);
    }
    result = convert_to_integer(line);
    return result;
}

double read_double_range(string prompt, double min, double max)
{
    double line;
    line = read_double(prompt);

    while(line < min or line > max)
    {
        write_line("PLEASE Enter the amount between " + to_string(min) + " to " +  to_string(max));
        line = read_double(prompt);
    }
    return line;
}

bool read_boolean(string prompt)
{
    string line;
    line = read_string(prompt);

    if(to_uppercase(line) == "YES" || to_uppercase(line) == "Y")
    {   
        return true;
    }
    else if(to_uppercase(line) =="NO" || to_uppercase(line) =="N")
    {
        return false;
    }
    else
    {
        write_line("please enter the response in yes(y) or no(n)");

        return false;
    }
    return false;
}

int read_integer(string prompt, int min, int max)
{
    int line;
    line = read_integer(prompt);

    while(line < min or line > max)
    {
        write_line("PLEASE Enter the time between " + to_string(min) + " to " + to_string(max));
        line = read_integer(prompt);
    }
    return line;
}

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
    result = calculate_interest_Business(principle, time) + principle;
    return result;
}

double calculate_compound_money_Education(double principle, int time)
{
    double result; 
    result = calculate_interest_Education(principle, time) + principle;
    return result;
}

void Business_option(double principle,int time)
{
    write("interest for business of " + to_string(time));
    write_line(calculate_interest_Business(principle, time));
    write("interest for education of " + to_string(time));
    write_line(calculate_compound_money_Business(principle, time));
}

void Education_option(double principle,int time)
{
    write("interest for Education of " + to_string(time));
    write_line(calculate_interest_Business(principle, time));
    write("interest for Education of " + to_string(time));
    write_line(calculate_compound_money_Education(principle, time));
}