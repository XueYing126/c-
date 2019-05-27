#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Creature
{
public:
    Creature(string n,int w):
    name(n),water(w),position(0){}

    virtual void step(char day) =0;

int getPosition()
{
    return position;
}
string getName()
{
    return name;
}
bool isAlive()
{
    return water>=0;
}
void print()
{
    cout<<"name: "<<name<<" water: "<<water<<" position: "<<position<<endl;
}

protected:
    string name;
    int water;
    int position;
};

class Sandwalker: public Creature
{
public:
    Sandwalker(string n,int w):Creature(n,w){}

    void step(char day)
    {
        if(isAlive()){
        switch(day)
            {
                    case 's':
                        water -= 1;
                        position += 3;
                        break;
                    case 'c':
                        water += 0;
                        position += 1;
                        break;
                    case 'r':
                        water += 3;
                        position += 0;
                        break;
            }
        }
        water = min(8,water);
    }

};
class Wanderer: public Creature
{
public:
    Wanderer(string n,int w):Creature(n,w){}

    void step(char day)
    {
        if(isAlive()){
        switch(day)
            {
                    case 's':
                        water -= 2;
                        position += 1;
                        break;
                    case 'c':
                        water -= 1;
                        position += 2;
                        break;
                    case 'r':
                        water += 3;
                        position += 1;
                        break;
            }
        }
        water = min(12,water);
    }

};
class Sponge: public Creature
{
public:
    Sponge(string n,int w):Creature(n,w){}

    void step(char day)
    {
        if(isAlive()){
        switch(day)
            {
                    case 's':
                        water -= 4;
                        position += 0;
                        break;
                    case 'c':
                        water -= 1;
                        position += 1;
                        break;
                    case 'r':
                        water += 6;
                        position += 3;
                        break;
            }
        }
        water = min(20,water);
    }

};

void Step(string days,vector<Creature*> &competitors)
{
    for(int i = 0;i<days.length();++i)
    {
     cout<<i+1<<"th day : "<<endl;
        for(int j = 0;j<competitors.size();++j)
           {
              competitors.at(j)->step(days[i]);
              competitors.at(j)->print();
           }
    }
}

Creature* compete(vector<Creature*> &creatures)
{
    Creature* furthermost = new Sandwalker("no one",0);
    for(int i = 0 ; i < creatures.size();++i)
    {

        if(creatures.at(i)->getPosition() > furthermost->getPosition() && creatures.at(i)->isAlive())
        {
            furthermost = creatures.at(i);
        }
    }
        return furthermost;
}

vector<Creature*> ReadFromFile(string &days)
{
    int num,water;
    string name,type;

    ifstream f("creatures.txt");
    vector<Creature*> competitors;
    if(f.is_open()){
    f>>num;
    for(int i = 0; i < num ; ++i )
    {
        f>>name>>type>>water;

        if (type == "sandwalker")
                competitors.push_back(new Sandwalker(name,water));
        if (type == "wanderer")
               competitors.push_back(new Wanderer(name,water));
        if (type == "sponge")
               competitors.push_back(new Sponge(name,water));

        cout<<name<<" " <<type<< " "<<water<<endl;
    }

    f>>days;
    }
    else
    {
        cout<<"error opening the file"<<endl;
    }
    f.close();
    return competitors;
}

int main()
{
    string days;
    vector<Creature*> competitors = ReadFromFile(days);
    cout<<days<<endl;

    Step(days,competitors);

    cout<<"Winner is:  ";
    compete(competitors)->print();
    return 0;
}
