#include <iostream>
#include <fstream>
using namespace std;
void f(const int & x){

}


class Shape{
protected:
    double x;
    double y;
public:
     void Move( double new_x, double new_y){
    x = new_x;
    y = new_y;
}


    virtual double area(){  //virtual decide in runtime, dynamic type
        //in java , every function default to be virtual
    return 0;
    }

};

class Circle :public Shape{
private:
    double r;
public:


void Resize(double new_r){
    this->r = new_r;

}
double area(){
    return 3.14*(*this).r*this->r;
}

};

class Square :public Shape{
private:
    double l;
public:
    void Resize(double new_r){
    this->l = new_r;
    }

    double area(){
    return l*l;
    }
};


//create text file
int main()
{
   const int i = 42;  //about const
   //int* p = &i; //not compile
   f(i); //pass by reference

   f(42); //it will create temperary object. only exist as this function call

   //----------------------------------------------------------------------
    Circle c1;

    c1.Move(1,1);
    c1.Resize(42);
    cout<<c1.area()<<endl;

    //-------------------------------------


    Shape shapes[10];
    Circle c2;
    Shape ss;
    ss=c2;
    ss.area();


    //-------------------------
    ifstream file("shapes.txt");

    char type;
    double x,y,z;

    Circle c;
    Square s;
    double sum = 0;

 while(file>>type>>x>>y>>z){
  switch (type){
    case 'c':
        c.Move(x,y);
        c.Resize(z);
        sum += c.area();
        break;
        case 's':
            s.Move(x,y);
            s.Resize(z);
            sum += s.area();
            break;
        }
        }
    cout<<sum;
    file.close();


    return 0;
}


ifstream file("creatures.txt");
    int num,water;
    string name,type;
    vector<Creature> creatures;
    file>>num;
    for(int i = 0; i < num ; ++i )
    {
        file>>name>>type>>water;
        Creature c(name,type,water);
        creatures.push_back(c)
        cout<<name<<" " <<type<< " "<<water<<endl;
        
    }
	
	switch(type)
        {
            case 'sandwalker': 
                
                break;
            case 'wanderer': 
                
                break;
            case 'sponge': 
                
                break;
        }