#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <conio.h> // for getch()

#include "Address.h"

using namespace std;

class Customers {
private:
    string cnic;
    string name;
    string number;
    string password;
    string _password;

    Address* A;

public:
    Customers();

    void SignUp();
    void SignIn();

    string getCnic();
    string getNumber();

    ~Customers();
};

#endif
