#include "splashkit.h"
#include <string>
using namespace std;

struct knight_data
{
    string loantype;
    string name;
    int age;
    int birth;
    double principle;
    int time;
    int earning;
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
    result.age = read_integer("Enter age: ");
    result.principle = read_integer("Enter the principle: ");
    result.time = read_integer("Enter the time: ");
    result.earning = read_integer("Enter the your earning");
    result.birth = read_integer("Enter the your birth year");
    return result;
}

void write_knight(const knight_data &knight)
{
    write_line("Hello " + knight.name + " nice to meet you");
    write_line("great you are " + to_string(knight.age));
    write_line("we will try to arrange the amount of " + to_string(knight.principle));
    write_line("there is high possiblity of loan for " + to_string(knight.time) + "years");
    write_line("oh great you earn " + to_string(knight.earning) + " it's a lot");
    write_line("my friend's date of birth is also " + to_string(knight.birth));
}
enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_BIRTH,
    UPDATE_PRINCIPLE,
    UPDATE_TIME,
    UPDATE_EARNING,
    FINISH_UPDATE
};

knight_update_option read_knight_update_option()
{
    int result;

    write_line("1: update name");
    write_line("2: update age");
    write_line("3: update birth");
    write_line("4: update principle");
    write_line("5: update time");
    write_line("6: update earning");
    write_line("7: finish update");
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
                knight.age = read_integer("Enter the new birth year");
                break;
            case UPDATE_PRINCIPLE:
                knight.principle = read_double("Enter the new principle");
                break;
            case UPDATE_TIME:
                knight.time = read_integer("Enter the new time period");
                break;
            case UPDATE_EARNING:
                knight.earning = read_integer("Enter the new earning income");
                break;
            case FINISH_UPDATE:
                write_line("thank you sir for providing data again");
                break;
            default:
                write_line("see you again");   
        }
    }while(option != FINISH_UPDATE);  

}

int main()
{
    knight_data knight;

    knight = read_knight();
    write_knight(knight);
    read_knight_update_option();
    update_knight(knight);
    return 0;
}
