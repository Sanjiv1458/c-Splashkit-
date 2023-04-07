// Task 3.1 HelloUser-2
// This task is given for creating our own project.
// My project is based on accountancy to help the customers in finding the interest money for loan with principle amount.
// Here is also given that the interest rate for Business loan is 12% and for Student loan is 10%.

#include "splashkit.h"

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

void all_required_calculation(double principle, int time)
{
    write("interest for Business: ");
    write_line(calculate_interest_Business(principle, time));
    write("interest for Education: ");
    write_line(calculate_interest_Business(principle, time));
    write("compond money for Business: ");
    write_line(calculate_compound_money_Business(principle, time));
    write("compound money for education: ");
    write_line(calculate_compound_money_Education(principle, time));
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
    
    write_line("wlcome to accountant sanjiv");
    
    name = read_string("Customer's name: ");
    principle = read_double("PLEASE enter the pricipal amount requested from bank: ");
    time = read_integer("PLEASE enter the time period for what time you want loan: ");
    
    write("Customer's name: ");
    write_line(name);
    
    all_required_calculation(principle, time);

    write_line("thanks for using this service : Online Bank!");

    return 0;
}
