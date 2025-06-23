#include "address.h"

Address::Address() : house(""), locality(""), city("") {}

Address::Address(const std::string& house, const std::string& locality, const std::string& city)
    : house(house), locality(locality), city(city) {}

void Address::setHouse(const std::string& h) {
    house = h;
}

std::string Address::getHouse() const {
    return house;
}

void Address::setLocality(const std::string& l) {
    locality = l;
}

std::string Address::getLocality() const {
    return locality;
}

void Address::setCity(const std::string& c) {
    city = c;
}

std::string Address::getCity() const {
    return city;
}

Address::~Address() = default;
