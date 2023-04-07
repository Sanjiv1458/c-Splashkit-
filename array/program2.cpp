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

void add_name(vector<string> &data)
{
    int index = data.size();
    index = read_integer("please the number of people you want to add; ");
    for (int i = 0; i < index; i++)
    {
        string name;
        name = read_string("please enter the name for adding the new name; ");
        data.push_back(name);
        write_line(data[i]);
    }
    write_line("name has been added");
}

void delete_name(vector<string> &data)
{
    int index;   
    if(index < 0 or index >= data.size())
    {
        write_line("Invalid input");
    }
    else
    {
        for(int i = index; i <= data.size(); i++)
        {
            index = read_integer("Enter the index of person you want to change the name: ");
            data[i] = data[data.size() -1];
            data.pop_back();
        }
    }
    write_line("name has been deleted");
}

void write_line_summary(string name, vector<string> &data)
{
    write_line("shortest name; " + shortest_name(data));
    write_line("longest name; " + longest_name(data));
    
    for(int i =0; i < data.size(); i++) 
    {
        write_line(to_string(i+1) +"."+ data[i]);
        write_line("Length; "+ to_string(data[i].length()));
    }

    write_line("Total Length; "+ to_string(total_length(name, data)));
    bool con = contains(data, "tarun");
    if(con) write_line("contains tarun");
    delete_name(data);
}

int main()
{
    int size = read_integer("enter the size of array: ");
    
    vector<string> data;
    int i;
    
    i = 0; 
    while(i < size)
    {
        string name = read_string("Enter the name of people; ");
        i++;
    }

    for(i = 0; i < data.size(); i++)
    {
        write_line(data[i]);
    }

    add_name(vector<string> &data);
    delete_name(vector<string> &data);
    string name;
    write_line_summary(name, data);
    delete_name(vector<string> &data);
    return 0;
}
