#pragma once

#include <iostream>
#include "Veterinary.h"

using namespace std;

class Console
{
private:
public:
    Console();
    ~Console();

    void showObject(string obj);

    int showMenu();

    Client* registerClient();


    int askPetIdentifier();
    int askNumberOfPets();
    int askPersonCI();
    int askNit();
    int askInvoiceId();
    float askAmount();

    string askConsultationType();
    char askYesOrNo(string question);
    string askConsultationID();

    Employee* registerEmployee();
    Pet* registerPet();
    Consultation* registerConsultation(string consultationId, Client* owner, string type, Employee* employeeToAdd, Pet*& pet);
    Pet* registerPet(Client* c);
};
