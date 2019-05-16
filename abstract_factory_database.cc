/*
    SQLAdapter      SQLConnection       SQLCommand
    OracleAdapter   OracleConnection    OracleCommand
    DB2Adapter      DB2Connection       DB2Command
*/

//AbstractFactory - Pattern
//useful while switching between family of components
#include <iostream>

using namespace std;

class Adapter{
    public:
    virtual void CreateAdapter() = 0;
    virtual void AttachAdapter() = 0;
};

class Command{
    public:
    virtual void CreateCommand() = 0;
    virtual void AttachCommand() = 0;
};

class Connection{
    public:
    virtual void CreateConnection() = 0;
    virtual void AttachConnection() = 0;
};

class SQLAdapter : public Adapter{
    public:
    virtual void CreateAdapter()
    {
        cout<<"SQL Adapter Created\n";
    }
    virtual void AttachAdapter()
    {
        cout<<"SQL Adapter Attached\n";
    }
};

class SQLConnection : public Connection{
    public:
    virtual void CreateConnection()
    {
        cout<<"SQL Connection Created\n";
    }
    virtual void AttachConnection()
    {
        cout<<"SQL Connection Attached\n";
    }
};

class SQLCommand : public Command{
    public:
    virtual void CreateCommand()
    {
        cout<<"SQL Command Created\n";
    }
    virtual void AttachCommand()
    {
        cout<<"SQL Command Attached\n";
    }
};

class OracleAdapter : public Adapter{
    public:
    virtual void CreateAdapter()
    {
        cout<<"Oracle Adapter Created\n";
    }
    virtual void AttachAdapter()
    {
        cout<<"Oracle Adapter Attached\n";
    }
};

class OracleConnection : public Connection{
    public:
    virtual void CreateConnection()
    {
        cout<<"Oracle Connection Created\n";
    }
    virtual void AttachConnection()
    {
        cout<<"Oracle Connection Attached\n";
    }
};

class OracleCommand : public Command{
    public:
    virtual void CreateCommand()
    {
        cout<<"Oracle Command Created\n";
    }
    virtual void AttachCommand()
    {
        cout<<"Oracle Command Attached\n";
    }
};


class DB2Adapter : public Adapter{
    public:
    virtual void CreateAdapter()
    {
        cout<<"DB2 Adapter Created\n";
    }
    virtual void AttachAdapter()
    {
        cout<<"DB2 Adapter Attached\n";
    }
};

class DB2Connection : public Connection{
    public:
    virtual void CreateConnection()
    {
        cout<<"DB2 Connection Created\n";
    }
    virtual void AttachConnection()
    {
        cout<<"DB2 Connection Attached\n";
    }
};

class DB2Command : public Command{
    public:
    virtual void CreateCommand()
    {
        cout<<"DB2 Command Created\n";
    }
    virtual void AttachCommand()
    {
        cout<<"DB2 Command Attached\n";
    }
};

class Factory
{
    public:
    virtual Adapter* BuildAdapter() = 0 ;
    virtual Connection* BuildConnection() = 0 ;
    virtual Command* BuildCommand() = 0 ;
};

class SQLFactory : public Factory
{
    public:
    virtual Adapter* BuildAdapter()
    {
        return new SQLAdapter();
    }
    virtual Connection* BuildConnection()
    {
        return new SQLConnection();
    }
    virtual Command* BuildCommand()
    {
        return new SQLCommand();
    }
};
class OracleFactory : public Factory
{
    public:
    virtual Adapter* BuildAdapter()
    {
        return new OracleAdapter();
    }
    virtual Connection* BuildConection()
    {
        return new OracleConnection();
    }
    virtual Command* BuildCommand()
    {
        return new OracleCommand();
    }
};

class DB2Factory : public Factory
{
    public:
    virtual Adapter* BuildAdapter()
    {
        return new DB2Adapter();
    }
    virtual Connection* BuildConection()
    {
        return new DB2Connection();
    }
    virtual Command* BuildCommand()
    {
        return new DB2Command();
    }
};

int main()
{
    Factory *factory = new SQLFactory();
    Adapter* adapter = factory->BuildAdapter();
    adapter->CreateAdapter();
    adapter->AttachAdapter();
    Connection* connection = factory->BuildConnection();
    connection->CreateConnection();
    connection->AttachConnection();
    Command* command = factory->BuildCommand();
    command->CreateCommand();
    command->AttachCommand();
    return 0;
}
