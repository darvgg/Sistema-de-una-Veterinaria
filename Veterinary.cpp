#include "Veterinary.h"
#include <string>
#include "Console.h"
#include <algorithm>  

Veterinary* Veterinary::instance = nullptr;
float Veterinary::totalProfit = 0.00;

Veterinary::Veterinary(LocalLoader* data)
{
    this->data = data;
    console = new Console();
}

Veterinary* Veterinary::getInstance(LocalLoader* data)
{
    if (instance == nullptr)
    {
        instance = new Veterinary(data);
    }
    return instance;
}

Veterinary::~Veterinary()
{
    delete console;
    delete data;
    delete instance;

    for (Client* client : clients)
    {
        delete client;
    }

    for (Pet* pet : pets)
    {
        delete pet;
    }

    for (Employee* employee : employees)
    {
        delete employee;
    }

    for (Invoice* invoice : invoices)
    {
        delete invoice;
    }

    for (Consultation* consultation : consultations)
    {
        delete consultation;
    }
}

void Veterinary::run()
{
    clients = data->getClients();
    employees = data->getEmployees();
    pets = data->getPets(clients);
    consultations = data->getConsultations(clients, employees);
    invoices = data->getInvoices(consultations);
    showMenu();
}

void Veterinary::showMenu()
{
    int option;
    do
    {
        option = console->showMenu();
        switch (option)
        {
        case 1:
            registerClientAndPets();
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 2:
            registerEmployees();
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 3:
            registerPet();
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 4:
            registerConsultation();
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 5:
            deleteConsultation();
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 6:
            generateInvoice();
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 7:
            getProfit();
            console->showObject("Total profit is: " + to_string(totalProfit));
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 8:
            sortEmployersForSalary(); 
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 9:
            showEmployees();
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 10:
            showClientWithPets();
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 11:
            searchBinaryPet();
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        case 12:
            showInvoice();
            console->showObject("Press Enter to continue...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;
        default:
            break;
        }
    } while (option != 0);
}

void Veterinary::showClientWithPets()
{
    int searchCI;
    Client* selectedClient;
    searchCI = console->askPersonCI();
    selectedClient = findClient(searchCI);
    if (selectedClient != nullptr)
    {
        console->showObject("\n---------------------------------\n");
        console->showObject(selectedClient->showPersonAndPets());
    }
    else
    {
        console->showObject("Client not found");
    }
}
void Veterinary::showInvoice()
{
    int searchId;
    Invoice* selectedInvoice;
    searchId = console->askInvoiceId();
    selectedInvoice = findInvoice(searchId);
    if (selectedInvoice != nullptr)
    {
        console->showObject("\n---------------------------------\n");
        console->showObject(selectedInvoice->showInvoice());
    }
    else
    {
        console->showObject("Invoice not found");
    }
}

void Veterinary::registerClientAndPets()
{
    int numPets;

    Client* client = console->registerClient();
    clients.push_back(client);
    numPets = console->askNumberOfPets();
    for (int i = 0; i < numPets; i++)
    {
        registerPets(client);
    }
}

void Veterinary::registerEmployees()
{
    Employee* employee = console->registerEmployee();
    if (employee != nullptr)
    {
        employees.push_back(employee);
    }
    else
    {
        console->showObject("The employee was not instantiated correctly");
        registerEmployees();
    }
}

void Veterinary::registerPet()
{
    Client* selectedClient;
    int searchCI;

    Pet* pet = console->registerPet();
    searchCI = console->askPersonCI();
    selectedClient = findClient(searchCI);
    if (selectedClient != nullptr)
    {
        selectedClient->addPet(pet);
        pets.push_back(pet);
        pet->addToOwner(selectedClient);
    }
    else
    {
        console->showObject("Client not found");
    }
}

Client* Veterinary::findClient(int ci)
{
    for (Client* client : clients)
    {
        if (client->getId() == ci)
        {
            return client;
        }
    }
    return nullptr;
}

void Veterinary::registerConsultation()
{
    string type = console->askConsultationType();
    Pet* selectedPet;
    int ownerCI, employeeCI, petId;
    Consultation* consultation = nullptr;
    Doctor* selectedDoctor = nullptr;
    Nurse* selectedNurse = nullptr;

    Client* selectedClient;
    console->showObject("Client's CI");
    ownerCI = console->askPersonCI();
    selectedClient = findClient(ownerCI);

    console->showObject("Pet's ID");
    petId = console->askPetIdentifier();
    selectedPet = findPet(petId);

    if (type == "Serious")
    {
        console->showObject("Employee's CI");
        employeeCI = console->askPersonCI();
        selectedDoctor = findDoctor(employeeCI);
    }
    else if (type == "Light" || type == "Vaccination")
    {
        console->showObject("Employee's CI");
        employeeCI = console->askPersonCI();
        selectedNurse = findNurse(employeeCI);
    }
    else
    {
        console->showObject("Error entering the consultation type");
        registerConsultation();
    }
    if (selectedDoctor == nullptr || selectedNurse == nullptr || selectedPet == nullptr)
    {
        console->showObject("Consultation could not be registered. No doctor, nurse, client, or pet was assigned");
        registerConsultation();
    }
    if (type == "Serious")
    {
        consultation = console->registerConsultation("ABCD" + to_string(consultations.size()), selectedClient, type, selectedDoctor, selectedPet);
    }
    else if (type == "Light" || type == "Vaccination")
    {
        consultation = console->registerConsultation("ABCD" + to_string(consultations.size()), selectedClient, type, selectedNurse, selectedPet);
    }
    else if (type == "Vaccination")
    {
        consultation = console->registerConsultation("ABCD" + to_string(consultations.size()), selectedClient, type, selectedNurse, selectedPet);
    }
    selectedPet->addConsultationToHistory(consultation);
}

Doctor* Veterinary::findDoctor(int ci)
{
    for (Doctor* doctor : doctors)
    {
        if (doctor->getId() == ci)
        {
            return doctor;
        }
    }
    return nullptr;
}

Nurse* Veterinary::findNurse(int ci)
{
    for(Nurse* nurse :nurses)
    {
        if (nurse->getId() == ci)
        {
            return nurse;
        }
    }
    return nullptr;
}

Invoice* Veterinary::findInvoice(int id)
{
    for(Invoice* invoice :invoices)
    {
        if (invoice->getId() == id)
        {
            return invoice;
        }
    }
    return nullptr;
}

Consultation* Veterinary::findConsultation(string idConsultation)
{
    for (Consultation* consultation : consultations)
    {
        if (consultation->getId() == idConsultation)
        {
            return consultation;
        }
    }
    return nullptr;
}

Pet* Veterinary::findPet(int id)
{
    for (Pet* pet : pets)
    {
        if (pet->getId() == id)
        {
            return pet;
        }
    }
    return nullptr;
}

void Veterinary::registerPets(Client* client)
{
    Pet* pet = console->registerPet(client);
    pets.push_back(pet);
    client->addPet(pet);
}

void Veterinary::deleteConsultation()
{
    string idConsultation;
    idConsultation=console->askConsultationID(); //Asks for the consultation id
    int index = -1;
    for (int i = 0; i < consultations.size(); i++) //In the for loop, it searches for the index of the consultation
    {
        if (consultations[i]->getId() == idConsultation)
        {
            index = i;
        }
    }
    if (index != -1) //If the consultation is found, it will be deleted
    {
        vector<Consultation*>::iterator it = consultations.begin() + index;
        consultations.erase(it);
    }
    else
    {
        console->showObject("The consultation was not found");
    }
}

void Veterinary::sortEmployersForSalary()
{
    
    QuickSort<Employee*>::sort(employees, [](Employee* a, Employee* b) 
    {
        return a->getSalary() > b->getSalary();
    });

    for(Employee* employee : employees)
    {
        string outputMessage = "id:" +to_string(employee->getId()) + "  Name:" + employee->getName() + "  Salary:" + to_string(employee->getSalary()) + "\n";
        console->showObject(outputMessage);
    }
}

void Veterinary::sortPetsById() 
{
    QuickSort<Pet*>::sort(pets, [](Pet* a, Pet* b)
    {
        return a->getId() > b->getId();
    });
}

int Veterinary::searchPetPosition(int petId) 
{
    BinarySearch<Pet*> binarySearch(pets);
    int result = binarySearch.search( new Pet("", petId, 0, "", "", 0, nullptr));
    return result;
}

void Veterinary::searchBinaryPet()
{
    sortPetsById();
    int petId = console->askPetIdentifier();
    int result = searchPetPosition(petId);
    if (result != -1)
    {
        console->showObject("The pet is in the position: " + to_string(result));
        console->showObject("The mascot is: " + pets[result]->show());
    }
    else
    {
        console->showObject("Sorry, the pet you want to search was not found");
    }
}

void Veterinary::registerInvoice(Consultation* c)
{
    float amount = console->askAmount();
    char resp = console->askYesOrNo("Do you want the invoice with NIT (Y/N): ");
    if (resp == 'Y' || resp == 'y')
    {
        int nit = console->askNit();
        console->showObject("The amount to be charged is: " + to_string(amount) + " Bs.");
        invoices.push_back(new Invoice(invoices.size() + 1, c, amount, nit));
    }
    else
    {
        if (resp == 'N' || resp == 'n')
        {
            console->showObject("The amount to be charged is: " + to_string(amount) + " Bs.");
            invoices.push_back(new Invoice(invoices.size() + 1, c, amount));
        }
        else
        {
            console->showObject("Invalid selection");
            registerInvoice(c);
        }
    }
}

void Veterinary::generateInvoice()
{
    string idConsultation = console->askConsultationID();
    Consultation* selectedConsultation = findConsultation(idConsultation);
    if (selectedConsultation == nullptr)
    {
        console->showObject("The invoice cannot be issued, as the consultation was not found");
        return;
    }
    else
    {
        registerInvoice(selectedConsultation);
        console->showObject("Invoice registered");
    }
}

void Veterinary::getProfit()
{
    for (Invoice* invoice : invoices)
    {
        totalProfit += invoice->getAmount();
    }
}

void Veterinary::clearScreen()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix/Linux/mac
#endif
}

void Veterinary::showEmployees()
{
    for( Employee* employee : employees)
    {
        console->showObject("\n---------------------------------\n");
        console->showObject(employee->showFullInformation());
    }
}
