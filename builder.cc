#include <iostream>
#include <string>
using namespace std;

//manufacturing units
//mercedes
//tata
//hyundai

class Vehicle
{
public:
    string manufacturer;
    string wheels;
    string stearing;
    string body;
    string engine;
    string windShield;
    virtual void Display() = 0;
    operator Vehicle*()
    {
        return this;
    }
};

class Car : public Vehicle
{
public:
    void Display()
    {
        cout<<"Car Manufactured By :"<<manufacturer<<endl;;
        cout<<"WHEELS :"<<wheels<<endl;;
        cout<<"STEARING :"<<stearing<<endl;;
        cout<<"BODY :"<<body<<endl;;
        cout<<"ENGINE :"<<engine<<endl;;
        cout<<"WINDSHIELD :"<<windShield<<endl;;
    }
};

class Truck : public Vehicle
{
public:
    void Display()
    {
        cout<<"Truck Manufactured By :"<<manufacturer<<endl;;
        cout<<"WHEELS :"<<wheels<<endl;;
        cout<<"STEARING :"<<stearing<<endl;;
        cout<<"BODY :"<<body<<endl;;
        cout<<"ENGINE :"<<engine<<endl;;
        cout<<"WINDSHIELD :"<<windShield<<endl;;
    }
};

class Manufacturer
{
protected:
    string name;
    Vehicle *vehicle;
    Manufacturer(string nm) : name(nm)
    {
        
    }
public:
    virtual void SetWheels() = 0;
    virtual void SetStearing() = 0;
    virtual void SetBody() = 0;
    virtual void SetEngine() = 0;
    virtual void SetWindShield() = 0;
    void SetVehicle(Vehicle* vh)
    {
        vehicle = vh;
        vehicle->manufacturer = name;
    }
    operator Manufacturer*()
    {
        return this;
    }
};

class MercedesCar : public Manufacturer
{
public:
    MercedesCar() : Manufacturer("Mercedes")
    {}
    virtual void SetWheels()
    {
        vehicle->wheels = "ALLOY";
    }

    virtual void SetStearing()
    {
        vehicle->stearing = "Plastics";
    }

    virtual void SetBody()
    {
        vehicle->body = "Steel";
    }

    virtual void SetEngine()
    {
        vehicle->engine = "2000cc";
    }

    virtual void SetWindShield()
    {
        vehicle->windShield = "SaintGobain";
    }
};

class TataCar : public Manufacturer
{
public:
    TataCar() : Manufacturer("Tata")
    {}
    virtual void SetWheels()
    {
        vehicle->wheels = "ALLOY";
    }

    virtual void SetStearing()
    {
        vehicle->stearing = "Plastics";
    }

    virtual void SetBody()
    {
        vehicle->body = "Steel";
    }

    virtual void SetEngine()
    {
        vehicle->engine = "2000cc";
    }

    virtual void SetWindShield()
    {
        vehicle->windShield = "SaintGobain";
    }
};

class TataTruck : public Manufacturer
{
public:
    TataTruck() : Manufacturer("TataTruck")
    {}
    virtual void SetWheels()
    {
        vehicle->wheels = "ALLOY";
    }

    virtual void SetStearing()
    {
        vehicle->stearing = "Plastics";
    }

    virtual void SetBody()
    {
        vehicle->body = "Steel";
    }

    virtual void SetEngine()
    {
        vehicle->engine = "2000cc";
    }

    virtual void SetWindShield()
    {
        vehicle->windShield = "SaintGobain";
    }
};

class Director
{
public:
    static void ConstructionFlow(Vehicle *vehicle, Manufacturer *manufacturer)
    {
        manufacturer->SetVehicle(vehicle);
        manufacturer->SetWheels();
        manufacturer->SetBody();
        manufacturer->SetEngine();
        manufacturer->SetStearing();
        manufacturer->SetWindShield();
    }
};
int main()
{
    Car car;
    Truck truck;
    MercedesCar mercCarBuilder;
    TataTruck tataTruckBuilder;
    TataCar   tataCarBuilder;

    Director::ConstructionFlow(car, tataCarBuilder);
    car.Display();
    Director::ConstructionFlow(truck, tataTruckBuilder);
    truck.Display();
    Director::ConstructionFlow(car, mercCarBuilder);
    car.Display();
    return 0;
}
