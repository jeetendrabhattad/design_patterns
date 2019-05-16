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

class FileFactory
{
protected:
    virtual File* CreateActualFile() = 0;
public:
    File* CreateFile()
    {
        cout<<"Pre Object Construction General\n";
        File* temp = CreateActualFile();            
        cout<<"Post Object Construction General\n";
        return temp;
    }
};

class BMPFactory : public FileFactory
{
protected:
    virtual File* CreateActualFile()
    {
        cout<<"Pre Object Construction BMP\n";
        File* temp = new BMP();
        cout<<"Post Object Construction BMP\n";
        return temp;
    }
};

class JPEGFactory : public FileFactory
{
protected:
    virtual File* CreateActualFile()
    {
        cout<<"Pre Object Construction JPEG\n";
        File* temp = new JPEG();
        cout<<"Post Object Construction JPEG\n";
        return temp;
    }
};

class WMFFactory : public FileFactory
{
protected:
    virtual File* CreateActualFile()
    {
        cout<<"Pre Object Construction WMF\n";
        File* temp = new WMF();
        cout<<"Post Object Construction WMF\n";
        return temp;
    }
};

class PNGFactory : public FileFactory
{
protected:
    virtual File* CreateActualFile()
    {
        cout<<"Pre Object Construction PNG\n";
        File* temp = new PNG();
        cout<<"Post Object Construction PNG\n";
        return temp;
    }
};

class Factory{
    static map<int, FileFactory*(*)()> file_factory;
public:
    static File* CreateFileObject(int id)
    {
        return file_factory[id]()->CreateFile();
    }
    static void Register(int key, FileFactory* (*val)())
    {
        file_factory[key] = val;
    }
    static void UnRegister(int key)
    {
        file_factory.erase(key);
    }
};
map<int, FileFactory*(*)()> Factory::file_factory;

class Dummy
{
public:
    Dummy()
    {
        #if 0
        // this makes it prototype
        Factory::Register(10, new BMPFactory());
        Factory::Register(20, new JPEGFactory());
        Factory::Register(30, new WMFFactory());
        Factory::Register(40, new PNGFactory());
        #endif
        Factory::Register(10, []()->FileFactory*{return new BMPFactory();});
        Factory::Register(20, []()->FileFactory*{return new JPEGFactory();});
        Factory::Register(30, []()->FileFactory*{return new WMFFactory();});
        Factory::Register(40, []()->FileFactory*{return new PNGFactory();});
    }
}dummy;

int main()
{
    File* file = Factory::CreateFileObject(10);
    file->ProcessFile();
    return 0;
}

//Factory Method Pattern : it is based on the principles of Factory but the implementation has the similar hierarchy of factories as 
//the hierarchy of actual classes
