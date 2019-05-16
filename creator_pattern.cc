#include <iostream>
#include <map>
using namespace std;

class ISort
{
public:
    virtual void DoSort() = 0;
};

class BubbleSort : public ISort
{
public:
    void DoSort()
    {
        cout<<"Bubble Sort\n";
    }
};

class InsertionSort : public ISort
{
public:
    void DoSort()
    {
        cout<<"Insertion Sort\n";
    }
};

class QuickSort : public ISort
{
public:
    void DoSort()
    {
        cout<<"Quick Sort\n";
    }
};

class HeapSort : public ISort
{
public:
    void DoSort()
    {
        cout<<"Heap Sort\n";
    }
};

class NullSort : public ISort
{
public:
    void DoSort(){}
};
class Array
{
    ISort *srt = nullptr;
public:

    void CreateSort(int par)
    {
        //instead of if-else use MAP
        if(10 == par)
            srt = new BubbleSort();
        else if(20 == par)
            srt = new InsertionSort();
        else if(30 == par)
            srt = new HeapSort();
        else
            srt = new NullSort();
    }
    void Sort()
    {
        srt->DoSort();
    }
};
int main()
{
    Array arr;
    arr.CreateSort(10);
    arr.Sort();
    return 0;
}

//Creator is similar to Factory with the differnce that creator uses the object created for itself.
//the stitching is achieved through Creator (stitching here is Strategy)
