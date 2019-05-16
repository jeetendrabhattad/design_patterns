#include <iostream>
#include <string>
#include <map>

using namespace std;

struct INotify
{
    virtual void Notify(string info) = 0;
    operator INotify*()
    {
        return this;
    }
};

class Doordarshan : public INotify
{
public:
    virtual void Notify(string info)
    {
        cout<<"Doordarshan received :"<<info<<endl;
    }
};

class NDTV : public INotify
{
public:
    virtual void Notify(string info)
    {
        cout<<"NDTV received :"<<info<<endl;
    }
};

class TimesNow : public INotify
{
public:
    virtual void Notify(string info)
    {
        cout<<"TIMESNOW received :"<<info<<endl;
    }
};

class Publisher
{
protected:
    string name;
    //move below stuff to different class and have its reference and just invoke the BroadCast on it
    //violates SRP
    map<string, INotify*> subscribers;
    void BroadCast(string info)
    {
        auto it = subscribers.begin();
        while(it != subscribers.end())
        {
            it->second->Notify(name+":"+info);
            it++;
        }
    }
public:
    Publisher(string name) : name(name){}
    void Subscribe(string key, INotify *client)
    {
        subscribers[key] = client;
    }
};

class Election : public Publisher
{
public:
    Election() : Publisher("Election"){}
    void ElectionResult(string info)
    {
        BroadCast(info);
    }
};

class Entertainment : public Publisher
{
public:
    Entertainment() : Publisher("Entertainment"){}
    void EntertainmentNews(string info)
    {
        BroadCast(info);
    }
};

class Sports : public Publisher
{
public:
    Sports() : Publisher("Sports"){}
    void SportsNews(string info)
    {
        BroadCast(info);
    }
};

int main()
{
    Doordarshan dd;
    NDTV ndtv;
    TimesNow tn;

    Election elec;
    Entertainment ent;
    Sports sport;

    elec.Subscribe("dd", dd);
    elec.Subscribe("ndtv",ndtv);
    elec.Subscribe("tn", tn);

    ent.Subscribe("ndtv", ndtv);
    ent.Subscribe("tn", tn);

    sport.Subscribe("tn", tn);

    elec.ElectionResult("NDA Wins with 300+ seats");
    ent.EntertainmentNews("RaGa fools people with promise of 72k per year");
    sport.SportsNews("RCB loosing each and every match");
    return 0;
}
