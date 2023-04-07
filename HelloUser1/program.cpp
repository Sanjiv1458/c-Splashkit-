#include "splashkit.h"
#include <string>

#define STROUHAL 0.33;
// Calculat resultant  strouhal air speed by reading in freq and amp
double calculate_air_speed(int freq, int amp)
{
    double result;
    result = freq * amp * 0.01 / STROUHAL;
    return result;
}
// breaking the declaration as proccedure calls to simplyfy the code as per instruction
void output_air_speed(string name, int freq, int amp)
{
    write_line("Air speed :");
    write_line(calculate_air_speed(freq, amp));
}
// return a string of the input line from the terminal
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}
// creating the variable to define datatype instruction
int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}
// these are variables of integer data type
int main()
{
    string name;
    int age;
    int frequency;
    int amplitude;

    name = read_string("What's the name of the bird: ");
    age = read_integer("What's the age of the bird: ");
    frequency = read_integer("What's the frequency of the bird's stroke: ");
    amplitude = read_integer("What's the stroke amplitude: ");
// adding some more out-puts which is followed by tasksheet
    write_line("");
    write("Bird Name:, ");
    write_line(name + "!");
    write("Bird age: ");
    write_line(age);
    write("Frequecy of wing flap: ");
    write_line(frequency);
    write("Amplitude of flap: ");
    write_line(amplitude);

    output_air_speed(name, frequency, amplitude);
    return 0;
}