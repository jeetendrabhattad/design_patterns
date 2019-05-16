#include <iostream>

using namespace std;

class Approver
{
protected:
    Approver *successor = nullptr;
    void InformSuccessor(size_t loan_amount)
    {
        if(successor != nullptr)
            successor->ProcessLoan(loan_amount);
    }
public:
    virtual void ProcessLoan(size_t amount) = 0;
    void SetSuccessor(Approver *approver)
    {
        successor = approver;
    }
    operator Approver*()
    {
        return this;
    }
};

class Cashier : public Approver
{
public:
    virtual void ProcessLoan(size_t amount)
    {
        if(amount < 20000)
            cout<<"Cashier Processed Loan:"<<amount<<endl;
        else
        {
            cout<<"Cashier Cannot Process Loan:"<<amount<<endl;
            InformSuccessor(amount);
        }
    }
};

class Manager : public Approver
{
public:
    virtual void ProcessLoan(size_t amount)
    {
        if(amount < 50000)
            cout<<"Manager Processed Loan:"<<amount<<endl;
        else
        {
            cout<<"Manager Cannot Process Loan:"<<amount<<endl;
            InformSuccessor(amount);
        }
    }
};

class Director : public Approver
{
public:
    virtual void ProcessLoan(size_t amount)
    {
        if(amount < 70000)
            cout<<"Director Processed Loan:"<<amount<<endl;
        else
        {
            cout<<"Nobody Can Process."<<amount<<endl;
            InformSuccessor(amount);
        }
    }
};


int main()
{
    Cashier cashier;
    Manager manager;
    Director director;
    cashier.SetSuccessor(manager);
    manager.SetSuccessor(director);
    
    cashier.ProcessLoan(15000);
    cashier.ProcessLoan(45000);
    cashier.ProcessLoan(65000);
    cashier.ProcessLoan(75000);

    return 0;
}
