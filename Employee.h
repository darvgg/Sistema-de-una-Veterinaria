#pragma once
#include "Person.h"

class Employee : public Person
{
protected:
    string employeeType, shiftType;
    //Tipo turno puede ser: afternoon, morning, solamente un dia quizas
    float salary;
    int yearsWorking;

public:
    Employee(int id, string name, int age, int phoneNumber, string employeeType, string shiftType, float salary, int yearsWorking);
    ~Employee();
    
    // Gets
    int gerId();
    string getName();
    int getAge();
    int getPhoneNumber();
    float getSalary();
    string getShiftType();
    string getEmployeeType();
    int getYearsWorking();

    // Sets
    void setSalary(float salary);
    void setShiftType(string shiftType);

    string showPerson();
    string showFullInformation();

    //Operadores
    bool operator<(const Employee& other) {
        return this->salary < other.salary;
    }
    bool operator>(const Employee& other) const {
        return this->salary > other.salary;
    }
};
