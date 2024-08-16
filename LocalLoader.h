#pragma once
#include "Employee.h"
#include "Pet.h"
#include "Client.h"
#include "Invoice.h"
#include "Consultation.h"

class LocalLoader
{
protected:
public:
    LocalLoader();
    virtual ~LocalLoader();
    virtual vector<Client*> getClients() = 0;
    virtual vector<Employee*> getEmployees() = 0;
    virtual vector<Pet*> getPets(vector<Client*>& clientList) = 0;
    virtual vector<Consultation*> getConsultations(vector<Client*>& clientList, vector<Employee*> employeeList) = 0;
    virtual vector<Invoice*> getInvoices(vector<Consultation*> consultationList) = 0;
};
