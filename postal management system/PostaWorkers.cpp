#include "PostalWorkers.h"
#include <iostream>
#include <conio.h> // for getch()

using namespace std;

PostalWorkers::PostalWorkers() 
    : cnic(""), name(""), password(""), _password(""), number("") {}

void PostalWorkers::SignUp() {
    char ch;

    cout << "\nEnter your name: ";
    getline(cin, name);

    do {
        cout << "\n* Phone number should be 11 digits *\n";
        cout << "Enter your phone number: ";
        getline(cin, number);
    } while (number.length() != 11);

    do {
        password.clear();
        cout << "\n* Password should be at least 8 characters *\n";
        cout << "Enter your password: ";

        while (true) {
            ch = getch();
            if (ch == 13) break; // Enter key
            password += ch;
            cout << '*';
        }
        cout << '\n';
    } while (password.length() < 8);

    do {
        _password.clear();
        cout << "Confirm your password: ";

        while (true) {
            ch = getch();
            if (ch == 13) break;
            _password += ch;
            cout << '*';
        }
        cout << '\n';
    } while (password != _password);
}

PostalWorkers::~PostalWorkers() = default;
