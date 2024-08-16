#pragma once
#include "Employee.h"

class Doctor : public Employee
{
private:
    string specialty;

public:
    Doctor(int id, string name, int age, int phoneNumber, string shiftType, float salary, int yearsWorking, string specialty);
    ~Doctor();

    string getSpecialty();

    string showPerson();
};
