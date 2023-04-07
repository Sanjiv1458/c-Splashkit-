#include "splashkit.h"
#include "terminal_user_input.h"

string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

int read_integer(string prompt)
{
    string line;
    int result;
    line = read_string(prompt);
    result = convert_to_integer(line);

    return result;
}
