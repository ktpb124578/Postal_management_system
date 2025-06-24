// management.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <conio.h>
#include <cctype>
#include <algorithm>

using namespace std;

// ---- Address class ----
class Address {
private:
    std::string house;
    std::string locality;
    std::string city;
public:
    Address();
    Address(const std::string& house, const std::string& locality, const std::string& city);
    void setHouse(const std::string& h);
    std::string getHouse() const;
    void setLocality(const std::string& l);
    std::string getLocality() const;
    void setCity(const std::string& c);
    std::string getCity() const;
    ~Address();
};

Address::Address() : house(""), locality(""), city("") {}
Address::Address(const std::string& house, const std::string& locality, const std::string& city)
    : house(house), locality(locality), city(city) {}
void Address::setHouse(const std::string& h) { house = h; }
std::string Address::getHouse() const { return house; }
void Address::setLocality(const std::string& l) { locality = l; }
std::string Address::getLocality() const { return locality; }
void Address::setCity(const std::string& c) { city = c; }
std::string Address::getCity() const { return city; }
Address::~Address() = default;

// ---- Payment class ----
class Payment {
private:
    int bill;
    int stamp5, stamp10, stamp20, stamp50, stamp100;
public:
    Payment();
    int calculateBill(int weight);
    void calculateStamps(int bill);
    ~Payment();
};

Payment::Payment() : bill(0), stamp5(0), stamp10(0), stamp20(0), stamp50(0), stamp100(0) {}
int Payment::calculateBill(int weight) {
    if (weight <= 0) return 0;
    if (weight == 1) return bill = 100;
    if (weight <= 3) return bill = 175;
    if (weight <= 5) return bill = 250;
    if (weight <= 10) return bill = 375;
    if (weight <= 15) return bill = 500;
    if (weight <= 20) return bill = 625;
    if (weight <= 25) return bill = 750;
    if (weight <= 30) return bill = 875;
    return bill = 0; // handle weight > 30
}
void Payment::calculateStamps(int bill) {
    int total = 0, s100 = 0, s50 = 0, s20 = 0, s10 = 0, s5 = 0;
    std::ifstream fin("Payment.txt");
    if (fin.is_open()) {
        fin >> total >> s100 >> s50 >> s20 >> s10 >> s5;
        fin.close();
    }
    total += bill;
    stamp100 = bill / 100; bill %= 100;
    stamp50 = bill / 50;  bill %= 50;
    stamp20 = bill / 20;  bill %= 20;
    stamp10 = bill / 10;  bill %= 10;
    stamp5  = bill / 5;   bill %= 5;
    s100 += stamp100;
    s50  += stamp50;
    s20  += stamp20;
    s10  += stamp10;
    s5   += stamp5;
    std::ofstream fout("Payment.txt");
    if (fout.is_open()) {
        fout << total << " " << s100 << " " << s50 << " " << s20 << " " << s10 << " " << s5 << std::endl;
        fout.close();
    }
}
Payment::~Payment() {}

// ---- Invoice class ----
class Invoice {
protected:
    Payment P;
public:
    Invoice();
    void getParcelDetails(int id, int weight, const std::string& dimensions, const std::string& duration,
                          const std::string& senderAddress, const std::string& senderContact,
                          const std::string& receiverAddress, const std::string& receiverContact);
    ~Invoice();
};

Invoice::Invoice() {}
void Invoice::getParcelDetails(int id, int weight, const string& dimensions, const string& duration, const string& senderAddress, const string& senderContact, const string& receiverAddress, const string& receiverContact) {
    int bill = P.calculateBill(weight);
    cout << "\n\n";
    cout << "\n\t ************************ \n";
    cout << "\n\t PARCEL INVOICE GENERATED \n";
    cout << "\n\t ************************ \n";
    cout << "\n\n Order ID: " << id;
    cout << "\n\n Weight: " << weight;
    cout << "\t Dimensions: " << dimensions;
    cout << "\t Duration: " << duration;
    cout << "\n\n Sender's Address: " << senderAddress;
    cout << "\n\n Sender's Contact: " << senderContact;
    cout << "\n\n Receiver's Address: " << receiverAddress;
    cout << "\n\n Receiver's Contact: " << receiverContact;
    P.calculateStamps(bill);
    cout << "\n\n\n Bill: Rs." << bill;
    cout << "\n\n Back to Main";
}
Invoice::~Invoice() {}

