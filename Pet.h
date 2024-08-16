#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Consultation;
class Client;

class Pet
{
private:
    string name, breed, gender;
    int id, age, weight;
    Client* owner;
    vector<Consultation*> history;

public:
    Pet(string name, int id, int age, string breed, string gender, int weight, Client* owner);
    Pet(string name, int id, int age, string breed, string gender, int weight);
    ~Pet();

    int getId();
    void addConsultationToHistory(Consultation* consultation);
    void addToOwner(Client* client);
    string getName();

    string show();
    // operadores para la busqueda binaria
    bool operator<(const Pet& other) const {
        return this->id < other.id;
    }    
    bool operator>(const Pet& other) const {
        return this->id > other.id;
    }    
    bool operator==(const Pet& other) const {
        return this->id == other.id;
    }

};
