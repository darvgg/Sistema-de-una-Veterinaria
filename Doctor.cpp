#include "Doctor.h"

Doctor::Doctor(int id, string name, int age, int phoneNumber, string shiftType, float salary, int yearsWorking, string specialty)
    : Employee(id, name, age, phoneNumber, "Doctor", shiftType, salary, yearsWorking)
{
    this->specialty = specialty;
}

Doctor::~Doctor()
{
}

string Doctor::getSpecialty()
{
    return specialty;
}

string Doctor::showPerson()
{
    stringstream ss;
    ss << Employee::showPerson() << "\tSpecialty in: " << specialty;
    return ss.str();
}