// ---- PostalWorkers class ----
class PostalWorkers {
protected:
    std::string cnic;
    std::string name;
    std::string password;
    std::string _password;
    std::string number;
public:
    PostalWorkers();
    void SignUp();
    virtual ~PostalWorkers();
};

PostalWorkers::PostalWorkers() : cnic(""), name(""), password(""), _password(""), number("") {}
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

// ---- Clerk class ----
class Clerk : public PostalWorkers {
private:
    std::string cnic;
public:
    Clerk();
    void SignUp();
    void SignIn();
    ~Clerk();
};

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

// ---- Officer class ----
class Officer : public PostalWorkers {
private:
    std::string cnic;
public:
    Officer();
    void SignUp();
    void SignIn();
    ~Officer();
};

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

// ---- Postman class ----
class Postman : public PostalWorkers {
public:
    Postman();
    void SignUp();
    void SignIn();
    ~Postman();
};

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

// ---- Head class ----
class Head {
protected:
    string cnic;
    string password;
    fstream file;
public:
    Head();
    void SignIn();
    ~Head();
};

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

// ---- Customers class ----
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

Customers::Customers() {
    cnic = name = password = _password = number = "";
    A = new Address();
}
string Customers::getCnic() { return cnic; }
string Customers::getNumber() { return number; }
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
Customers::~Customers() { delete A; }

// ---- Order class ----
class Order {
protected:
    int ID;
    int weight;
    string dimensions;
    string duration;
    string senderAddress;
    string senderContact;
    string receiverAddress;
    string receiverContact;
    Invoice I;
    fstream file;
public:
    Order();
    void setParcelDetails(string cnic);
    void traceParcelDetails(string cnic);
    ~Order();
};

Order::Order() {
    ID = 999;
    weight = 0;
    dimensions = "";
    duration = "";
    senderAddress = "";
    senderContact = "";
    receiverAddress = "";
    receiverContact = "";
}
void Order::setParcelDetails(string cnic) {
    string house, locality, city;
    cout << "\n\t ************************* \n";
    cout << "\n\t YOUR PARCEL ORDER DETAILS \n";
    cout << "\n\t ************************* \n";
    cout << "\n Please enter all the relevant information. \n";
    cout << "\n Enter weight: ";
    cin >> weight;
    cin.ignore();
    cout << "\n Enter dimensions: ";
    getline(cin, dimensions);
    cout << "\n Enter duration: ";
    getline(cin, duration);
    cout << "\n Enter sender house number: ";
    getline(cin, house);
    cout << "\n Enter sender locality: ";
    getline(cin, locality);
    cout << "\n Enter sender city: ";
    getline(cin, city);
    senderAddress = house + " " + locality + " " + city;
    cout << "\n Enter sender contact: ";
    getline(cin, senderContact);
    cout << "\n Enter receiver house number: ";
    getline(cin, house);
    cout << "\n Enter receiver locality: ";
    getline(cin, locality);
    cout << "\n Enter receiver city: ";
    getline(cin, city);
    receiverAddress = house + " " + locality + " " + city;
    cout << "\n Enter receiver contact: ";
    getline(cin, receiverContact);
    ID++;
    file.open("Parcel.txt", ios::app);
    file << cnic << " " << ID << " " << weight << " " << dimensions << " " << duration << " ";
    file << senderAddress << " " << senderContact << " ";
    file << receiverAddress << " " << receiverContact << endl;
    file.close();
    cout << "\n\n Parcel order has been placed successfully!!\n\n Please proceed";
    system("CLS");
    I.getParcelDetails(ID, weight, dimensions, duration, senderAddress, senderContact, receiverAddress, receiverContact);
}
void Order::traceParcelDetails(string cnic) {
    string _cnic, dimensions, duration;
    string s_house, s_locality, s_city, s_contact;
    string r_house, r_locality, r_city, r_contact;
    int id, wt;
    file.open("Parcel.txt");
    while (file >> _cnic >> id >> wt >> dimensions >> duration 
                >> s_house >> s_locality >> s_city >> s_contact 
                >> r_house >> r_locality >> r_city >> r_contact) {
        if (_cnic == cnic) {
            cout << "\n\n Order ID: " << id;
            cout << "\n Weight: " << wt << "\t Dimensions: " << dimensions;
            cout << "\n Duration: " << duration;
            cout << "\n\n Sender Address: " << s_house << " " << s_locality << " " << s_city;
            cout << "\n Sender Contact: " << s_contact;
            cout << "\n\n Receiver Address: " << r_house << " " << r_locality << " " << r_city;
            cout << "\n Receiver Contact: " << r_contact;
            cout << "\n\n Status: Pending\n";
        }
    }
    file.close();
    cout << "\n\n Back to Main";
}
Order::~Order() {}

