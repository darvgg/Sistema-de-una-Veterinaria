#pragma once
#include <vector>
#include "Doctor.h"
#include "Nurse.h"
#include "Client.h"

class Consultation
{
private:
    string consultationId, date, details, type; // type = Light/Vaccination/Serious
    Client* owner;
    Doctor* doctor;
    Nurse* nurse;
    Pet* pet;
    string status; // Reserved - Recent

public:
    Consultation(string consultationId, string date, string details, Client* owner, Doctor* doctor, Pet* pet, string status);
    // Si es Light o Vaccination, usaran el constructor de abajo porque los vera una enfermera
    Consultation(string consultationId, string date, string details, Client* owner, Nurse* nurse, Pet* pet, string status);
    // Consultation(string consultationId, string date, Client* owner, Pet* pet);
    Consultation(string consultationId, string date, string details, Client* owner, Nurse* nurse, Pet* pet);
    ~Consultation();

    string getId();
    string getDetails();
    string getClientType();
    string getConsultationType();
    bool getPreferredClient(); //Cliente preferencial es cuando tiene mas de 4 mascotas
    Client* getOwner();

    string showConsultation();
};

