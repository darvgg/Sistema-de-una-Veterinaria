#pragma once
#include "LocalLoader.h"
class TxtLocalLoader : public LocalLoader
{
private:
    Client* findClient(vector<Client*>list, int ci);
    Employee* findEmployee(vector<Employee*>list, int ci);
    Pet* findPet(vector<Pet*>list, int id);
    Consultation* findConsultation(vector<Consultation*> list, string id);

public:
    vector<Client*> getClients();
    vector<Employee*> getEmployees();
    vector<Pet*> getPets(vector<Client*>& clientList);
    vector<Consultation*> getConsultations(vector<Client*>& clientList, vector<Employee*> employeeList);
    vector<Invoice*> getInvoices(vector<Consultation*> consultationList);
};


