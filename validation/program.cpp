#include "splashkit.h"
#include "terminal_user_input.h"
using namespace std;
using std::string;
  
int main()
{
    string name;
    string responce;
    string feedback;
    double principle;
    int time;
    int earning;
    int age;
    int option;
    bool service;

    name = read_string("Customer's name: ");
    age = read_integer("please enter the your age: ");
    write_line("great you are of " + to_string(age));
    principle = read_double_range("PLEASE enter the pricipal amount requested from bank: ", 100000, 1000000);
    write_line("we will try to arrange the amount of " + to_string(principle));
    time = read_integer("PLEASE enter the time period for what time you want loan: ", 3, 10);
    write_line("yeah it is possible to give loan for " + to_string(time) + "years");
    earning = read_integer("PLEASE enter the your monthly income: ");
    
    write_line("welcome to accountant sanjiv");
    write("customer's name: ");
    write_line(name);
    
    if(to_lowercase(name) == "Madhav Mittal")
    {
        write_line("welcome! our customer");
        write_line("we are waiting for you");
    }
    else if(to_lowercase(name) == "tarunpal singh")
    {
        write_line("welcome! our customer");
        write_line("we have some great offers for you please visit to branch office");
    }
    else
    {
        write_line("welcome! our new expected customer");
        write_line ("please open the account to our bank for loan");
    }

    do
    {
        write_line("1: loan for Education");
        write_line("2: loan for Business");
        write_line("3: quit");
        option = read_integer("PLEASE choose an OPTION for loan type: ");
        
        switch(option)
        {
            case 1:
                Education_option(principle, time);
                break;
            case 2:
                Business_option(principle, time);
                break;
            case 3:
                write_line("see you letter!");
                break;
            default:
                write_line("see you again");
        }
    } while (option != 3);

    if(age >= 18 && age <= 45)
    {
       write_line("oh great you are " + to_string(age));
    }
    else
    {
        write_line("your age is not elligible for loan");
    }

    if((principle <= 500000 && earning >= 30000) || (principle <= 1000000 && earning >= 50000))
    {
        write_line("thanks for giving opportunity to serve you");
        write_line("your salary is elligible for loan");
    }
    else
    {
        write_line("your are not elligible for loan");
    }

    service = read_boolean("please give review to our services as writing as YES or NO: ");
    
    if(service == true)
    {
        write_line("happy to know");
    }
    else
    {
        write_line("well give us feedback sir we will improve");
    }

    feedback = read_string("give feedback sir: ");
    write("your feedback: ");
    write_line(feedback);

    write_line("thanks for using our services!");
    return 0;
}