#include <iostream>

using namespace std;
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

template <typename T>
class Account
{
    protected:
    Database *db;
    Account(Database *d) : db(d) {}
    public:
    void DoJob()
    {
        db->OpenDB();
        static_cast<T*>(this)->ActualJob();
        db->CloseDB();
    }
};

class SavingsAccount : public Account<SavingsAccount>
{
public:
    SavingsAccount(Database *d) : Account(d) {}
    void ActualJob(){
        cout<<"Savings Actual Job.\n";
    }
};

class CurrentAccount : public Account<CurrentAccount>
{
public:
    CurrentAccount(Database *d) : Account(d) {}
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
    Database db;
    SavingsAccount sa(&db);
    sa.DoJob();
    CurrentAccount ca(&db);
    ca.DoJob();
    return 0;
}
