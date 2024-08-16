#include "Nurse.h"

Nurse::Nurse(int id, string name, int age, int phoneNumber, string shiftType, float salary, int yearsWorking)
    : Employee(id, name, age, phoneNumber, "Nurse", shiftType, salary, yearsWorking)
{
}

Nurse::~Nurse()
{
}
