#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
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

template <typename Cont>
void print(const Cont& cont)
{
  for (typename Cont::const_iterator i = cont.begin();
       i != cont.end(); ++i)
    std::cout << *i << std::endl;
}

template <typename It1, typename It2>
void copy(It1 from, It1 to, It2 here)
{
  while (from != to)
  {
    *here = *from;
    ++from;
    ++here;
  }
}

bool containsX(const std::string& word)
{
  for (int i = 0; i < word.size(); ++i)
    if (word[i] == 'x' || word[i] == 'X')
      return true;

  return false;
}

struct contains
{
  char c;
  contains(char c) : c(c) {}
  bool operator()(const std::string& word )
  {
    for (int i = 0; i < word.size(); ++i)
      if (word[i] == c)
        return true;

    return false;
  }
};

int main()
{
  std::ifstream f("main.cpp");

  std::set<std::string> words(
    (std::istream_iterator<std::string>(f)),
    (std::istream_iterator<std::string>()));

  f.close();

  std::vector<std::string> v;

  std::copy(
    words.begin(), words.end(),
    std::back_inserter(v));

  std::sort(v.rbegin(), v.rend());

  std::vector<std::string>::iterator it
    = std::find(v.begin(), v.end(), "#include");

  if (it == v.end())
    std::cout
      << "There is no #include in the file"
      << std::endl;
  else
    std::cout
      << "There is #include in the file : "<<*it <<" " <<*it
      << std::endl;

  std::find_if(v.begin(), v.end(), contains('x'));
  std::find_if(v.begin(), v.end(), containsX);

  return 0;
}
