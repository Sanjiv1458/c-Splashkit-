#include "splashkit.h"
#include <string>
#include "terminal_user_input.h"
using namespace std;
using std::string;



int main()
{
    string name;
    int age;
    int medicineA; 
    int medicineB;
    int medicineC;
    bool service;
    bool hyegine;

    name=read_string("Enter the patient's name: ");
    age=read_integer("Enter patient's age: ");
    medicineA=read_integer_range("Enter the quantity of medicineA: ", 1, 10);
    medicineB=read_integer_range("Enter the quantity of medicineB: ", 1, 10);
    medicineC=read_integer_range("Enter the quantity of medicineC: ", 1, 10);


    if(to_lowercase(name) == "john")
    {
        write_line("Hello! how may I help you");
        write_line("Don't worry! you have fever");
        write_line("Just take some medicine and you will be fine");
        write("Price of medicine for fever: ");
        write_line(calculate_medicine_fever(medicineA , medicineB));
    }
    else if (to_lowercase(name) == "adam")
    {
        write_line("Hello! how may I help you");
        write_line("Don't worry! you have fever");
        write_line("Just take some medicine and you will be fine");
        write("Price of medicine for fever: ");
        write_line(calculate_medicine_cough(medicineB , medicineC));
    }
    else if(to_lowercase(name) == "shayam")
    {
        write_line("Hello! how may I help you");
        write_line("Don't worry! you have typhoid");
        write_line("Just take some medicine and you will be fine");
        write("Price of medicine for typhoid: ");
        write_line(calculate_medicine_typhoid(medicineA , medicineC));
    }
    else if(to_lowercase(name) == "suresh")
    {
        write_line("Hello! how may I help you");
        write_line("Don't worry! you have cough, fever and typhoid too");
        write_line("take medicine on time and you will be fine");
        write("Price of medicine: ");
        write_line(calculate_medicine_cough_fever_typhoid(medicineA , medicineB, medicineC));
    }
    else
    {
        write_line("you dont have not appointment !!!");
    }

    hyegine = read_bool("do you like our hyegine maintainess(YES,NO or Y,N): ");

    if(hyegine == true)
    {
        write_line("good to know, we are happy");
    }
    else
    {
        write_line("sorry sir! next time we will improve our hyegine");
    }

    service = read_bool("do you like our services(YES,NO or Y,N): ");
    if(service == false)
    {
        write_line("good to know, we are happy");
    }
    else
    {
        write_line("well give us feedback sir we will improve");
    }
    
    string feedback = read_string("please give feedback: ");
  
    write_line("Thanks for visiting!");
    write_line("Stay healthy");
    
    return 0;
}