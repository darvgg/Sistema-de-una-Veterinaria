#pragma once
#include "Client.h"
#include "Pet.h"
#include "Employee.h"
#include "Invoice.h"
#include "Consultation.h"
#include "LocalLoader.h"
#include "QuickSort.h"
#include "BinarySearch.h"

class Console;
class Veterinary
{
private:
    // Singleton
    Veterinary(LocalLoader* data);
    //Estaticos
    static Veterinary* instance;
    static float totalProfit;
    //Declaraciones de los atributos
    Console* console;
    LocalLoader* data;

    vector<Client*> clients;
    vector<Pet*> pets;
    vector<Employee*> employees;
    vector<Invoice*> invoices;
    vector<Consultation*> consultations;
    vector<Doctor*> doctors;
    vector<Nurse*> nurses;
    //Funcionalidades de busqueda
    Client* findClient(int id);
    Doctor* findDoctor(int id);
    Nurse* findNurse(int id);
    Consultation* findConsultation(string idConsultation);
    Pet* findPet(int id);
    Invoice* findInvoice(int id);
    //Funcionalidades de registros
    void registerClientAndPets();
    void registerEmployees();
    void registerPet();
    void registerConsultation();
    void registerPets(Client* client);
    void registerInvoice(Consultation* c);
    //Funciones varias
    void generateInvoice();//Generar factura
    void deleteConsultation();//Borrar consulta
    void sortEmployersForSalary();//Ordenar a los empleados por salario
    void sortPetsById();
    int searchPetPosition(int petId);
    void clearScreen();//Limpiar pantalla 
    void getProfit();//Al ser ahora el total de las ganacias un statico solo se llamara a la funcion cuando se necesite sumar total del coste de las consultas
    void searchBinaryPet();
    //Funcionalidades de mostrar
    void showEmployees();    
    void showMenu();
    void showClientWithPets();
    void showInvoice();
public:
    static Veterinary* getInstance(LocalLoader* data);
    ~Veterinary();

    void run();
};
