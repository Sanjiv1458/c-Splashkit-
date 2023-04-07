#include "splashkit.h"
using std::vector;
#include <vector>
using namespace std;

struct knight_data
{
    string name;
    string address;
    double age;
    int birth;
    vector<string> data;
};

struct kingdom_data
{
    string name;
    vector<knight_data> knights;
};

string read_string(string prompt)
{
    string line;
    write_line(prompt);
    line = read_line();
    return line;
}

int read_integer(string prompt)
{
    string line;
    int value;
    write_line(prompt);
    value = convert_to_integer(read_line());
    return value;
}

double read_double(string prompt)
{
    string line;
    double value;
    write_line(prompt);
    value = convert_to_double(read_line());
    return value;
}

knight_data read_knight()
{
    knight_data result;

    result.name = read_string("Enter name; ");
    result.age = read_double("Enter age; ");
    result.birth = read_integer("Enter the your birth year");
    result.address = read_string("Enter your Address; ");
    return result;
}

kingdom_data read_kingdom()
{
    kingdom_data result;

    result.name = read_string("Enter kingdom name; ");
    return result;
}

void write_knight(const knight_data &knight)
{
    write_line("Hello " + knight.name + " nice to meet you");
    write_line("great you are " + to_string(knight.age));
    write_line("my friend's birth year is also " + to_string(knight.birth));
    write_line("you live in " + knight.address);
}

void add_knight(kingdom_data &kingdom)
{
    knight_data new_knight;
    new_knight = read_knight();
    kingdom.knights.push_back(new_knight);
}

void delete_knight(kingdom_data &kingdom, int index)
{
    if(kingdom.knights[index].data.size() == 0)
    {
        write_line("you dont want to delete people from voter ID list");
    }
    else
    {
        write_line("yor voters name are:- ");
        for(int i = 0; i < (kingdom.knights[index].data.size()); i++)
        {
            write("names number: ");
            write(i);
            write_line(kingdom.knights[index].data[i]);
        }
    }
    write_line("----select the name of died people to delete name from voter list----");
    int max;
    int del;
    max = kingdom.knights[index].data.size();
    del = read_integer("please enter the name to delete; ");
    while(del>max)
    {
        write_line("please enter the valid option!!!");
        del = read_integer("please enter the name to delete; ");
    }

    int last_index;
    last_index = kingdom.knights[index].data.size() - 1;
    kingdom.knights[index].data[del] = kingdom.knights[index].data[last_index];
    kingdom.knights[index].data.pop_back();
}

int select_knight(const kingdom_data &kingdom)
{
    int max;
    max = kingdom.knights.size();
    write_line("=======knights=======");
    for(int i = 0; i < max; i++)
    {
        write(i+1);
        write(" ");
        write_line(kingdom.knights[i].name);
    }
    write_line("============================");

    max = max + 1;
    int knightno;

    knightno = read_integer("please select a knight; ");

    while(knightno > max)
    {
        write_line("please enter a valid value.");
        knightno = read_integer("please select a knight; ");

    }
    return knightno;
}

void query_knight(kingdom_data &kingdom)
{
    write_line("=====knights=====");
    for(int i = 0; i < kingdom.knights.size(); i++)
    {
        write_knight(kingdom.knights[i]);
    }
    write_line("=======================");
}

void write_kingdom(const kingdom_data &kingdom)
{
    write_line("==== knights ====");
    write_line("======" + kingdom.name + "======");
    for(int i =0; i <kingdom.knights.size(); i++)
    {
       write_knight(kingdom.knights[i]);
    }
    write_line("============");
}

enum knight_update_option
{
    UPDATE_NAME ,
    UPDATE_AGE,
    UPDATE_BIRTH,
    UPDATE_ADDRESS,
    FINISH_UPDATE
};

enum kingdom_update_option
{
    ADD_KNIGHT,
    QUERY_KNIGHT,
    DELETE_KNIGHT,
    UPDATE_KNIGHT,
    DISPLAY_KINGDOM,
    EXIT_MENU
};

knight_update_option read_knight_update_option()
{
    int result;

    write_line("1: update name");
    write_line("2: update age");
    write_line("3: update birth");
    write_line("4: update address");
    write_line("5: finish update");
    result = read_integer("select option: ");

    return static_cast<knight_update_option>(result - 1);
}

void update_knight(knight_data &knight)
{
    knight_update_option option;
    do
    {
        write_line("== update knight ==");
        write_knight(knight);
        write_line();
        option = read_knight_update_option();
        switch(option)
        {
            case UPDATE_NAME:
                knight.name = read_string("Enter new name");
                break;
            case UPDATE_AGE:
                knight.age = read_integer("Enter the new age");
                break;
            case UPDATE_BIRTH:
                knight.birth = read_integer("Enter the new birth year");
                break;
            case UPDATE_ADDRESS:
                knight.address = read_string("Enter the new address");
                break;
            case FINISH_UPDATE:
                write_line("thank you sir for providing data again");
                break;
            default:
                write_line("see you again");   
        }
    }while(option != FINISH_UPDATE);  
}

kingdom_update_option read_kingdom_update_option()
{
    int result;
    
    write_line("1: add knight");
    write_line("2: query knight");
    write_line("3: delete knight");
    write_line("4: update knight");
    write_line("5: display kingdom");
    write_line("6: exit menu");
    result = read_integer("select option: ");

    return static_cast<kingdom_update_option>(result - 1);
}

void update_kingdom(kingdom_data &kingdom)
{
    int option;
    int index = 0;
    knight_data knight;
    
    do
    {
        write_line();
        write_line("== update knight ==");
        write_knight(kingdom.knights[index = 0]);
        write_line();
        option = read_kingdom_update_option();
        switch(option)
        {   
            case ADD_KNIGHT:
                add_knight(kingdom);
                break;
            case QUERY_KNIGHT:
                query_knight(kingdom);
                break;
            case DELETE_KNIGHT:
                delete_knight(kingdom, index);
                break;
            case UPDATE_KNIGHT:
                update_knight(knight);
                break;
            case DISPLAY_KINGDOM:
                write_kingdom(kingdom);
                break;
            case EXIT_MENU:
                write_line("====================");
                break;
            default:
                write_line("see you again!!!");   
        }
    }while(option != FINISH_UPDATE);
}

int main()
{
    vector<knight_data> knights;
    vector<string> data;
    knight_data knight;

    kingdom_data kingdom = read_kingdom();
    add_knight(kingdom);
    write_kingdom(kingdom);
    update_knight(knight);
    update_kingdom(kingdom);
    return 0;
}