// ---- Main logic ----
void console();
void options1();
void prices();
void controller();

int main() {
    controller();
}

void console() {
    cout << "\n\t\t  **************************************** \n";
    cout << "\n\t\t  WELCOME TO POST COURIER SERVICE \n";
    cout << "\n\t\t  **************************************** \n";
}
void options1() {
    cout << "\n";
    cout << "\t   1. Prices";
    cout << "\t   2. Sign Up";
    cout << "\t   3. Sign In";
    cout << "\t   4. Exit";
}
void prices() {
    cout << "\n PRICE TABLE OF REGULAR MAIL SERVICE";
    cout << "\n";
    cout << "\n             Weight upto         Weight upto         Additional";
    cout << "\n              250 grams           500 grams           500 grams";
    cout << "\n";
    cout << "\n Local         Rs. 25              Rs. 40              Rs. 10";
    cout << "\n";
    cout << "\n Inter-City    Rs. 60              Rs. 100             Rs. 20";
    cout << "\n PRICE TABLE OF URGENT MAIL SERVICE";
    cout << "\n";
    cout << "\n             Weight upto         Weight upto         Additional";
    cout << "\n              250 grams           500 grams           500 grams";
    cout << "\n";
    cout << "\n Local         Rs. 50              Rs. 65              Rs. 25";
    cout << "\n";
    cout << "\n Inter-City    Rs. 85              Rs. 130             Rs. 45";
    cout << "\n\n";
    cout << "\n Back to Home";
}

