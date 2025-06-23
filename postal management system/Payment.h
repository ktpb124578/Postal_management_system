#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <fstream>
#include <string>

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

#endif // PAYMENT_H
