#include <iostream>

using namespace std;

//template<typename T>
//class Account<T>;
class SavingsAccount;
class CurrentAccount;
class DematAccount;

class ITransInfo
{
    public:
    //virtual void SendInfo(Account<T>*) = 0;
    virtual void SendInfo(SavingsAccount*) = 0;
    virtual void SendInfo(CurrentAccount*) = 0;
    virtual void SendInfo(DematAccount*) = 0;    
};

class NullTrans : public ITransInfo
{
    public:
    //void SendInfo(Account*){}
    void SendInfo(SavingsAccount*){}
    void SendInfo(CurrentAccount*){}
    void SendInfo(DematAccount*){}   
};

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
    static ITransInfo *info;
    Account(Database *d) : db(d) {}
    public:
    void DoJob()
    {
        db->OpenDB();
        static_cast<T*>(this)->ActualJob();
        db->CloseDB();
    }
    static void SetTransInfo(ITransInfo *in)
    {
        delete info;
        info = in;
    }
};

template <typename T>
ITransInfo* Account<T>::info = new NullTrans;
class SavingsAccount : public Account<SavingsAccount>
{
public:
    SavingsAccount(Database *d) : Account(d) {}
    void ActualJob(){
        cout<<"Savings Actual Job.\n";
        //transaction info
        info->SendInfo(this);
    }
};

class CurrentAccount : public Account<CurrentAccount>
{
public:
    CurrentAccount(Database *d) : Account(d) {}
    void ActualJob(){
        cout<<"Current Actual Job.\n";
        //transaction info
        info->SendInfo(this);
    }
};

class DematAccount : public Account<DematAccount>
{
public:
    DematAccount(Database *d) : Account(d) {}
    void ActualJob(){
        cout<<"Demat Actual Job.\n";
        //transaction info
        info->SendInfo(this);
    }
};

//consumer
class DiwaliTrans : public ITransInfo
{
    public:
    void SendInfo(SavingsAccount*){
        cout<<"Diwali Savings\n";
    }
    void SendInfo(CurrentAccount*){
        cout<<"Diwali Current\n";
    }
    void SendInfo(DematAccount*){
        cout<<"Diwali demat\n";
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
    sa.SetTransInfo(new DiwaliTrans);
    sa.DoJob();
    CurrentAccount ca(&db);
    ca.DoJob();
    DematAccount da(&db);
    da.DoJob();
    return 0;
}