void controller()
{
    Head H;
    PostalWorkers *P;
    Clerk CL;
    Officer AO;
    Postman PM;
    Customers C;
    Order OR;

    fstream file;

    int to, s1, s2, s3, s4, s5;
    char opt;
    bool flag;
    string cn, na, nu, pa;

    while(1)
    {
        console();
        options1();

        opt = getch();

        system("CLS");

        switch(opt)
        {
            case '1':
                console();
                prices();

                opt = getch();

                system("CLS");
            break;

            case '2':
                console();
                options1();

                cout << "\n";
                cout << "\n\t\t\t\t  ^";
                cout << "\n\t\t\t\t  |";
                cout << "\n\t\t\t\t  |";
                cout << "\n\t\t\t\t  |--- 1. As Postal Worker";
                cout << "\n\t\t\t\t  |";
                cout << "\n\t\t\t\t  |--- 2. As Customer";

                opt = getch();

                system("CLS");

                switch (opt)
                {
                    case '1':
                        console();
                        options1();

                        cout << "\n";
                        cout << "\n\t\t\t\t  ^";
                        cout << "\n\t\t\t\t  |       --- 1. Account Officer";
                        cout << "\n\t\t\t\t  |                               /";
                        cout << "\n\t\t\t\t  |--- 1. As Postal Worker   ----- --- 2. Clerk";
                        cout << "\n\t\t\t\t  |                               \\";
                        cout << "\n\t\t\t\t  |--- 2. As Customer              --- 3. Postman";

                        opt = getch();

                        system("CLS");

                        switch(opt)
                        {
                            case '1':
                                P = &AO;
                                P->SignUp();

                                opt = getch();

                                system("CLS");
                            break;

                            case '2':
                                P = &CL;
                                P->SignUp();

                                opt = getch();

                                system("CLS");
                            break;

                            case '3':
                                P = &PM;
                                P->SignUp();

                                opt = getch();

                                system("CLS");
                            break;

                            default:
                                
                            break;
                        }
                    break;

                    case '2':
                        C.SignUp();

                        opt = getch();

                        system("CLS");
                    break;
                    
                    default:
                        
                    break;
                }
            break;

            case '3':
                console();
                options1();

                cout << "\n";
                cout << "\n\t\t\t\t\t\t  ^";
                cout << "\n\t\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t\t  |--- 1. As Head";
                cout << "\n\t\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t\t  |--- 2. As Postal Workers";
                cout << "\n\t\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t\t  |--- 3. As Customers";

                opt = getch();

                system("CLS");

                switch (opt)
                {
                    case '1':
                        H.SignIn();

                        opt = getch();

                        system("CLS");

                        do
                        {
                            flag = true;
                            console();

                            cout << "\n";
                            cout << "\n   1. Daily Report";
                            cout << "\n   2. Search Postal Workers";
                            cout << "\n   3. Add Employees";
                            cout << "\n   4. Sign Out";

                            opt = getch();

                            system("CLS");

                            switch(opt)
                            {
                                case '1':
                                    cout << "\n\t ***************** \n";
                                    cout << "\n\t YOUR DAILY REPORT \n";
                                    cout << "\n\t ***************** \n";

                                    file.open("Payment.txt");

                                    file >> to >> s1 >> s2 >> s3 >> s4 >> s5;

                                    file.close();

                                    cout << "\n\n Total Earnings : " << to;
                                    cout << "\n";
                                    cout << "\n Stamps sold of each category";
                                    cout << "\n";
                                    cout << "\n  Rs.100   Rs.50   Rs.20   Rs.10   Rs.5";
                                    cout << "\n";
                                    cout << "\n   " << s1 << "       " << s2 << "       " << s3 << "       " << s4 << "       " << s5;

                                    cout << "\n\n Back to Main";

                                    opt = getch();

                                    system("CLS");
                                break;

                                case '2':
                                    console();
                                    
                                    cout << "\n";
                                    cout << "\n   1. Daily Report";
                                    cout << "\n   2. Search Postal Workers";
                                    cout << "\n\t 1. Account Officer";
                                    cout << "\n\t 2. Clerk";
                                    cout << "\n\t 3. Postman";
                                    cout << "\n";
                                    cout << "\n   3. Add Employees";
                                    cout << "\n   4. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            cout << "\n Following is all the information of Account Officers";

                                            file.open("AccountOfficer.txt");
                                            
                                            while(!file.eof())
                                            {
                                                file >> cn >> na >> nu >> pa;

                                                cout << "\n\n";
                                                cout << "\n CNIC : " << cn;
                                                cout << "\n Name : " << na;
                                                cout << "\n Number : " << nu;
                                            }

                                            file.close();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':
                                            cout << "\n Following is all the information of Clerks";

                                            file.open("Clerk.txt");
                                            
                                            while(!file.eof())
                                            {
                                                file >> cn >> na >> nu >> pa;

                                                cout << "\n\n";
                                                cout << "\n CNIC : " << cn;
                                                cout << "\n Name : " << na;
                                                cout << "\n Number : " << nu;
                                            }

                                            file.close();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '3':
                                            cout << "\n Following is all the information of Postmans";

                                            file.open("Postman.txt");
                                            
                                            while(!file.eof())
                                            {
                                                file >> cn >> na >> nu >> pa;

                                                cout << "\n\n";
                                                cout << "\n CNIC : " << cn;
                                                cout << "\n Name : " << na;
                                                cout << "\n Number : " << nu;
                                            }

                                            file.close();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        default:

                                        break;
                                    }
                                break;

                                case '3':
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Daily Report";
                                    cout << "\n   2. Search Postal Workers";
                                    cout << "\n   3. Add Employees";
                                    cout << "\n\t 1. Account Officer";
                                    cout << "\n\t 2. Clerk";
                                    cout << "\n\t 3. Postman";
                                    cout << "\n";
                                    cout << "\n   4. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            P = &AO;
                                            P->SignUp();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':
                                            P = &CL;
                                            P->SignUp();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '3':
                                            P = &PM;
                                            P->SignUp();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        default:
                                            
                                        break;
                                    }
                                break;

                                case '4':
                                    cout << "\n\n Head has been signed out successfully!!";
                                    cout << "\n\n Back to Home";

                                    opt = getch();

                                    system("CLS");

                                    flag = false;
                                break;

                                default:

                                break;
                            }
                        }
                        while(flag == true);
                    break;

                    case '2':
                        console();
                        options1();

                        cout << "\n";
                        cout << "\n\t\t\t\t\t\t  ^";
                        cout << "\n\t\t\t\t\t\t  |";
                        cout << "\n\t\t\t\t\t\t  |--- 1. As Head                  --- 1. Account Officer";
                        cout << "\n\t\t\t\t\t\t  |                               /";
                        cout << "\n\t\t\t\t\t\t  |--- 2. As Postal Worker   ----- --- 2. Clerk";
                        cout << "\n\t\t\t\t\t\t  |                               \\";
                        cout << "\n\t\t\t\t\t\t  |--- 3. As Customer              --- 3. Postman";

                        opt = getch();

                        system("CLS");

                        switch (opt)
                        {
                            case '1':
                                AO.SignIn();

                                opt = getch();

                                system("CLS");

                                do
                                {
                                    flag = true;
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Manage Accounts";
                                    cout << "\n   2. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            cout << "\n\n All accounts have been managed successfully!!";
                                            cout << "\n\n Back to Main";
                                            
                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':
                                            cout << "\n\n Account officer has been signed out successfully!!";
                                            cout << "\n\n Back to Home";

                                            opt = getch();

                                            system("CLS");

                                            flag = false;
                                        break;

                                        default:

                                        break;
                                    }
                                }
                                while(flag == true);
                            break;
                            
                            case '2':
                                CL.SignIn();

                                opt = getch();

                                system("CLS");

                                do
                                {
                                    flag = true;
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Stamp Orders";
                                    cout << "\n   2. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                        {
                                            ifstream parcelFile("Parcel.txt");
                                            bool hasOrders = false;
                                            if (parcelFile.is_open()) {
                                                string line;
                                                while (getline(parcelFile, line)) {
                                                    if (!line.empty()) {
                                                        hasOrders = true;
                                                        break;
                                                    }
                                                }
                                                parcelFile.clear();
                                                parcelFile.seekg(0, ios::beg);
                                                if (hasOrders) {
                                                    cout << "\n\nList of all parcel orders:\n";
                                                    string _cnic, dimensions, duration;
                                                    string s_house, s_locality, s_city, s_contact;
                                                    string r_house, r_locality, r_city, r_contact;
                                                    int id, wt;
                                                    while (parcelFile >> _cnic >> id >> wt >> dimensions >> duration 
                                                            >> s_house >> s_locality >> s_city >> s_contact 
                                                            >> r_house >> r_locality >> r_city >> r_contact) {
                                                        cout << "\nOrder ID: " << id;
                                                        cout << "\nWeight: " << wt << "\tDimensions: " << dimensions;
                                                        cout << "\nDuration: " << duration;
                                                        cout << "\nSender Address: " << s_house << " " << s_locality << " " << s_city;
                                                        cout << "\nSender Contact: " << s_contact;
                                                        cout << "\nReceiver Address: " << r_house << " " << r_locality << " " << r_city;
                                                        cout << "\nReceiver Contact: " << r_contact;
                                                        cout << "\nStatus: Pending\n";
                                                    }
                                                    cout << "\n\nBack to Main";
                                                } else {
                                                    cout << "\n\nAll orders have been stamped successfully!!";
                                                    cout << "\n\nBack to Main";
                                                }
                                                parcelFile.close();
                                            } else {
                                                cout << "\n\nAll orders have been stamped successfully!!";
                                                cout << "\n\nBack to Main";
                                            }
                                            opt = getch();
                                            system("CLS");
                                        }
                                        break;

                                        case '2':
                                            cout << "\n\n Clerk has been signed out successfully!!";
                                            cout << "\n\n Back to Home";

                                            opt = getch();

                                            system("CLS");

                                            flag = false;
                                        break;

                                        default:

                                        break;
                                    }
                                }
                                while(flag == true);
                            break;

                            case '3':
                                PM.SignIn();

                                opt = getch();

                                system("CLS");

                                do
                                {
                                    flag = true;
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Distribute Orders";
                                    cout << "\n   2. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                        {
                                            ifstream parcelFile("Parcel.txt");
                                            bool hasOrders = false;
                                            if (parcelFile.is_open()) {
                                                string line;
                                                while (getline(parcelFile, line)) {
                                                    if (!line.empty()) {
                                                        hasOrders = true;
                                                        break;
                                                    }
                                                }
                                                parcelFile.clear();
                                                parcelFile.seekg(0, ios::beg);
                                                if (hasOrders) {
                                                    cout << "\n\nList of all parcel orders:\n";
                                                    string _cnic, dimensions, duration;
                                                    string s_house, s_locality, s_city, s_contact;
                                                    string r_house, r_locality, r_city, r_contact;
                                                    int id, wt;
                                                    while (parcelFile >> _cnic >> id >> wt >> dimensions >> duration 
                                                            >> s_house >> s_locality >> s_city >> s_contact 
                                                            >> r_house >> r_locality >> r_city >> r_contact) {
                                                        cout << "\nOrder ID: " << id;
                                                        cout << "\nWeight: " << wt << "\tDimensions: " << dimensions;
                                                        cout << "\nDuration: " << duration;
                                                        cout << "\nSender Address: " << s_house << " " << s_locality << " " << s_city;
                                                        cout << "\nSender Contact: " << s_contact;
                                                        cout << "\nReceiver Address: " << r_house << " " << r_locality << " " << r_city;
                                                        cout << "\nReceiver Contact: " << r_contact;
                                                        cout << "\nStatus: Pending\n";
                                                    }
                                                    cout << "\n\nBack to Main";
                                                } else {
                                                    cout << "\n\nAll orders have been distributed successfully!!";
                                                    cout << "\n\nBack to Main";
                                                }
                                                parcelFile.close();
                                            } else {
                                                cout << "\n\nAll orders have been distributed successfully!!";
                                                cout << "\n\nBack to Main";
                                            }
                                            opt = getch();
                                            system("CLS");
                                        }
                                        break;

                                        case '2':
                                            cout << "\n\n Postman has been signed out successfully!!";
                                            cout << "\n\n Back to Home";

                                            opt = getch();

                                            system("CLS");

                                            flag = false;
                                        break;

                                        default:

                                        break;
                                    }
                                }
                                while(flag == true);
                            break;
                            
                            default:
                                
                            break;
                        }
                    break;

                    case '3':
                        C.SignIn();

                        opt = getch();

                        system("CLS");

                        do
                        {
                            flag = true;
                            console();

                            cout << "\n";
                            cout << "\n   1. Place Order";
                            cout << "\n   2. Trace Order";
                            cout << "\n   3. Sign Out";

                            opt = getch();

                            system("CLS");

                            switch(opt)
                            {
                                case '1':
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Place Order";
                                    cout << "\n\t 1. Order of Parcel";
                                    cout << "\n\t 2. Order of Mail";
                                    cout << "\n";
                                    cout << "\n   2. Trace Order";
                                    cout << "\n   3. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            OR.setParcelDetails(C.getCnic());

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':

                                        break;

                                        default:

                                        break;
                                    }
                                break;

                                case '2':
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Place Order";
                                    cout << "\n   2. Trace Order";
                                    cout << "\n\t 1. Tracing Parcel";
                                    cout << "\n\t 2. Tracing Mail";
                                    cout << "\n";
                                    cout << "\n   3. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            OR.traceParcelDetails(C.getCnic());

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':

                                        break;

                                        default:

                                        break;
                                    }
                                break;

                                case '3':
                                    cout << "\n\n Customer has been signed out successfully!!";
                                    cout << "\n\n Back to Home";

                                    opt = getch();

                                    system("CLS");

                                    flag = false;
                                break;

                                default:

                                break;
                            }
                        }
                        while(flag == true);
                        
                    break;
                    
                    default:
                        
                    break;
                }
            break;

            case '5':
                exit(0);
            break;
            
            default:
                exit(0);
            break;
        }
    }
    
} 