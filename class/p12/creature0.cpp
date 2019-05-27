#include <iostream>

class Creature
{
public:
  Creature(const std::string& name, int water)
    : name(name), water(water), position(0)
  {
  }

private:
  std::string name;
  int water;
  int position;
};

class SandWalker : public Creature
{
public:

private:
};

class C
{
public:
  C() { std::cout << "default" << std::endl; }
  C(const C&) { std::cout << "copy" << std::endl; }
  C& operator=(const C&) {
    std::cout << "op=" << std::endl;
  }
  ~C() { std::cout << "destructor" << std::endl; }
};

class B
{
public:
  B(const C& c) //: c1(c)
  {
    c1 = c;
  }

  C c1;
};

int main()
{
  C c2;
  B b(c2);
  return 0;
}
