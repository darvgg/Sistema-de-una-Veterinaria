#include "Person.h"

Person::Person(int id, string name, int age, int phoneNumber)
{
    this->phoneNumber = phoneNumber;
    this->id = id;
    this->name = name;
    this->age = age;
}

Person::~Person()
{
}

int Person::getId()
{
    return id;
}

int Person::getAge()
{
    return age;
}

int Person::getPhoneNumber()
{
    return phoneNumber;
}

string Person::getName()
{
    return name;
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::setPhoneNumber(int phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

string Person::showPerson()
{
    stringstream ss;
    ss << "Name: " << name << "\nPhone Number: " << phoneNumber << "\nID: " << id << "\nAge: " << age;
    return ss.str();
}
