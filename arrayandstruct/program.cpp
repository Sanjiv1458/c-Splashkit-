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

    result.name = read_string("Enter name: ");
    result.age = read_double("Enter age: ");
    result.birth = read_integer("Enter the your birth year: ");
    result.address = read_string("Enter your Address: ");
    return result;
}

kingdom_data read_kingdom()
{
    kingdom_data result;

    result.name = read_string("Enter kingdom name: ");
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

void delete_knight(kingdom_data &kingdom)
{
    int indx = 0;
    if(indx >=0 && indx < kingdom.knights.size())
    {
        int last_indx = read_integer("please enter the index of knight you want to delete: ");
        last_indx = kingdom.knights.size() - 1;
        kingdom.knights[indx] = kingdom.knights[last_indx];
        kingdom.knights.pop_back();
    }
    else
    {
        write_line("you are entering wrong index");
    }
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
    UPDATE_NAME,
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
    result = read_integer("select option; ");

    return static_cast<knight_update_option>(result - 1);
}

void update_knight(knight_data &knight)
{
    knight_update_option option;
    do
    {
        write_line("== update knight ==");
        option = read_knight_update_option();
        write_knight(knight);
        write_line();
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
    result = read_integer("select option; ");

    return static_cast<kingdom_update_option>(result - 1);
}

void update_kingdom(kingdom_data &kingdom)
{
    kingdom_update_option option;
    knight_data knight;
    
    do
    {
        write_line();
        write_line("== update knight ==");
        for(int i = 0; i < kingdom.knights.size(); i++)
        {
            write_knight(kingdom.knights[i]);
        }
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
                delete_knight(kingdom);
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
    }while(option != EXIT_MENU);
}

int main()
{
    vector<knight_data> knights;
    knight_data knight;

    kingdom_data kingdom = read_kingdom();
    add_knight(kingdom);
    update_kingdom(kingdom);
    write_kingdom(kingdom);
    update_kingdom(kingdom);
    return 0;
}
