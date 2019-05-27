#include <iostream>

struct Circle
{
  int x, y;
  int r;

  Circle(int x, int y, int r) : x(x), y(y), r(r) {}
};

bool operator<(const Circle& c1, const Circle& c2)
{
  return c1.r < c2.r;
}

template <typename T>
const T& bigger(const T& a, const T& b)
{
  return a < b ? b : a;
}

struct S
{
  static int counter;
  S() { ++counter; }
  S(const S&) { ++counter; }
  ~S() { --counter; }
};

int S::counter = 0;

struct A
{
  struct B
  {

  };
};
/*
template <typename T>
class vector
{
public:
  vector(int n) : arr(new T[n]), size(n)
  {
  }

  vector(const vector<T>& other)
    : arr(new T[other.size]), size(other.size)
  {
    for (int i = 0; i < size; ++i)
      arr[i] = other.arr[i];
  }

  ~vector()
  {
    delete[] arr;
  }

private:
  T* arr;
  int size;
};

template <>
class vector<bool>
{
  
}
*/


template <typename T>
struct MyClass
{
  static int i;
};

template <>
struct MyClass<int>
{
  struct i
  {
  };
};

template <typename T>
void f()
{
  typename MyClass<T>::i * x;
}

int main()
{
  f<double>();
  MyClass<double>::i;
  return 0;
}
