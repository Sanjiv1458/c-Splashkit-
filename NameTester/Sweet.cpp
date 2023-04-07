#include "splashkit.h"

#define PRICEDONUT 3.0
#define PRICEMILKSHAKE 4.0
#define PRICEICECREAM 2.0
#define PRICEFRIES 3.5
#define PRICEGULABJAMUN 150

double calculate_combo1_price(int donut, int milkshake, double gulabjamun)

    double result;
    result = donut * PRICEDONUT + milkshake * PRICEMILKSHAKE + gulabjamun * PRICEGULABJAMUN;
    return result;
}

double calculate_combo2_price(int icecream, int fries, double gulabjamun)

    double result;
    result = icecream * PRICEICECREAM + fries * PRICEFRIES + gulabjamun * PRICEGULABJAMUN;
    return result;
}

double calculate_total_price(int donut, int milkshake, int icecream, int fries, double gulabjamun)

    double result;
    result = donut * PRICEDONUT + milkshake * PRICEMILKSHAKE + icecream * PRICEICECREAM+ fries * PRICEFRIES + gulabjamun * PRICEGULABJAMUN;
    return result;
}

void combo_1(int num_donut, int num_milkshake, double gulabjamun)

    write("price of combo1; ");
    write_line(calculate_combo1_price(num_donut, num_milkshake, gulabjamun));
}
void combo_2(int num_icecream, int num_fries, int gulabjamun)

    write("Price of combo2; ");
    write_line(calculate_combo2_price(num_icecream, num_fries, gulabjamun));
}
void total_price(int num_donut, int num_milkshake, int num_icecream, int num_fries, double gulabjamun)

    write("Total Price; ");
    write_line(calculate_total_price(num_donut, num_milkshake, num_icecream, num_fries, gulabjamun));
}

string read_string(string prompt)
  
    string result;  
    write(prompt);
    result = read_line();
    return result;
}
double read_double(string prompt)

    string line;
    line = read_string(prompt);
    return convert_to_double(line);
}

int read_integer(string prompt)

    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

int main()

    string name;
    int num_donut;
    int num_milkshake;
    int num_icecream;
    int num_fries;
    double gulabjamun;
    int option;

    
    name = read_string("Bill name; ");
    num_donut = read_integer("PLEASE enter the number of donut requested; ");
    num_milkshake = read_integer("PLEASE enter the number of milkshake requested; ");
    num_icecream = read_integer("PLEASE enter the number of icecream requested; ");
    num_fries = read_integer("PLEASE enter the number of fries requested; ");
    gulabjamun = read_double("PLEASE enter the WEIGHT OF gulabjamun in KG; ");

    write_line("wlcome to accountant tarunpal singh");
    write("Name; ");
    write_line(name);

    if(to_lowercase(name) == "Madhav Mittal")
    
        write_line("welcome to Shop");
    }
    else if(to_lowercase(name) == "Dhruv Naina")
    
        write_line("welcome to shop");
        write_line("you are a food lover");
    }
    else
    
        write_line("welcome to shop we are waiting for you");
    }
    if(num_donut >= 4 && num_milkshake >= 2)
    
        write_line("you are getting for discount offer of 10%");
    }
    else
    
        write_line("sorry sir you can't claim offer");
    }
    if((num_fries >= 2 && gulabjamun >= 30000) && (num_donut >= 2 && num_milkshake >= 2))
    
        write_line("you are getting offer of 5%");
    }
    else
    
        write_line("sorry sir you can't claim offer");
    }
    do
    
        write_line("1; combo 1");
        write_line("2; combo 2");
        write_line("3; total");
        write_line("4; quit");
        option = read_integer("please choose combo or total price; ");
        switch(option)
        
            case 1;
                   combo_1(num_donut, num_milkshake, gulabjamun);
                break;
            case 2;
                   combo_2(num_icecream, num_fries, gulabjamun);
                break;
            case 3;
                   total_price(num_donut, num_milkshake, num_icecream, num_fries, gulabjamun);
                break;
            case 4;
                   write_line("thanks sir!")    
                default;
                write_line("see you again");
        }
    } while (option != 4);
    
    write_line("thanks for using food; cashier!");
    return 0;
}
