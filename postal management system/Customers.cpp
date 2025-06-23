#include "Customers.h"
#include "Address.cpp" // Consider moving this to the .h if needed globally

Customers::Customers() {
    cnic = name = password = _password = number = "";
    A = new Address();
}

string Customers::getCnic() {
    return cnic;
}

string Customers::getNumber() {
    return number;
}

void Customers::SignUp() {
    char ch;
    string house, locality, city;
    string _cnic;
    bool validDigits, unique;

    cout << "\n\t **********************\n";
    cout << "\t SIGN UP A NEW CUSTOMER\n";
    cout << "\t **********************\n\n";

    do {
        validDigits = true;
        unique = true;

        cout << "* CNIC should be 13 digits (without dashes) and unique *\n";
        cout << "Enter your CNIC: ";
        getline(cin, cnic);

        if (cnic.length() != 13) validDigits = false;
        for (char c : cnic)
            if (!isdigit(c)) validDigits = false;

        ifstream infile("Customer.txt");
        while (infile >> _cnic) {
            infile.ignore(numeric_limits<streamsize>::max(), '\n');
            if (cnic == _cnic) {
                unique = false;
                break;
            }
        }
        infile.close();
    } while (!validDigits || !unique);

    cout << "Enter your name: ";
    getline(cin, name);

    do {
        cout << "* Phone number must be 11 digits *\n";
        cout << "Enter your phone number: ";
        getline(cin, number);
    } while (number.length() != 11);

    cout << "Enter your house number: ";
    getline(cin, house);
    A->setHouse(house);

    cout << "Enter your locality: ";
    getline(cin, locality);
    A->setLocality(locality);

    cout << "Enter your city: ";
    getline(cin, city);
    A->setCity(city);

    do {
        password.clear();
        cout << "* Password must be at least 8 characters *\nEnter your password: ";
        while ((ch = getch()) != 13) {
            password += ch;
            cout << '*';
        }
        cout << '\n';
    } while (password.length() < 8);

    do {
        _password.clear();
        cout << "Confirm your password: ";
        while ((ch = getch()) != 13) {
            _password += ch;
            cout << '*';
        }
        cout << '\n';
    } while (password != _password);

    ofstream outfile("Customer.txt", ios::app);
    outfile << cnic << " " << name << " " << number << " "
            << A->getHouse() << " " << A->getLocality() << " "
            << A->getCity() << " " << password << endl;
    outfile.close();

    cout << "\nCustomer signed up successfully!\nReturning to home...\n";
}

void Customers::SignIn() {
    bool found = false;
    string _cnic, _name, _number, _house, _locality, _city, _password;

    cout << "\n\t ****************************\n";
    cout << "\t SIGN IN AN EXISTING CUSTOMER\n";
    cout << "\t ****************************\n";

    do {
        cout << "Enter CNIC: ";
        getline(cin, cnic);
        cout << "Enter password: ";
        getline(cin, password);

        ifstream infile("Customer.txt");
        while (infile >> _cnic >> _name >> _number >> _house >> _locality >> _city >> _password) {
            if (_cnic == cnic && _password == password) {
                found = true;
                break;
            }
        }
        infile.close();

        if (!found)
            cout << "Invalid CNIC or password. Try again.\n";

    } while (!found);

    cout << "\nCustomer signed in successfully!\nProceeding...\n";
}

Customers::~Customers() {
    delete A;
}
