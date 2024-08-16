#include "Console.h"

Console::Console()
{
}

Console::~Console()
{
}

void Console::showObject(string obj)
{
    cout << obj << endl;
}

int Console::showMenu()
{
    int op;
    cout << "\n-------------------------------\n";
    cout << "1. Register new client" << endl;
    cout << "2. Register new employee" << endl;
    cout << "3. Register new pet" << endl;
    cout << "4. Register Consultation (Serious/Light/Vaccination)" << endl;
    cout << "5. Delete Consultation" << endl; //Falta agregar para que se borre la factura para que recien se borre la consulta
    cout << "6. Generate invoice" << endl; // Creo q iria la parte de calcular descuento en la factura
    cout << "7. Show total profit" << endl;
    cout << "8. Sort employeers (salary)" <<endl;
    cout << "9. Show all employeers info" <<endl;
    cout << "10. Show the customer with their pets" << endl;
    cout << "11. Search pet position" <<endl;
    cout << "12. Show invoince" <<endl;
    cout << "0. Exit" << endl;
    cout << "\n-------------------------------\n";
    cin >> op;
    return op;
}

Client* Console::registerClient()
{
    int id, age, phoneNumber;
    string name;
    string location, clientType;

    cout << "\nID: "; cin >> id;
    cout << "Name: "; cin >> name;
    cout << "Age: "; cin >> age;
    cout << "Phone Number: "; cin >> phoneNumber;
    cout << "Location: "; cin >> location;
    cout << "Client Type: (Frequent, Casual)"; cin >> clientType;
    return new Client(id, name, age, phoneNumber, location, clientType);
}

int Console::askPetIdentifier()
{
    int petId;
    cout << "\nPet ID: "; cin >> petId;
    return petId;
}

int Console::askNumberOfPets()
{
    int numPets;
    cout << "\nEnter the number of pets: "; cin >> numPets;
    return numPets;
}

int Console::askPersonCI()
{
    int personId;
    cout << "\nPerson ID: "; cin >> personId;
    return personId;
}

int Console::askInvoiceId()
{
    int invoiceId;
    cout <<"\n Invoice Id: ";
    cin>> invoiceId;
    return invoiceId;
}

int Console::askNit()
{
    int nit;
    cout << "Enter client's NIT: "; cin >> nit;
    return nit;
}

float Console::askAmount()
{
    float amount;
    cout << "Enter amount (00.00): "; cin >> amount;
    return amount;
}

string Console::askConsultationType()
{
    string type;
    cout << "\nType (Serious/Light/Vaccination): "; cin >> type;
    return type;
}

char Console::askYesOrNo(string question)
{
    char resp;
    cout << endl << question; cin >> resp;
    return resp;
}

string Console::askConsultationID()
{
    string resp;
    cout << "\nEnter the consultation identifier: "; cin >> resp;
    return resp;
}

Employee* Console::registerEmployee()
{
    int id, age, phoneNumber;
    string name;

    string employeeType, shiftType;
    //Tipo turno puede ser: tarde, manana, solamente un dia quizas
    float salary;
    int yearsOfWorking;
    string specialty;
    Employee* employee = nullptr;
    cout << "ID: "; cin >> id;
    cout << "Name: "; cin >> name;
    cout << "Age (Years): "; cin >> age;
    cout << "Phone Number: "; cin >> phoneNumber;
    cout << "Employee Type (Doctor/Nurse): "; cin >> employeeType;
    cout << "Shift Type (Morning/Afternoon): "; cin >> shiftType;
    cout << "Salary: "; cin >> salary;
    cout << "Years Working (Experience): "; cin >> yearsOfWorking;
    if (employeeType == "Doctor")
    {
        cout << "Specialty: "; cin >> specialty;
        employee = new Doctor(id, name, age, phoneNumber, shiftType, 7000, yearsOfWorking, specialty);
    }
    else
    {
        employee = new Nurse(id, name, age, phoneNumber, shiftType, 3000, yearsOfWorking);
    }
    return employee;
}

Pet* Console::registerPet()
{
    string name;
    int id;
    int age;
    string breed;
    string gender;
    int weight;

    cout << "Name: "; cin >> name;
    cout << "ID: "; cin >> id;
    cout << "Age (Years): "; cin >> age;
    cout << "Breed: "; cin >> breed;
    cout << "Gender: "; cin >> gender;
    cout << "Weight: "; cin >> weight;
    return new Pet(name, id, age, breed, gender, weight);
}

Consultation* Console::registerConsultation(string consultationId, Client* owner, string type, Employee* employeeToAdd, Pet*& pet)
{
    string date, details; //tipo = leve y grave 
    string status; //Reservado - Emergencia
    Consultation* consultation = nullptr;
    cout << "Date (dd/mm/yyyy): "; cin >> date;
    cout << "Details: "; cin >> details;
    if (type != "Vaccination")
    {
        cout << "Status (Reserved-Emergency): "; cin >> status;
    }
    if (type == "Serious")
    {
        Doctor* docAux = dynamic_cast<Doctor*>(employeeToAdd);
        consultation = new Consultation(consultationId, date, details, owner, docAux, pet, status);
    }
    else if(type == "Light")
    {
        Nurse* nurseAux = dynamic_cast<Nurse*>(employeeToAdd);
        consultation = new Consultation(consultationId, date, details, owner, nurseAux, pet, status);
    }
    else if (type == "Vaccination")
    {
        Nurse* nurseAux = dynamic_cast<Nurse*>(employeeToAdd);
        consultation = new Consultation(consultationId, date, details, owner, nurseAux, pet);
    }
    return consultation;
}

Pet* Console::registerPet(Client* c)
{
    string name;
    int id;
    int age;
    string breed;
    string gender;
    int weight;

    cout << "Name: "; cin >> name;
    cout << "ID: "; cin >> id;
    cout << "Age (years): "; cin >> age;
    cout << "Breed: "; cin >> breed;
    cout << "Gender: "; cin >> gender;
    cout << "Weight: "; cin >> weight;

    Pet* pet = new Pet(name, id, age, breed, gender, weight, c);
    return pet;
}
