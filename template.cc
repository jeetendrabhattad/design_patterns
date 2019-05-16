#include <iostream>

using namespace std;
#if 0
//SRP
class Account
{
public:
    void WithdrawCA()
    {
        cout<<"Withdraw for Current"<<endl;
    }
    void WithdrawSA()
    {
        cout<<"Withdraw for Savings"<<endl;    
    }
};

//1st refactor
// it can be seen that both are performing a common operation of database opening and closing
// using pure fabrication we can separate out Database interface.
// database object can be instantiated in each account but then the Database object will be present with both the classes hence it is
// better to create Account base class and have DB object with it.
class SavingAccount
{
public:
    void Withdraw()
    {
        cout<<"OPEN DB"<<endl;
        cout<<"Withdraw for Savings"<<endl;    
        cout<<"CLOSE DB"<<endl;
    }
};
class CurrentAccount
{
public:
    void Withdraw()
    {
        cout<<"OPEN DB"<<endl;
        cout<<"Withdraw for Current"<<endl;
        cout<<"CLOSE DB"<<endl;
    }
};
#endif

class Database
{
    public:
    void OpenDB()
    {
        cout<<"OPEN DB"<<endl;
    }
    void CloseDB()
    {
        cout<<"CLOSE DB"<<endl;
    }
};

class Account
{
    protected:
    Database db;
    Account(){}
    virtual void ActualJob() = 0;
    public:
    void DoJob()
    {
        db.OpenDB();
        ActualJob();
        db.CloseDB();
    }
};

class SavingsAccount : public Account
{
protected:
    void ActualJob(){
        cout<<"Savings Actual Job.\n";
    }
};

class CurrentAccount : public Account
{
protected:
    void ActualJob(){
        cout<<"Current Actual Job.\n";
    }
};

int main()
{
#if 0
    SavingAccount sa;
    sa.Withdraw();
    CurrentAccount ca;
    ca.Withdraw();
#endif
    SavingsAccount sa;
    sa.DoJob();
    CurrentAccount ca;
    ca.DoJob();
    return 0;
}
// High Cohesion - SRP
// DIE - Pure Fabrication
// OCP 
