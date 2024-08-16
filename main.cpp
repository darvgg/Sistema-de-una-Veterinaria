#include <iostream>
#include "Veterinary.h"  
#include "LocalLoader.h"
#include "LocalLoaderStatic.h"
#include "TxtLocalLoader.h" 

int main()
{
    LocalLoader* myLocalLoader = new LocalLoaderStatic();
    Veterinary* uniqueInstance = Veterinary::getInstance(myLocalLoader);
    uniqueInstance->run();
    return 0;
}
/*
void testInvoiceWithOnePet() //Test Factura con una mascota
{
 	Client* cliente = new Client(1, "pepito", 18, 6478485, "Av. America", "Frequent");
  	Pet* mascota = new Pet("Mac", 11, 2, "perro", "macho", 15, cliente);
  	cliente->addPet(mascota);
  	Nurse* enfermera = new Nurse(100, "Albertina", 28, 6523565, "Enfermera", 1400, 5);
  	Consultation* consulta = new Consultation("ABC_1", "14/12/2023", "Anti Rabia", cliente, enfermera, mascota);
  	Invoice* factura = new Invoice(123, consulta, 70.50);
  	cout << "\nFactura:\n";
  	cout<<factura->showInvoice();
  	cout << endl;
  	cout << "\nConsulta:\n";
  	cout << consulta->showConsultation();
  	cout << endl;
  	cout << "\nEnfermera:\n";
  	cout << enfermera->showPerson();
  	cout << endl;
  	cout << "\nCliente y mascotas:\n";
  	cout << cliente->showPersonAndPets();
  	cout << endl;
  	cout << "\nMascota:\n";
  	cout << mascota->show();
}
void testInvoiceWithMorePets() //Test Factura con mas de 4 mascotas
{
  	Client* cliente = new Client(1, "pepito", 18, 6478485, "Av. America", "Frequent");
  	Pet* mascota1 = new Pet("Mac1", 11, 2, "perro", "macho", 15, cliente);
  	cliente->addPet(mascota1);
  	Pet* mascota2 = new Pet("Mac2", 11, 2, "perro", "macho", 15, cliente);
  	cliente->addPet(mascota2);
  	Pet* mascota3 = new Pet("Mac3", 11, 2, "perro", "macho", 15, cliente);
  	cliente->addPet(mascota3);
  	Pet* mascota4 = new Pet("Mac4", 11, 2, "perro", "macho", 15, cliente);
  	cliente->addPet(mascota4);
  	Pet* mascota5 = new Pet("Mac5", 11, 2, "perro", "macho", 15, cliente);
  	cliente->addPet(mascota5);
  	Nurse* enfermera = new Nurse(100, "Albertina", 28, 6523565, "Enfermera", 1400, 5);
  	Consultation* consulta = new Consultation("ABC_1", "14/12/2023", "Anti Rabia", cliente, enfermera, mascota1);
  	Invoice* factura = new Invoice(123, consulta, 70.50);
  	cout << "\nFactura:\n";
  	cout << factura->showInvoice();
  	cout << endl;
  	cout << "\nConsulta:\n";
  	cout << consulta->showConsultation();
  	cout << endl;
  	cout << "\nEnfermera:\n";
  	cout << enfermera->showPerson();
  	cout << endl;
  	cout << "\nCliente y mascotas:\n";
  	cout << cliente->showPersonAndPets();
  	cout << endl;
}*/