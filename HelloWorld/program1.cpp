#include "splashkit.h"
using namespace std;
#include <string.h>

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
    line = read_string(prompt);
    return convert_to_integer(line);
}

int main()
{
    int n = read_integer("please inter the number: ");
    write_line(to_string(n) + " natural numbers are ");
    for(int i = 1; i <= n; i++)
    {
        write_line(to_string(i));
    }
}