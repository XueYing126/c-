#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class A
{
public:
    A(){}
  virtual void f(int i = 1)
  {
    std::cout << "A" << i << std::endl;
  }
};

class B : public A
{
public:
    B(){}
  void f(int i = 2)
  {
    std::cout << "B" << i << std::endl;
  }
};

int main()
{

   A a; a.f(); //A 1
   B b; b.f(); //B 2

   A* t = &b;  t->f(); //B 1
   A* c = new B;  c->f(); //B 1

    return 0;
}
