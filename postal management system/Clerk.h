#ifndef CLERK_H
#define CLERK_H

#include "PostalWorkers.h"
#include <string>
#include <fstream>

class Clerk : public PostalWorkers {
private:
    std::string cnic;

public:
    Clerk();

    void SignUp();
    void SignIn();

    ~Clerk();
};

#endif
