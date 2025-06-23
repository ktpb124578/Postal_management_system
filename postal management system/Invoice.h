#ifndef INVOICE_H
#define INVOICE_H

#include "Payment.h"
#include <string>
#include <iostream>

class Invoice {
protected:
    Payment P;

public:
    Invoice();
    
    void getParcelDetails(int id, int weight, const std::string& dimensions, const std::string& duration,
                          const std::string& senderAddress, const std::string& senderContact,
                          const std::string& receiverAddress, const std::string& receiverContact);
    
    void getMailDetails(); // This should be defined or removed if not used

    ~Invoice();
};

#endif // INVOICE_H
