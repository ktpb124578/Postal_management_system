#include "Officer.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Officer::Officer() {}

void Officer::SignUp() {
    string newCnic;
    bool isValid = false;

    cout << "\n\t ***************************** \n";
    cout << "\t SIGN UP A NEW OFFICER \n";
    cout << "\t ***************************** \n";

    do {
        cout << "\n * CNIC must be 13 digits and unique *";
        cout << "\n Enter your CNIC: ";
        getline(cin, newCnic);

        isValid = true;

        if (newCnic.length() != 13 || !all_of(newCnic.begin(), newCnic.end(), ::isdigit)) {
            cout << "\n Invalid CNIC format.\n";
            isValid = false;
            continue;
        }

        ifstream fin("Officer.txt");
        string existingCnic;
        while (fin >> existingCnic) {
            string dummy1, dummy2, dummy3;
            fin >> dummy1 >> dummy2 >> dummy3;
            if (existingCnic == newCnic) {
                cout << "\n CNIC already exists.\n";
                isValid = false;
                break;
            }
        }
        fin.close();

    } while (!isValid);

    cnic = newCnic;
    PostalWorkers::SignUp(); // Set name, number, password

    ofstream fout("Officer.txt", ios::app);
    fout << cnic << " " << name << " " << number << " " << password << "\n";
    fout.close();

    cout << "\n Officer has been signed up successfully!\n";
}

void Officer::SignIn() {
    string inputCnic, inputPassword;
    bool authenticated = false;

    cout << "\n\t *********************************** \n";
    cout << "\t SIGN IN EXISTING OFFICER \n";
    cout << "\t *********************************** \n";

    do {
        cout << "\n Enter CNIC: ";
        getline(cin, inputCnic);
        cout << " Enter Password: ";
        getline(cin, inputPassword);

        ifstream fin("Officer.txt");
        string storedCnic, storedName, storedNumber, storedPassword;

        while (fin >> storedCnic >> storedName >> storedNumber >> storedPassword) {
            if (inputCnic == storedCnic && inputPassword == storedPassword) {
                cnic = storedCnic;
                name = storedName;
                number = storedNumber;
                password = storedPassword;
                authenticated = true;
                break;
            }
        }
        fin.close();

        if (!authenticated) {
            cout << "\n Invalid CNIC or password. Please try again.\n";
        }

    } while (!authenticated);

    cout << "\n Signed in successfully! Welcome, " << name << ".\n";
}

Officer::~Officer() {}
#include "Officer.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Officer::Officer() {}

void Officer::SignUp() {
    string newCnic;
    bool isValid = false;

    cout << "\n\t ***************************** \n";
    cout << "\t SIGN UP A NEW OFFICER \n";
    cout << "\t ***************************** \n";

    do {
        cout << "\n * CNIC must be 13 digits and unique *";
        cout << "\n Enter your CNIC: ";
        getline(cin, newCnic);

        isValid = true;

        if (newCnic.length() != 13 || !all_of(newCnic.begin(), newCnic.end(), ::isdigit)) {
            cout << "\n Invalid CNIC format.\n";
            isValid = false;
            continue;
        }

        ifstream fin("Officer.txt");
        string existingCnic;
        while (fin >> existingCnic) {
            string dummy1, dummy2, dummy3;
            fin >> dummy1 >> dummy2 >> dummy3;
            if (existingCnic == newCnic) {
                cout << "\n CNIC already exists.\n";
                isValid = false;
                break;
            }
        }
        fin.close();

    } while (!isValid);

    cnic = newCnic;
    PostalWorkers::SignUp(); // Set name, number, password

    ofstream fout("Officer.txt", ios::app);
    fout << cnic << " " << name << " " << number << " " << password << "\n";
    fout.close();

    cout << "\n Officer has been signed up successfully!\n";
}

void Officer::SignIn() {
    string inputCnic, inputPassword;
    bool authenticated = false;

    cout << "\n\t *********************************** \n";
    cout << "\t SIGN IN EXISTING OFFICER \n";
    cout << "\t *********************************** \n";

    do {
        cout << "\n Enter CNIC: ";
        getline(cin, inputCnic);
        cout << " Enter Password: ";
        getline(cin, inputPassword);

        ifstream fin("Officer.txt");
        string storedCnic, storedName, storedNumber, storedPassword;

        while (fin >> storedCnic >> storedName >> storedNumber >> storedPassword) {
            if (inputCnic == storedCnic && inputPassword == storedPassword) {
                cnic = storedCnic;
                name = storedName;
                number = storedNumber;
                password = storedPassword;
                authenticated = true;
                break;
            }
        }
        fin.close();

        if (!authenticated) {
            cout << "\n Invalid CNIC or password. Please try again.\n";
        }

    } while (!authenticated);

    cout << "\n Signed in successfully! Welcome, " << name << ".\n";
}

Officer::~Officer() {}
