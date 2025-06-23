#include "Order.h"

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
