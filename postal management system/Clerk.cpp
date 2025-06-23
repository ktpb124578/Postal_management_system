#include "Clerk.h"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

Clerk::Clerk() = default;

void Clerk::SignUp() {
    bool validDigits, isUnique;
    string enteredCnic, fileCnic;

    cout << "\n\t ******************* \n";
    cout << "\t SIGN UP A NEW CLERK \n";
    cout << "\t ******************* \n\n";
    cout << "Please enter all the relevant information.\n";

    do {
        validDigits = true;
        isUnique = true;

        cout << "\n* CNIC must be unique, numeric and 13 digits long (no dashes)\n";
        cout << "Enter your CNIC: ";
        getline(cin, enteredCnic);

        for (char ch : enteredCnic) {
            if (!isdigit(ch)) {
                validDigits = false;
                break;
            }
        }

        ifstream inFile("Clerk.txt");
        while (inFile >> fileCnic) {
            if (enteredCnic == fileCnic) {
                isUnique = false;
                break;
            }
            string temp;
            getline(inFile, temp); // skip rest of line
        }
        inFile.close();

    } while (enteredCnic.length() != 13 || !validDigits || !isUnique);

    cnic = enteredCnic;
    PostalWorkers::SignUp();

    ofstream outFile("Clerk.txt", ios::app);
    outFile << cnic << " " << name << " " << number << " " << password << "\n";
    outFile.close();

    cout << "\n\nClerk has been signed up successfully!";
    cout << "\nBack to Home\n";
}

void Clerk::SignIn() {
    string fileCnic, fileName, fileNumber, filePassword;

    cout << "\n\t ************************* \n";
    cout << "\t SIGN IN AN EXISTING CLERK \n";
    cout << "\t ************************* \n\n";
    cout << "Please enter your CNIC and password to sign in.\n";

    bool authenticated = false;

    do {
        cout << "\nEnter CNIC: ";
        getline(cin, cnic);
        cout << "Enter Password: ";
        getline(cin, password);

        ifstream inFile("Clerk.txt");

        while (inFile >> fileCnic >> fileName >> fileNumber >> filePassword) {
            if (cnic == fileCnic && password == filePassword) {
                authenticated = true;
                break;
            }
        }

        inFile.close();

        if (!authenticated) {
            cout << "\nInvalid CNIC or password. Please try again.\n";
        }

    } while (!authenticated);

    cout << "\nClerk signed in successfully!";
    cout << "\nProceeding...\n";
}

Clerk::~Clerk() = default;
