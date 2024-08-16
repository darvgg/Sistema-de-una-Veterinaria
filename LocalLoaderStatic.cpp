#include "LocalLoaderStatic.h"
#include <string>

vector<Client*> LocalLoaderStatic::getClients()
{
    vector<Client*> clientList;
    clientList.push_back(new Client(1, "Alberto", 19, 75849145, "Tiquipaya", "Casual"));
    clientList.push_back(new Client(2, "Beatriz", 25, 71234567, "Sacaba", "Casual"));
    clientList.push_back(new Client(3, "Carlos", 30, 79876543, "Quillacollo", "Casual"));
    clientList.push_back(new Client(4, "Diana", 22, 76543210, "Tiquipaya", "Casual"));
    clientList.push_back(new Client(5, "Eduardo", 35, 70123456, "Sacaba", "Casual"));
    return clientList;
}

vector<Employee*> LocalLoaderStatic::getEmployees()
{
    vector<Employee*> employeeList;
    employeeList.push_back(new Doctor(100, "Alejandro", 25, 75849145, "Morning", 3050.70, 1, "Cardiology"));
    employeeList.push_back(new Nurse(200, "Maria", 25, 71234567, "Morning", 2050.70, 1));
    employeeList.push_back(new Doctor(300, "Brandon", 30, 79876543, "Afternoon", 2050.70, 3, "Surgery"));
    employeeList.push_back(new Nurse(400, "Carla", 22, 76543210, "Afternoon", 3050.70, 0));
    employeeList.push_back(new Doctor(500, "Tiago", 35, 70123456, "Morning", 3050.70, 5, "Dermatology"));
    employeeList.push_back(new Nurse(500, "Marta", 35, 70123456, "Morning", 2050.70, 4));

    return employeeList;
}

vector<Pet*> LocalLoaderStatic::getPets()
{
    vector<Pet*> petList;
    petList.push_back(new Pet("pipoca", 999, 2,"gato", "female", 200));
    return petList;
}

vector<Pet*> LocalLoaderStatic::getPets(vector<Client*>& clientList)
{
    // se genera de forma semi automatica
    vector<Pet*> petList;
    Pet* animal = nullptr;
    int clientSize = clientList.size();
    for (int i = 0; i < clientSize; i++)
    {
        if (i % 2 == 0)
        {
            animal = new Pet("Toddy", 1001, 2, "Golden", "male", 15 + i, clientList[i]);
            clientList[i]->addPet(animal);
            petList.push_back(animal);
        }
        else
        {
            animal = new Pet("Almendra", 1002, 3, "Bengali", "female", 4, clientList[i]);
            clientList[i]->addPet(animal);
            petList.push_back(animal);
        }
    }
    return petList;
}

vector<Consultation*> LocalLoaderStatic::getConsultations(vector<Client*>& clientList, vector<Employee*> employeeList)
{
    vector<Consultation*> consultationList;
    Consultation* auxConsultation = nullptr;
    int clientSize = clientList.size();
    for (int i = 0; i < clientSize; i++)
    {
        if (employeeList[i]->getEmployeeType() == "Doctor")
        {
            Doctor* auxDoctor = dynamic_cast<Doctor*>(employeeList[i]);
            auxConsultation = new Consultation("ABC_" + to_string(i), "10/09/2023", "Sterilization", clientList[i], auxDoctor, clientList[i]->getPets()[0], "Serious");
            clientList[i]->getPets()[0]->addConsultationToHistory(auxConsultation);
            consultationList.push_back(auxConsultation);
        }
        else
        {
            Nurse* auxNurse = dynamic_cast<Nurse*>(employeeList[i]);
            auxConsultation = new Consultation("ABC_" + to_string(i), "10/09/2023", "Dental Cleaning", clientList[i], auxNurse, clientList[i]->getPets()[0], "Light");
            clientList[i]->getPets()[0]->addConsultationToHistory(auxConsultation);
            consultationList.push_back(auxConsultation);
        }
    }
    return consultationList;
}

vector<Invoice*> LocalLoaderStatic::getInvoices(vector<Consultation*> consultationList)
{
    vector<Invoice*> invoiceList;
    int consultationSize = consultationList.size();//Ninguna de las factura tendra nit por el momento
    for (int i = 0; i < consultationSize; i++)
    {
        if (consultationList[i]->getConsultationType() == "Light")
        {
            invoiceList.push_back(new Invoice(i + 1, consultationList[i], 75.50));
        }
        if (consultationList[i]->getConsultationType() == "Serious")
        {
            invoiceList.push_back(new Invoice(i + 1, consultationList[i], 340));
        }
         if (consultationList[i]->getConsultationType() == "Vaccination")
        {
            invoiceList.push_back(new Invoice(i + 1, consultationList[i], 20));
        }
    }
    return invoiceList;
}  