#include <iostream>
#include <string>
#include <map>
using namespace std;

class MSP
{
    string _make;
    string _series;
    string _processor;
    public:
    static size_t count;
    MSP(string make, string series, string proc) : _make(make), _series(series), _processor(proc)
    {
        count++;
    }
    string getMake() const
    {
        return _make;
    }
    string getSeries() const
    {
        return _series;
    }
    string getProcessor() const
    {
        return _processor;
    }
};
size_t MSP::count = 0;

class MSPCache
{
    static map<string, MSP*> cache;
public:
    static MSP* getMSPObjectFromCache(string make, string series, string proc)
    {
        string key = make+series+proc;
        MSP *temp;
        if(cache.find(key) != cache.end())
            temp = cache[key];
        else
        {
            temp = new MSP(make, series, proc);
            cache[key] = temp;
        }
        return temp;
    }    
};
map<string, MSP*> MSPCache::cache;

class Computer
{
    string _ram;
    string _hd;
    string _monitor;
    MSP*    _msp;
public:
    static size_t count;
    Computer(string ram, string hd, string proc, string make, string monitor, string series):
        _ram(ram),
        _hd(hd),
        _monitor(monitor)
    {
        _msp = MSPCache::getMSPObjectFromCache(make, series, proc);
        count++;
    }

    void Display() const
    {
        cout<<"RAM:"<<_ram<<endl;
        cout<<"HD:"<<_hd<<endl;
        cout<<"MONITOR:"<<_monitor<<endl;
        cout<<"MAKE:"<<_msp->getMake()<<endl;
        cout<<"SERIES:"<<_msp->getSeries()<<endl;
        cout<<"PROCESSOR:"<<_msp->getProcessor()<<endl;
    }
};
size_t Computer::count = 0;
int main()
{
    Computer comp1("16gb", "1tb", "QUAD-Core", "Intel", "15inch", "x451");
    Computer comp2("16gb", "1tb", "QUAD-Core", "Intel", "15inch", "x451");
    Computer comp3("16gb", "1tb", "QUAD-Core", "Intel", "15inch", "x451");
    Computer comp4("16gb", "1tb", "QUAD-Core", "Intel", "15inch", "x452");

    for(auto &x : {comp1, comp2, comp3, comp4})
    {
        cout<<"----------------------------\n";
        x.Display();
    }
    cout<<"Computer Count:"<<Computer::count<<endl;
    cout<<"MSP Count:"<<MSP::count<<endl;
    return 0;
}
//MSP object was shared across multiple objects to save memory, this design pattern is known as fly-weight
//it helps in saving the memory overhead for duplicate state 
