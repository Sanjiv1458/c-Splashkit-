#include "splashkit.h"
using std::vector;
#include <vector>
using namespace std;

string read_string(string prompt)
{
    string name;
    write(prompt);
    name = read_line();
    return name;
}

int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

int index_of(string name, string data[], int size)
{
    
    for(int i = 0; i < size; i++)
    {
        if(to_lowercase(name) == to_lowercase(data[i])) 
        {
            return i;
        }
        
    }
    return -1;
}

bool contains(string data[], int size, string name)
{
    for(int i = 0; i < size; i++)
    {
        if(to_lowercase(data[i]) == to_lowercase(name))
        {
            return true;
        }
    }
    return false;
}

string shortest_name(string data[], int size)
{
    string min;
    min = data[0];
    for(int i = 1; i < size; i++)
    {
        if(min.length() > data[i].length())
        {
            min = data[i];
        }
    }
    return min;
}

string longest_name(string data[], int size)
{
    string max;
    max = data[0];
    for(int i = 1; i < size; i++)
    {
        if(max.length() < data[i].length())
        {
            max = data[i];
        }
    }
    return max;
}

int total_length(string name, string data[], int size)
{
    int result=0;
    for(int i = 0; i < size; i++)
    {
        string name = data[i];
        result += name.length();
    }
    return result;
}

void write_line_summary(string name, string data[], int size)
{
    write_line("shortest name; " + shortest_name(data, size));
    write_line("longest name; " + longest_name(data, size));
    
    for(int i =0; i<size; i++) 
    {   write_line(to_string(i+1) +"."+ data[i]);
        write_line("Length; " + to_string(data[i].length()));
    }

    write_line("Total Length; "+ to_string(total_length(name, data, size)));
    bool cont = contains(data, size, "Sanjiv");
    if(cont) write_line("contains Sanjiv");
}

int main()
{
    #define SIZE 3
    string data[SIZE];
    int i;

    write_line("-----CHECK YOUR NAME IN VOTER LIST-----");
    
    i = 0; 
    while(i < SIZE)
    {
        data[i] = read_string("Enter the your name; ");
        i++;
    }

    for(i = 0; i < SIZE; i++)
    {
        write_line(data[i]);
    }


    bool name1;
    bool name2;
    bool name3;

    name1 = contains(data, SIZE, "vilas");
    name2 = contains(data, SIZE, "tarun");
    name3 = contains(data, SIZE, "andrew");

    if(name1) write_line("vilas; oh you are tutor in chitkara university");
    if(name2) write_line("tarun; oh you are student in chitkara university");
    if(name3) write_line("andrew; oh you are tutor in deakin university");

    string name;
    write_line_summary(name, data, SIZE);

    return 0;
}
