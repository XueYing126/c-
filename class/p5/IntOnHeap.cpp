#include <iostream>

using namespace std;

class IntOnHeap
{

    int* p;
  public:

      int get()
      {
          return *p;
      }

      void set(int new_val){

         *p = new_val;
      }

    //default constructor , can be called by no parameter
    IntOnHeap(int n = 0)
    {
        cout<<"This is default constructor."<<endl;  //because it can be called without parameter
        p = new int(n); //allocated on the heap
    }
    IntOnHeap(const IntOnHeap& other)
    {
       // p = other.p; //copy constructor;. point to the same place on heap;
       cout<<"This is copy constructor."<<endl;
       p =  new int(*other.p); //create new object, do not assign to same object
    }

    IntOnHeap& operator=(const IntOnHeap& other)
    {
        cout<<"Assignment: ."<<endl;
        *p = *other.p;
        return *this;
    }

    ~IntOnHeap()
    {
        cout<<"This is destructor."<<endl;
        delete p;
    }
};

IntOnHeap * factory()
{
    IntOnHeap *x = new IntOnHeap(42);  //create on heap
    return x;
}

void consumer (IntOnHeap y)  //copy constructor , at end of this function destructor
{

}

IntOnHeap factory2()
{
    IntOnHeap x;  //temporary . local object on stack
    return x;  //return by value: RVO
//more efficient than factory....
}
int main()
{
    /*
    IntOnHeap* p = factory();
    consumer(*p);
    delete p;
*/

    IntOnHeap a = factory2();

    /*
    IntOnHeap x(3);
    IntOnHeap y;
    //IntOnHeap z(); //this is a function

    //y.p = 0;  //0 is the only int can be assign to pointer

    if(true)
    {
        IntOnHeap w(x);
    }
    IntOnHeap z;
    z = x; //assignment
    //but we only want same value


    //RAII
    //rule of 3: if we have resource, I will need a copy constructor, and operator, and destructor
*/



   //task? linked list ? binary tree ?



    return 0;
}
