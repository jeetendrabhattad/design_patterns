#include <iostream>
#include <string>
#include <map>
using namespace std;

class Register
{
public:
    //additional business for construction
};
class ObjectPool
{
public:
    static map<int, ObjectPool*> object_pool;
protected:
    ObjectPool(Register& reg, int key){
        object_pool[key] = this;
    }
    virtual ObjectPool* Clone() = 0;
public:
    virtual void DoJob() = 0;
    static ObjectPool* GetObject(int key)
    {
        return object_pool[key]->Clone();
    }
    ObjectPool(const ObjectPool &obj)
    {

    }
};

map<int, ObjectPool*> ObjectPool::object_pool;

class Currency : public ObjectPool
{
    Currency(Currency& obj) : ObjectPool(obj)
    {
        cout<<"Currency Clonned\n";
    }
public:
    Currency(Register &reg) : ObjectPool(reg, 101){
        cout<<"Currency Registered\n";
    }
    ObjectPool* Clone()
    {
        return new Currency(*this);
    }
    void DoJob()
    {
        cout<<"Currency Info Received\n";
    }
};

class Weather : public ObjectPool
{
    Weather(Weather& obj) : ObjectPool(obj)
    {
        cout<<"Weather Clonned\n";
    }
public:
    Weather(Register &reg) : ObjectPool(reg, 102){
        cout<<"Weather Registered\n";
    }
    ObjectPool* Clone()
    {
        return new Weather(*this);
    }
    void DoJob()
    {
        cout<<"Weather Info Received\n";
    }
};

class SMSProvider : public ObjectPool
{
    SMSProvider(SMSProvider& obj) : ObjectPool(obj)
    {
        cout<<"SMSProvider Clonned\n";
    }
public:
    SMSProvider(Register &reg) : ObjectPool(reg, 103){
        cout<<"SMSProvider Registered\n";
    }
    ObjectPool* Clone()
    {
        return new SMSProvider(*this);
    }
    void DoJob()
    {
        cout<<"SMS Received\n";
    }
};

class Dummy
{
public:
    Dummy()
    {
        Register reg;
        new Currency(reg);
        new Weather(reg);
        new SMSProvider(reg);
    }
}dummy;
int main()
{
    ObjectPool* obj = ObjectPool::GetObject(101);
    obj->DoJob();
    obj = ObjectPool::GetObject(102);
    obj->DoJob();
    obj = ObjectPool::GetObject(103);
    obj->DoJob();
    return 0;
}
