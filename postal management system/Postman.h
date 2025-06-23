#ifndef POSTMAN_H
#define POSTMAN_H

#include "PostalWorkers.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

class Postman : public PostalWorkers {
public:
    Postman();

    void SignUp();
    void SignIn();

    ~Postman();
};

#endif
