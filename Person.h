#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Person
{
protected:
    int id, age, phoneNumber;
    string name;

public:
    Person(int id, string name, int age, int phoneNumber);
    virtual ~Person();

    // Getters
    int getId();
    int getAge();
    int getPhoneNumber();
    string getName();

    // Setters
    void setAge(int age);
    void setPhoneNumber(int phoneNumber);

    // Mostrar a la persona
    virtual string showPerson();
};
