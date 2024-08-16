#include "Pet.h"  // Assuming "Mascota" is translated to "Pet"
#include "Client.h"  // Assuming "Cliente" is translated to "Client"
#include "Consultation.h"  // Assuming "Consulta" is translated to "Consultation"

Pet::Pet(string name, int id, int age, string breed, string gender, int weight, Client* owner)
{
    this->name = name;
    this->id = id;
    this->age = age;
    this->breed = breed;
    this->gender = gender;
    this->weight = weight;
    this->owner = owner;
}

Pet::Pet(string name, int id, int age, string breed, string gender, int weight)
{
    this->name = name;
    this->id = id;
    this->age = age;
    this->breed = breed;
    this->gender = gender;
    this->weight = weight;
    this->owner = nullptr;
}

Pet::~Pet()
{
}

int Pet::getId()
{
    return id;
}

void Pet::addConsultationToHistory(Consultation* consultation)
{
    history.push_back(consultation);
}

void Pet::addToOwner(Client* client)
{
    this->owner = client;
}

string Pet::getName()
{
    return name;
}

string Pet::show()
{
    stringstream ss;
    ss << "Pet's name: " << name << "\nBreed: " << breed << "\nAge: " << age;
    return ss.str();
}
