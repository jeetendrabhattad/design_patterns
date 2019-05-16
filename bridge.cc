#include <iostream>

using namespace std;

class IOutput
{
public:
    virtual void Click() = 0;
    virtual void Drag() = 0;
    virtual void DoubleClick() = 0;
    operator IOutput*()
    {
        return this;
    }
};

class Screen : public IOutput
{
public:
    virtual void Click()
    {
        cout<<"Screen Clicked : selected\n";
    }
    virtual void Drag()
    {
        cout<<"Screen Dragged : moved\n";
    }
    virtual void DoubleClick()
    {
        cout<<"Screen Double Clicked : minimized\n";
    }
};

class Audio : public IOutput
{
public:
    virtual void Click()
    {
        cout<<"Audio Clicked : played\n";
    }
    virtual void Drag()
    {
        cout<<"Audio Dragged : seek\n";
    }
    virtual void DoubleClick()
    {
        cout<<"Audio Double Clicked : pause-play\n";
    }
};

class InputDevice
{
protected:
    IOutput * output = nullptr;
public:
    InputDevice& operator=(IOutput *out)
    {
        output = out;
        return *this;
    }
};

class Mouse : public InputDevice
{
public:
    void Click()
    {
        output->Click();
    }
    void Drag()
    {
        output->Drag();
    }
    void DoubleClick()
    {
        output->DoubleClick();
    }
    Mouse& operator=(IOutput *out)
    {
        output = out;
        return *this;
    }
};

class Gestures : public InputDevice
{
public:
    void Tap()
    {
        output->Click();
    }
    void Pinch()
    {
        output->Drag();
    }
    void Pan()
    {
        output->DoubleClick();
    }
    Gestures& operator=(IOutput *out)
    {
        output = out;
        return *this;
    }
};

int main()
{
    Screen scr;
    Audio aud;

    Gestures ges;
    Mouse mouse;

    ges = scr;
    ges.Pan();
    ges.Pinch();
    ges.Tap();

    ges = aud;
    ges.Pan();
    ges.Pinch();
    ges.Tap();

    mouse = scr;
    mouse.Click();
    mouse.Drag();
    mouse.DoubleClick();
    
    mouse = aud;
    mouse.Click();
    mouse.Drag();
    mouse.DoubleClick();
    return 0;
}
