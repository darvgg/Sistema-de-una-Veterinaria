#pragma once
#include "LocalLoader.h"

class LocalLoaderStatic : public LocalLoader
{
public:
    vector<Client*> getClients();
    vector<Employee*> getEmployees();
    vector<Pet*> getPets();
    vector<Pet*> getPets(vector<Client*>& clientList);
    vector<Consultation*> getConsultations(vector<Client*>& clientList, vector<Employee*> employeeList);
    vector<Invoice*> getInvoices(vector<Consultation*> consultationList);
};
