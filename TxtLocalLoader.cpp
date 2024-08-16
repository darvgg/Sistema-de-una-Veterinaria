#include "TxtLocalLoader.h"
#include <fstream>
Client* TxtLocalLoader::findClient(vector<Client*> list, int ci)
{
    for (Client* auxClient : list)
    {
        if (auxClient->getId()== ci)
        {
            return auxClient;
        }
    }
    return nullptr;
}

Employee* TxtLocalLoader::findEmployee(vector<Employee*> list, int ci)
{
    for (Employee* auxEmployee : list)
    {
        if (auxEmployee->getId() == ci)
        {
            return auxEmployee;
        }
    }
    return nullptr;
}

Pet* TxtLocalLoader::findPet(vector<Pet*> list, int id)
{
    for (Pet* auxPet : list)
    {
        if (auxPet->getId() == id)
        {
            return auxPet;
        }
    }
    return nullptr;
}

Consultation* TxtLocalLoader::findConsultation(vector<Consultation*> list, string id)
{
    for (Consultation* auxConsultation : list)
    {
        if (auxConsultation->getId() == id)
        {
            return auxConsultation;
        }
    }
    return nullptr;
}

vector<Client*> TxtLocalLoader::getClients()
{
    vector<Client*> clientList;
    int id, age, phoneNumber;
    string name,location, clientType;
    ifstream file("Clients.txt");
    if (!file.is_open())
    {
        cout << "Unable to open the file.";
    }
    while (file>>id>>name>>age>>phoneNumber>>location>>clientType)
    {
        clientList.push_back(new Client(id, name, age, phoneNumber, location, clientType));
    }
    file.close();
    return clientList;
}

vector<Employee*> TxtLocalLoader::getEmployees()
{
    vector<Employee*> employeeList;
    ifstream fileDoctors("Doctors.txt");
    int id, age, phoneNumber, yearsWorkingstring;
    string name, shiftType, specialty;
    float salary;
    ifstream fileNurses("Nurses.txt");
    if (!fileDoctors.is_open())
    {
        cout << "Unable to open the file.";
    }
    while (fileDoctors >> id >> name >> age >> phoneNumber >> shiftType >> salary >> yearsWorkingstring >> specialty)
    {
        employeeList.push_back(new Doctor(id,name,age,phoneNumber,shiftType,salary,yearsWorkingstring,specialty));
    }
    fileDoctors.close();
    if (!fileNurses.is_open())
    {
        cout << "Unable to open the file.";
    }
    while (fileNurses >> id >> name >> age >> phoneNumber >> shiftType >> salary >> yearsWorkingstring )
    {
        employeeList.push_back(new Nurse(id, name, age, phoneNumber, shiftType, salary, yearsWorkingstring));
    }
    fileNurses.close();
    return employeeList;
}

vector<Pet*> TxtLocalLoader::getPets(vector<Client*>& clientList)
{
    vector<Pet*> petList;
    ifstream file("Pets.txt");    
    string name, breed, gender;
    int id, age, weight, ciOwner;
    Client* owner;
    if (!file.is_open())
    {
        cout << "Unable to open the file.";
    }
    while (file>>ciOwner>>id>>name>>age>>breed>>gender>>weight)
    {
        owner = findClient(clientList, ciOwner);
        Pet* animal = new Pet(name, id, age, breed, gender, weight,owner);
        owner->addPet(animal);
    }
    file.close();
    return petList;
}

vector<Consultation*> TxtLocalLoader::getConsultations(vector<Client*>& clientList, vector<Employee*> employeeList)
{
    vector<Consultation*> consultationList;
    Consultation* auxConsultation=nullptr;
    string consultationId, date, details, type; // type = Light/Vaccination/Serious
    Client* owner;
    Doctor* doctor=NULL;
    Nurse* nurse=NULL;
    Pet* pet;
    string status; // Reserved - Recent
    int ciOwner, idPet, ciEmployee1, ciEmployee2; //si el ciEmployee1 o ciEmployee1 que es el ci de doctor/enfermera fuese 0 significa que no hay doctor/enfermera en la consulta
    ifstream file("Consultations.txt");
    if (!file.is_open())
    {
        cout << "Unable to open the file.";
    }
    while (file>>type>>consultationId>>date>>details>>ciOwner>>ciEmployee1>> ciEmployee2 >>idPet>>status)
    {
        owner = findClient(clientList, ciOwner);
        vector<Pet*>pets=owner->getPets();
        pet = findPet(pets, idPet);
        if ("Serious"==type)
        {
            doctor = dynamic_cast<Doctor*>(findEmployee(employeeList, ciEmployee1));
            auxConsultation = new Consultation(consultationId, date, details, owner, doctor, pet, status);
        }        
        if ("Light"==type)
        {
            nurse = dynamic_cast<Nurse*>(findEmployee(employeeList, ciEmployee2));
            auxConsultation = new Consultation(consultationId, date, details, owner, nurse, pet, status);
        }
        if ("Vaccination" == type)
        {
            nurse = dynamic_cast<Nurse*>(findEmployee(employeeList, ciEmployee2));
            auxConsultation = new Consultation(consultationId, date, details, owner, nurse, pet);
        }
        pet->addConsultationToHistory(auxConsultation);
        consultationList.push_back(auxConsultation);
    }
    file.close();
    return consultationList;
}

vector<Invoice*> TxtLocalLoader::getInvoices(vector<Consultation*> consultationList)
{
    vector<Invoice*> invoiceList;
    int invoiceId;
    Consultation* consultation;
    float amount;
    int nit; //Si al leer hay un nit 0 se usara el constructor de factura que no usa nit
    string idConsultation;
    ifstream file("Invoices.txt");
    if (!file.is_open())
    {
        cout << "Unable to open the file.";
    }
    while (file>>invoiceId>>idConsultation>>amount>>nit)
    {
        consultation = findConsultation(consultationList, idConsultation);
        if (nit==0)
        {
            invoiceList.push_back(new Invoice(invoiceId, consultation, amount));
        }
        invoiceList.push_back(new Invoice(invoiceId, consultation, amount,nit));
    }
    file.close();
    return invoiceList;
}
