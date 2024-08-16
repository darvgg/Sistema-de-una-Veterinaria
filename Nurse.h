#pragma once
#include "Employee.h"

class Nurse : public Employee
{
public:
    Nurse(int id, string name, int age, int phoneNumber, string shiftType, float salary, int yearsWorking);
    ~Nurse();
};
