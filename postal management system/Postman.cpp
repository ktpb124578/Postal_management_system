#include "Postman.h"
#include <cctype>

Postman::Postman() {}

void Postman::SignUp() {
    bool isDigitsOnly = true, isUnique = true;
    string inputCnic, existingCnic;

    cout << "\n\t ********************* \n"
         << "\t SIGN UP A NEW POSTMAN \n"
         << "\t ********************* \n\n"
         << " Please enter all the relevant information.\n"
         << " * CNIC should be 13 digits long (no dashes)\n"
         << " * CNIC should only contain digits\n"
         << " * CNIC must be unique\n\n";

    do {
        isDigitsOnly = isUnique = true;

        cout << " Enter your CNIC: ";
        getline(cin, inputCnic);

        if (inputCnic.length() != 13) isDigitsOnly = false;

        for (char c : inputCnic) {
            if (!isdigit(c)) {
                isDigitsOnly = false;
                break;
            }
        }

        ifstream inFile("Postman.txt");
        while (inFile >> existingCnic) {
            if (inputCnic == existingCnic) {
                isUnique = false;
                break;
            }
            inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip rest of the line
        }
        inFile.close();

        if (!isDigitsOnly || !isUnique) {
            cout << "\n Invalid CNIC. Please try again.\n";
        }
    } while (inputCnic.length() != 13 || !isDigitsOnly || !isUnique);

    cnic = inputCnic;
    PostalWorkers::SignUp();

    ofstream outFile("Postman.txt", ios::app);
    outFile << cnic << " " << name << " " << number << " " << password << '\n';
    outFile.close();

    cout << "\n\n Postman has been signed up successfully!\n Back to Home.\n";
}

void Postman::SignIn() {
    bool authenticated = false;
    string existingCnic, existingName, existingNumber, existingPassword;

    cout << "\n\t *************************** \n"
         << "\t SIGN IN AN EXISTING POSTMAN \n"
         << "\t *************************** \n\n"
         << " Please enter your login credentials.\n";

    do {
        cout << "\n Enter CNIC: ";
        getline(cin, cnic);

        cout << " Enter Password: ";
        getline(cin, password);

        ifstream inFile("Postman.txt");
        while (inFile >> existingCnic >> existingName >> existingNumber >> existingPassword) {
            if (cnic == existingCnic && password == existingPassword) {
                authenticated = true;
                break;
            }
        }
        inFile.close();

        if (!authenticated) {
            cout << "\n Invalid credentials. Please try again.\n";
        }
    } while (!authenticated);

    cout << "\n\n Postman has been signed in successfully!\n Please proceed.\n";
}

Postman::~Postman() {}
