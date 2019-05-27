#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

struct Circle
{
  int x, y, r;

  Circle(int x = 0, int y = 0, int r = 1)
    : x(x), y(y), r(r)
  {
//    std::cout << "default" << std::endl;
  }

  Circle(const Circle& other)
    : x(other.x), y(other.y), r(other.r)
  {
//    std::cout << "copy" << std::endl;
  }

  ~Circle()
  {
//    std::cout << "destructor" << std::endl;
  }
};

bool operator<(const Circle& c1, const Circle& c2)
{
  return c1.r < c2.r;
}

void f(const std::map<std::string, int>& m)
{
  std::cout << m["hello"];
}

int main()
{
  std::map<std::string, int> m;

  m["hello"] = 42;
  m["xyz"] = 5;
  m["xyz"] = 6;
  m["abc"] = 0;

  f(m);

  return 0;
}
