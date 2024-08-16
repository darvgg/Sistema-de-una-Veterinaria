#pragma once
#include "Consultation.h"

class Invoice
{
private:
    int invoiceId;
    Consultation* consultation;
    float amount;
    int nit;

    void modificateAmount();


public:
   //Si el cliente da nit
    Invoice(int invoiceId, Consultation* consultation, float amount, int nit);
    //Si el cliente no da nit
    Invoice(int invoiceId, Consultation* consultation, float amount);
    ~Invoice();

    float getAmount();
    int getId();
    Consultation* getConsultation();

    string showInvoice();
};
