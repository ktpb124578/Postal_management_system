#include "Payment.h"
#include "Invoice.h"

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
