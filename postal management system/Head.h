#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

#endif
