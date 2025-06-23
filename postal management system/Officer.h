#ifndef OFFICER_H
#define OFFICER_H

#include <string>

class PostalWorkers {
protected:
    std::string name;
    std::string number;
    std::string password;

public:
    virtual void SignUp(); // Assumes this sets name, number, password
};

class Officer : public PostalWorkers {
private:
    std::string cnic;

public:
    Officer();
    void SignUp();
    void SignIn();
    ~Officer();
};

#endif
