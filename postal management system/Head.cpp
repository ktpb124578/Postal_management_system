#include "Head.h"

Head::Head() {}

void Head::SignIn() {
    bool found = false;
    string _cnic, _name, _number, _password;

    cout << "\n\t ************************ \n";
    cout << "\n\t SIGN IN AN EXISTING HEAD \n";
    cout << "\n\t ************************ \n";

    cout << "\n Please enter all the relevant information. \n";

    do {
        found = false;

        cout << "\n\n Enter CNIC : ";
        getline(cin, cnic);

        cout << "\n\n Enter password : ";
        getline(cin, password);

        file.open("Head.txt"); // Should be "Head.txt" if you want separate file

        if (!file) {
            cout << "\n Error: Unable to open file.\n";
            return;
        }

        while (file >> _cnic >> _name >> _number >> _password) {
            if (cnic == _cnic && password == _password) {
                found = true;
                break;
            }
        }

        file.close();

        if (!found) {
            cout << "\n Invalid CNIC or password. Please try again.\n";
        }

    } while (!found);

    cout << "\n\n Head has been signed in successfully!!";
    cout << "\n\n Please proceed\n";
}

Head::~Head() {}
