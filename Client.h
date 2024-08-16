#pragma once

#include "Person.h"
#include "Pet.h"
#include <vector>

class Client : public Person
{
private:
    vector<Pet*> petList;
    string location, clientType;
  /*Tipo de cliente puede ser Frequent o Casual, si es frecuente tiene 10 % de descuentos
		a la hora de pagar, tambien habra otro descuento del 5% si el cliente tiene mas de 4 mascotas (Preferred Client)*/
public:
    Client(int id, string name, int age, int phoneNumber, string location, string clientType);
    ~Client();
    // Gets
    string getLocation();
    string getClientType();
    int getNumberOfPets(); //Para tener codigo separado una funcion que mostrara solo sus mascotas
    // Sets
    void setLocation(string location);
    void setClientType(string clientType);
    //Tipos Para mostrar
    string showMyPets(); //Para tener codigo separado una funcion que mostrara solo sus mascotas
    string showPersonAndPets();
    string showPerson();
    //Posiblemente podriamos agregar un buscar mascota dentro del duenio
    vector<Pet*> getPets();
    void addPet(Pet* pet);
};


