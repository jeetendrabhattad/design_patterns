#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Account
{
    int amount;
public:
    Account(int amt): amount(amt){}
    void Withdraw(int amt)
    {
        amount -= amt;
    }
    void Deposit(int amt)
    {
        amount += amt;
    }
};

class Informers
{
public:
    virtual void Send(string transaction) = 0;
};

class RBI : public Informers
{
public:
    void Send(string transaction)
    {
        cout<<"RBI received:"<<transaction<<endl;
    }
};

class IncomeTax : public Informers
{
public:
    void Send(string transaction)
    {
        cout<<"Income Tax received:"<<transaction<<endl;
    }
};

class ServiceTax : public Informers
{
public:
    void Send(string transaction)
    {
        cout<<"ServiceTax received:"<<transaction<<endl;
    }
};
//behaves like a facade
class TransactionHelper
{
    Account &account;
    vector<Informers*> informers;
public:

    TransactionHelper(Account &acc) : account(acc)
    {
        informers.push_back(new RBI());
        informers.push_back(new IncomeTax());
        informers.push_back(new ServiceTax());
    }
    void Withdraw(int amount)
    {
        cout<<"Logging Info"<<endl;
        account.Withdraw(amount);
        for(auto& informer : informers)
            informer->Send("Amount Withdrawn"+std::to_string(amount));
    }
};

int main()
{
    Account acc(10000);
    TransactionHelper th(acc);
    th.Withdraw(4000);
    return 0;
}
