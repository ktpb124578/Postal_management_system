#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
private:
    std::string house;
    std::string locality;
    std::string city;

public:
    Address();
    Address(const std::string& house, const std::string& locality, const std::string& city);

    void setHouse(const std::string& h);
    std::string getHouse() const;

    void setLocality(const std::string& l);
    std::string getLocality() const;

    void setCity(const std::string& c);
    std::string getCity() const;

    ~Address();
};

#endif
