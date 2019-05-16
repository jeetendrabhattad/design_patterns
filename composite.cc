#include <iostream>
#include <vector>

using namespace std;

class IShow
{
public:
    virtual void Show() = 0;
};
class Player : public IShow
{
    string name;
public:
    Player(string nm) : name(nm) 
    {}
    void Show()
    {
        cout<<"\t\t\t\t\t"<<name<<endl;
    }
};

class PlayersList : public vector<Player*>
{
public:
    PlayersList()
    {

    }
};

class Team : public IShow
{
    PlayersList player_vector;
    string name;
public:
    Team(string nm) : name(nm)
    {
    }
    void Show()
    {
        cout<<"\t\t\t\t"<<name<<endl;
        auto it = player_vector.begin();
        auto end = player_vector.end();
        while(it != end)
        {
            (*it)->Show();
            it++;
        }
    }
    void AddPlayer(string plname)
    {
        player_vector.push_back(new Player(plname));
    }
};

class TeamList : public vector<Team*>
{
public:
    TeamList()
    {}
};

class Division : public IShow
{
    TeamList teamList;
    string name;
public:
    Division(string name) : name(name)
    {}
    void Show()
    {
        cout<<"\t\t"<<name<<endl;
        auto it = teamList.begin();
        auto end = teamList.end();
        while(it != end)
        {
            (*it)->Show();
            it++;
        }
    }
    void AddTeam(string team_name)
    {
        teamList.push_back(new Team(team_name));
    }
    Team& operator[](int index)
    {
       return *teamList[index];
    }
};

class DivisionList : vector<Division*>
{
public:
    void AddDivision( string name)
    {
        push_back(new Division(name));
    }
    void Show() 
    {
        cout<<"\t\t"<<endl;
        auto it = begin();
        auto en = end();
        while(it != en)
        {
            (*it)->Show();
            it++;
        }
    }
    Division& operator[](int index)
    {
        return *at(index);
    }
};

int main()
{
    DivisionList divList;
    divList.AddDivision("Alpha");
    divList.AddDivision("Gamma");

    Division& d1 = divList[0];
    d1.AddTeam("RCB");
    d1.AddTeam("KKR");

    Team& t1 = d1[0];
    t1.AddPlayer("Virat");
    t1.AddPlayer("ABD");

    Team& t2 = d1[1];
    t2.AddPlayer("Karthik");
    t2.AddPlayer("Robin");
    divList.Show();
    return 0;
}
//code should be corrected to make use of map instead of vector
