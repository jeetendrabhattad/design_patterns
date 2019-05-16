#include <iostream>
#include <string>

using namespace std;

/*
- normal card
- silver card
- gold card
- platinum card
*/

class CardHolder
{
protected:
    string card_holder_type;
    CardHolder(string type):card_holder_type(type)
    {
    }
public:
    virtual void Facilities() = 0;
};

class NormalCard : public CardHolder
{
public:
    NormalCard() : CardHolder("Normal")
    {

    }
    void Facilities()
    {
        cout<<"You are holding "<<card_holder_type<<endl;
        cout<<"Your Limit is 50000\n";
        cout<<"Swipe at Petrol Pump for 0 Service Charge\n";
        cout<<"Eligible for Instant Loan of 50000\n";
    }
};
class SilverCard : public CardHolder
{
public:
    SilverCard() : CardHolder("Silver")
    {

    }
    void Facilities()
    {
        cout<<"You are holding "<<card_holder_type<<endl;
        cout<<"Your Limit is 150000\n";
        cout<<"Swipe at Petrol Pump for 0 Service Charge\n";
        cout<<"Eligible for Instant Loan of 150000\n";
    }
};

class GoldCard : public CardHolder
{
public:
    GoldCard() : CardHolder("Gold")
    {

    }
    void Facilities()
    {
        cout<<"You are holding "<<card_holder_type<<endl;
        cout<<"Your Limit is 250000\n";
        cout<<"Swipe at Petrol Pump for 5% cashback\n";
        cout<<"Eligible for Instant Loan of 250000\n";
    }
};

class PlatinumCard : public CardHolder
{
public:
    PlatinumCard() : CardHolder("Platinum")
    {

    }
    void Facilities()
    {
        cout<<"You are holding "<<card_holder_type<<endl;
        cout<<"Your Limit is 550000\n";
        cout<<"Swipe at Petrol Pump for 10% cashback\n";
        cout<<"Elligible for Instant Loan of 500000\n";
    }
};
class NullCard : public CardHolder
{
public:
    NullCard() : CardHolder("NULL")
    {

    }
    void Facilities()
    {
    }
};


class CardHolderFactory
{
public:
    static CardHolder* GetCard(int amount)
    {
        if(amount < 50000)
            return new NormalCard();
        else if(amount < 150000)
            return new SilverCard();
        else if(amount < 250000)
            return new GoldCard();
        else if(amount < 550000)
            return new PlatinumCard();
        else 
            return new NullCard();
    }
};
class Account
{
    int amount;
    CardHolder *holder = nullptr;
public:
    void CardStatus()
    {
        if(holder != nullptr)
        {
            delete holder;
            holder = nullptr;
        }
        holder = CardHolderFactory::GetCard(amount);
        holder->Facilities();
    }
    Account(int amount): amount(amount)
    {
        CardStatus();
    }
    void Withdraw(int amount)
    {
        this->amount -= amount;
        CardStatus();
    }
    void Deposit(int amount)
    {
        this->amount += amount;
        CardStatus();
    }
};

int main()
{
    Account acc(40000);
    acc.Deposit(300000);
    acc.Withdraw(100000);
    return 0;
}
