#include <iostream>

using namespace std;

struct Circle
{
    int x,y;
    int r;

    Circle(int x, int y,int r):x(x),y(y),r(r){}
};

bool operator<(const Circle& a,const Circle& b)
{
    return a.r<b.r;
}
template <typename T>
const T& bigger(const T& a,const T& b)
{
    return a<b?b:a;
}


int main()
{
   Circle c1(0,0,1),c2(0,0,2);

   bigger<Circle>(c1,c2);
    cout<<bigger<Circle>(c1,c2)<<endl;
    return 0;
}
