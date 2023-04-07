#ifndef TERMINAL_USER_INPUT 
#define TERMINAL_USER_INPUT

#include <string>
using std::string;

string read_string(string prompt);

int read_integer(string prompt);

double read_double(string prompt);

int read_integer_range(string data, int min, int max);

bool read_bool(string prompt);

double calculate_medicine_fever(int medicineA, int medicineB);

double calculate_medicine_cough(int medicineB, int medicineC);

double calculate_medicine_typhoid(int medicineA, int medicineC);

double calculate_medicine_cough_fever_typhoid(int medicineA, int medicineB, int medicineC);

#endif