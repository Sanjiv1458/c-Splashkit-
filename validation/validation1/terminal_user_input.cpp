#include "splashkit.h"
#include "terminal_user_input.h"
using namespace std;

string read_string(string prompt) 
{
    string line;
    write(prompt);
    line=read_line();
    return line;
}

int read_integer(string prompt)
{   
    string line;
    int result;

    line = read_string(prompt);
    while(not is_integer(line))
    {
        write_line("please enter a whole number: ");
        line = read_string(prompt);
    }
    result = convert_to_integer(line);
    return result;
}

double read_double(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_double(line);
}

int read_integer_range(string line, int min, int max)
{
    int result;
    result = read_double(line);

    while(result < min or result > max)
    {
        write_line("Please enter the quantity between " + to_string(min) + "  and  " + to_string(max));
        result = read_double(line);
    }
    return result;
}

bool read_bool(string prompt)
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

#define PmedicineA 5
#define PmedicineB 4.5
#define PmedicineC 2.5

double calculate_medicine_fever(int medicineA, int medicineB)
{
    double result;
    result = medicineA * PmedicineA + medicineB * PmedicineB;
    return result;
}

double calculate_medicine_cough(int medicineB, int medicineC)
{   
    double result;
    result = medicineB * PmedicineB + medicineC * PmedicineC;
    return result;
}

double calculate_medicine_typhoid(int medicineA, int medicineC)
{   
    double result;
    result = medicineA * PmedicineA + medicineC * PmedicineC;
    return result;
}

double calculate_medicine_cough_fever_typhoid(int medicineA, int medicineB, int medicineC)
{   
    double result;
    result = medicineA * PmedicineA + medicineB * PmedicineB + medicineC * PmedicineC;
    return result;
}