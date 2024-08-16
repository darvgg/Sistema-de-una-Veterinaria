#include "Employee.h"

Employee::Employee(int id, string name, int age, int phoneNumber, string employeeType, string shiftType, float salary, int yearsWorking)
    : Person(id, name, age, phoneNumber)
{
    this->salary = salary;
    this->employeeType = employeeType;
    this->shiftType = shiftType;
    this->yearsWorking = yearsWorking;
}

Employee::~Employee()
{
}

int Employee::gerId()
{
    return id;
}

string Employee::getName()
{
    return name;
}

int Employee::getAge()
{
    return age;
}

int Employee::getPhoneNumber()
{
    return phoneNumber;
}

float Employee::getSalary()
{
    return salary;
}

string Employee::getShiftType()
{
    return shiftType;
}

string Employee::getEmployeeType()
{
    return employeeType;
}

int Employee::getYearsWorking()
{
    return yearsWorking;
}

void Employee::setSalary(float salary)
{
    this->salary = salary;
}

void Employee::setShiftType(string shiftType)
{
    this->shiftType = shiftType;
}

string Employee::showPerson()
{
    stringstream ss;
    ss << Person::showPerson() << "\nEmployee Type: " << employeeType << "\nShift: " << shiftType;
    return ss.str();
}

string Employee::showFullInformation()
{
    stringstream ss;
    ss << "id: " << id << endl;
    ss << "name: " << name << endl;
    ss << "age: " << age << endl;
    ss << "phone number: " << phoneNumber << endl;
    ss << "employee Type: " << shiftType << endl;
    ss << "salaty: " << salary << endl;
    ss << "years working: " << yearsWorking << endl;
    return ss.str();
}
