#ifndef POSTALWORKERS_H
#define POSTALWORKERS_H

#include <string>

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

    virtual ~PostalWorkers(); // in case of inheritance
};

#endif
