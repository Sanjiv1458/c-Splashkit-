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

int index_of(string name, vector<string> &data)
{
    
    for(int i = 0; i < data.size(); i++)
    {    
        if(to_lowercase(name) == to_lowercase(data[i])) 
        {
            return i;
        }  
    }
    return -1;
}

bool contains(vector<string> &data, string name)
{
    for(int i = 0; i < data.size(); i++)
    {
        if(to_lowercase(data[i]) == to_lowercase(name))
        {
            return true;
        }
    }
    return false;
}

string shortest_name(vector<string> &data)
{
    string min;
    min = data[0];
    for(int i = 1; i < data.size(); i++)
    {
        if(min.length() > data[i].length())
        {
            min = data[i];
        }
    }
    return min;
}

string longest_name(vector<string> &data)
{
    string max;
    max = data[0];
    for(int i = 1; i < data.size(); i++)
    {
        if(max.length() < data[i].length())
        {
            max = data[i];
        }
    }
    return max;
}

int total_length(string name, vector<string> &data)
{
    int result=0;
    for(int i = 0; i < data.size(); i++)
    {    
        string name = data[i];
        result += name.length();
    }
    return result;
}

void add_name(string name, vector<string> &data)
{
    int size = read_integer("entet the number of people you want to add more people: ");
    int i = 0;
    while(i < size)
    {
        name = read_string("Enter the name of people you want to add: ");
        data.push_back(name);
    }
    i++;
    for(i = 0; i < data.size(); i++)
    {
        write_line(data[i]);
    }
}

void print_summary(string name, vector<string> &data)
{
    write_line("shortest name: " + shortest_name(data));
    write_line("longest name: " + longest_name(data));
    
    for(int i =0; i < data.size(); i++) 
    {
        write_line(to_string(i+1) +"."+ data[i]);
        write_line("Length: "+ to_string(data[i].length()));
    }

    write_line("Total Length: "+ to_string(total_length(name, data)));
    bool con = contains(data, "Samjiv");
    if(con) write_line("contains Sanjiv");
    add_name(name, data);
}

int main()
{
    int size = read_integer("enter the number of people you want to check the name in voter list: ");
    
    vector<string> data;
    int i;

    write_line("-----CHECK YOUR NAME IN VOTER LIST-----");
    
    i = 0; 

    while(i < size)
    {
        string name = read_string("Enter the name of people: ");
        data.push_back(name);
        i++;
    }

    for(i = 0; i < data.size(); i++)
    {
        write_line(data[i]);
    }


    bool name1;
    bool name2;
    bool name3;

    name1 = contains(data, "vilas");
    name2 = contains(data, "tarun");
    name3 = contains(data, "andrew");

    if(name1) write_line("vilas: oh you are tutor in chitkara university");
    if(name2) write_line("tarun: oh you are student in chitkara university");
    if(name3) write_line("andrew: oh you are tutor in deakin university");
    
    string name;
    print_summary(name, data);
    return 0;
}