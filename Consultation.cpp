#include "Consultation.h"

Consultation::Consultation(string consultationId, string date, string details, Client* owner, Doctor* doctor, Pet* pet, string status)
{
    this->consultationId = consultationId;
    this->date = date;
    this->details = details;
    this->owner = owner;
    this->doctor = doctor;
    this->pet = pet;
    this->nurse = nullptr;
    this->status = status;
    this->type = "Serious";
}

Consultation::Consultation(string consultationId, string date, string details, Client* owner, Nurse* nurse, Pet* pet, string status)
{
    this->consultationId = consultationId;
    this->date = date;
    this->details = details;
    this->owner = owner;
    this->doctor = nullptr;
    this->nurse = nurse;
    this->pet = pet;
    this->status = status;
    this->type = "Light";
}

Consultation::Consultation(string consultationId, string date, string details, Client* owner, Nurse* nurse, Pet* pet)
{
    this->consultationId = consultationId;
    this->date = date;
    this->details = details;
    this->owner = owner;
    this->doctor = nullptr;
    this->nurse = nurse;
    this->pet = pet;
    this->status = "";
    this->type = "Vaccination";
}

Consultation::~Consultation()
{
}

string Consultation::getId()
{
    return consultationId;
}

string Consultation::getDetails()
{
    return details;
}

Client* Consultation::getOwner()
{
    return owner;
}

string Consultation::showConsultation()
{
    stringstream ss;
    ss << "\nConsultation Type: " << type << "\nConsultation Identifier: " << consultationId << "\nDate: " << date;
    ss << "\nDetails of the consultation: " << details;
    ss << "\nOwner's Name: " << owner->getName();
    ss << "\nPet: " << pet->getName();
    if (nurse != nullptr)
    {
        ss << "\nAttending Personnel: " << nurse->getEmployeeType() << " " << nurse->getName();
    }
    else
    {
        ss << "\nAttending Personnel: " << doctor->getEmployeeType() << " " << doctor->getName();
    }
    return ss.str();
}

string Consultation::getClientType()
{
    return owner->getClientType();
}

string Consultation::getConsultationType()
{
    return type;
}

bool Consultation::getPreferredClient()
{
    return owner->getNumberOfPets() >= 4;
}
