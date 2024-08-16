#include "Invoice.h"

void Invoice::modificateAmount()
{
    string clientType=consultation->getClientType();
    if (clientType == "Frequent" && consultation->getPreferredClient())
    {
        amount = amount - (amount * 0.10) - (amount * 0.05);
    }
    else
    {
        if (clientType == "Frequent")
        {
            amount = amount - (amount * 0.10);
        }
        else
        {
            if (consultation->getPreferredClient())
            {
                amount = amount - (amount * 0.05);
            }
        }
    }
}

Invoice::Invoice(int invoiceId, Consultation* consultation, float amount, int nit)
{
    this->invoiceId = invoiceId;
    this->consultation = consultation;
    this->amount = amount;
    this->nit = nit;
    modificateAmount();
}

Invoice::Invoice(int invoiceId, Consultation* consultation, float amount)
{
    this->invoiceId = invoiceId;
    this->consultation = consultation;
    this->amount = amount;
    this->nit = -1;
    modificateAmount();
}

Invoice::~Invoice()
{
}

float Invoice::getAmount()
{
    return amount;
}

int Invoice::getId()
{
    return invoiceId;
}

Consultation* Invoice::getConsultation()
{
    return consultation;
}

string Invoice::showInvoice()
{
    stringstream ss;
    ss << "\nInvoice Number: " << invoiceId;
    ss << "\nAmount to Pay: " << amount;
    ss << "\nNit: ";
    if (nit == -1)
    {
        ss << "No nit";
    }
    else
    {
        ss << nit;
    }
    ss << "\nConsultation Details:\n";
    ss << consultation->showConsultation();
    return ss.str();
}
