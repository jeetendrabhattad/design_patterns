#include <iostream>

using namespace std;

template<typename T>
class IIterator
{
public:
    virtual void First() = 0;
    virtual void Last() = 0;
    virtual bool Next() = 0;
    virtual T Current() = 0;
};

class Container
{
    int arr[5];
    int size = 5;
public:
    Container() : arr{1,2,3,4,5}
    {
    }
    Container* begin()
    {
        return this;
    }
    class Iterator : public IIterator<int>
    {
        Container *container;
        int size;
        int nav = 0;
        public:
        Iterator(Container *cont) : container(cont), size(cont->size)
        {

        }
        virtual void First()
        {
            nav = 0;
        }
        virtual void Last()
        {
            nav = size - 1;
        }
        
        virtual bool Next()
        {
            nav++;
            return nav < size;
        }
        
        virtual int Current()
        {
            return container->arr[nav];
        }
        int operator*()
        {
            return Current();
        }
        //implement below methods, implement end as well
        void operator++()
        {
        }
        void operator++(int)
        {
        }
    };
};

int main()
{
    Container container;
    Container::Iterator it = container.begin();

    cout<<it.Current()<<endl;
    while(it.Next())
    {
        cout<<it.Current()<<endl;
    }
    return 0;
}
