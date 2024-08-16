#include "Client.h"

Client::Client(int id, string name, int age, int phoneNumber, string location, string clientType)
    : Person(id, name, age, phoneNumber)
{
    this->clientType = clientType;
    this->location = location;
}

Client::~Client()
{
}

string Client::getLocation()
{
    return location;
}

string Client::getClientType()
{
    return clientType;
}

int Client::getNumberOfPets()
{
    return petList.size();
}

void Client::setLocation(string location)
{
    this->location = location;
}

void Client::setClientType(string clientType)
{
    this->clientType = clientType;
}

string Client::showMyPets()
{
    stringstream ss;
    for (int i = 0; i < petList.size(); i++)
    {
        ss << petList[i]->show();
        if (i < petList.size() - 1)
        {
            ss << "\n";
        }
    }
    return ss.str();
}

string Client::showPersonAndPets()
{
    stringstream ss;
    ss << showPerson();
    ss << "\nMine pet/s:\n";
    ss << showMyPets();
    return ss.str();
}

string Client::showPerson()
{
    stringstream ss;
    ss << Person::showPerson() << "\nClient Type: " << clientType << "\nAddress: " << location;
    return ss.str();
}

vector<Pet*> Client::getPets()
{
    return petList;
}

void Client::addPet(Pet* pet)
{
    petList.push_back(pet);
}
