#include <iostream>

using namespace std;

class Rational
{
    friend  Rational operator*(const Rational&,const Rational&);
public:
    Rational(int n = 0,int d = 1)
    {
        nom = n;
        denom = d;
    }

    /*
    Rational operator*(const Rational& other)
    {
        Rational result(nom*other.nom, denom*other.denom);
        return result;
    }
*/
    void print()
    {
        cout<<nom<<"/"<<denom<<endl;
    }

    Rational& operator=(const Rational & other) //r1=r2=r3
    {
        nom = other.nom;
        denom = other.denom;
        return *this;
    }

    operator double()
    {
        return (double)nom / denom;
    }
private:
    int nom;
    int denom;
};

 Rational operator*(const Rational& left,const Rational& right)
    {
        Rational result(left.nom*right.nom, left.denom*right.denom);
        return result;
    }


int main()
{
    Rational r1;
    r1.print();
    Rational r2(r1);
    r2.print();
    Rational r3 = r1;
    r3.print();
    Rational r4(1,2);
    r4.print();
    Rational r5(3);  //constructor call
    r5.print();
    Rational r6 = 42; //also constructor
    r6.print();

    r1 = r2; r1.print(); //assignment
    r1 = 5;  r1.print();  //implicit convert. a constructor receive one integer
    r1 = Rational(5); //the same with up
    r5 = r1*r2; r5.print(); //same with operator*(r1,r2)
    //r5 = r1*3; r5.print(); //it van convert integer to rational or convert rational to double. You need say it explicitly
     r5 = double(r1)*3;
    r5 =Rational(3)*r1; r5.print();



    //compiler generate: assignment,copy constructor,destructor




    return 0;
}
