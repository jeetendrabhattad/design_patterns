#include <iostream>

using namespace std;

//different ways of implementation
//create static object and use it
//create object and pass wherever required by reference

//- inheritance : allowed or should not be ? : if allowed then constructor and destructor should be made protected.
//- serialization & de-serialization

class Singleton
{
    Singleton(){
        cout<<"Singleton Created\n";
    }
    ~Singleton(){
        cout<<"Singleton Released\n";
    }
    static Singleton* head;
    static Singleton* CreateSingleton()
    {
        if(head == nullptr)
            head = new Singleton();
        return head;
    }
    friend class SmartPTR;
public:
    void DoJob()
    {
        cout<<"Singleton Performing the Job\n";
    }
};

Singleton* Singleton::head = nullptr;

class SmartPTR
{
    //stopping object creation of SmartPTR on heap
    static void* operator new(size_t sz){}
    static void* operator new[](size_t sz){}
    static void operator delete(void* ptr){}
    static void operator delete[](void* ptr){}
    Singleton *pt;
    static int count;
public:
    SmartPTR() : pt(Singleton::CreateSingleton())
    {
        count++;
    }
    SmartPTR(const SmartPTR &par) : pt(par.pt)
    {
        count++;
    }
    SmartPTR& operator=(const SmartPTR &par) = delete; //assignment not allowed
    ~SmartPTR()
    {
        count--;
        if(!count)
        {
            delete pt;
            pt = NULL;
        }
    }
    Singleton* operator->()
    {
        return pt;
    }
};
int SmartPTR::count = 0;

int main()
{
    SmartPTR pt1;
    SmartPTR pt2;
    SmartPTR pt3;
    SmartPTR pt4(pt3);

    pt4->DoJob();
}
