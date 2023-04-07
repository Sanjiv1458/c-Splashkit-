// Code program.cpp code for terminal_user_input.cpp

#include "splashkit.h"
#include "terminal_user_input.h"

using namespace std;

string read_string(string prompt);
int read_integer(string prompt);

int main()
{
    string name;
    int age;
    
    name = read_string("Enter your name; ");
    write_line("welcome" + name);

    age = read_integer("enter your age; ");
    write_line("great you  are" + to_string(age));

    return 0;
}
