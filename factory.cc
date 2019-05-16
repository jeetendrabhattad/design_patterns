#include <iostream>
#include <map>
using namespace std;
class File
{
public:
    virtual void ProcessFile() = 0;
};
class BMP : public File//10
{
public:
    BMP()
    {
        cout<<"BMP Constructed\n";
    }
    virtual void ProcessFile()
    {
        cout<<"Processing BMP file\n";
    }
};

class JPEG : public File//20
{
public:
    JPEG()
    {
        cout<<"JPEG Constructed\n";
    }
    virtual void ProcessFile()
    {
        cout<<"Processing JPEG file\n";
    }
};

class WMF : public File//30
{
public:
    WMF()
    {
        cout<<"WMF Constructed\n";
    }
    virtual void ProcessFile()
    {
        cout<<"Processing WMF file\n";
    }
};

class PNG : public File//40
{
public:
    PNG()
    {
        cout<<"PNG Constructed\n";
    }
    virtual void ProcessFile()
    {
        cout<<"Processing PNG file\n";
    }
};

class Factory{
    static map<int, File*(*)()> file_factory;
public:
    static File* CreateFileObject(int id)
    {
        return file_factory[id]();
    }
    static void Register(int key, File*(*val)() )
    {
        file_factory[key] = val;
    }
    static void UnRegister(int key)
    {
        file_factory.erase(key);
    }
};
map<int, File*(*)()> Factory::file_factory;

class Dummy
{
public:
    Dummy()
    {
        cout<<"Pre Object Construction\n";
        Factory::Register(10, []()->File*{ return new BMP();});
        Factory::Register(20, []()->File*{ return new JPEG();});
        Factory::Register(30, []()->File*{ return new WMF();});
        Factory::Register(40, []()->File*{ return new PNG();});
        cout<<"Post Object Construction\n";
    }
}dummy;
int main()
{
    File* file = Factory::CreateFileObject(10);
    file->ProcessFile();
    return 0;
}

//Factory Hides the Construction of Object from Consumer
