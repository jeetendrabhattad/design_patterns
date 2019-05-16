#include <iostream>
#include <string>

using namespace std;

class ILogger
{
public:
    virtual void LogMessage(string msg) = 0;
};

class NullLogger : public ILogger
{
public:
    virtual void LogMessage(string msg)
    {}
};

//dynamic behavior extension
class Decorator : public ILogger
{
    ILogger *logger;
public:
    Decorator(ILogger *log) : logger(log){}
    virtual void LogMessage(string msg)
    {
        logger->LogMessage(msg);
    }
};

class FileLogger : public Decorator
{
public:
    FileLogger(ILogger *il): Decorator(il){}
    void LogMessage(string msg)
    {
        cout<<"File Logger Logged:"<<msg<<endl;
        Decorator::LogMessage(msg);//traverses the LinkedList
    }
};

class ConsoleLogger : public Decorator
{
public:
    ConsoleLogger(ILogger *il): Decorator(il){}
    void LogMessage(string msg)
    {
        cout<<"Console Logger Logged:"<<msg<<endl;
        Decorator::LogMessage(msg);
    }
};

class ServiceLogger : public Decorator
{
public:
    ServiceLogger(ILogger *il): Decorator(il){}
    void LogMessage(string msg)
    {
        cout<<"Service Logger Logged:"<<msg<<endl;
        Decorator::LogMessage(msg);
    }
};

class EncoderLogger : public Decorator
{
public:
    EncoderLogger(ILogger *il): Decorator(il){}
    void LogMessage(string msg)
    {
        cout<<"Encoder Logger Logged:"<<msg<<endl;
        Decorator::LogMessage(msg);
    }
};

//factory
class LoggerFactory
{
public:
    static ILogger* CreateLoggers()
    {
        return new EncoderLogger(new ServiceLogger(new FileLogger(new ConsoleLogger(new NullLogger()))));
        //return new ServiceLogger;
        //return new ConsoleLogger;
        //return new FileLogger;
        //return new NullLogger;
    }
};


int main()
{
    ILogger *log = LoggerFactory::CreateLoggers();
    cout<<"Business Started."<<endl;
    log->LogMessage("Business Running.");
    cout<<"Business Completed."<<endl;
}
