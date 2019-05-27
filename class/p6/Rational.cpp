#include <iostream>

using namespace std;

class Rational
{
    friend  Rational operator*(const Rational&,const Rational&);
public:
    Rational(int n = 4,int d = 2)
    {
        nom = n;
        denom = d;
    }


    Rational operator*(const Rational& other)
    {
        Rational result(nom*other.nom, denom*other.denom);
        return result;
    }

    void print()
    {
        cout<<nom<<"/"<<denom<<" " <<double(*this)<<endl;
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

    r1 = r2; r1.print();
    r1 = 5;  r1.print();
    r5 = r1*r2; r5.print();
    r5 = r1*3.0; r5.print();
    r5 = 3.0*r1; r5.print();






    return 0;
}
