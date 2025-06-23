#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Invoice.h"

using namespace std;

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

#endif
