#include <iostream>

using namespace std;


class Matrix
{
    friend  Matrix operator+(const Matrix& ,const Matrix&);
public:
    Matrix(int a, int b)
    {
        row = a;
        col = b;
        matrix =new int[row*col];
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
               matrix[j+i*col] = new int(0);
            }
        }

    }

    Matrix operator=(const Matrix& other)
    {
        if(col!=other.getCol() || row != other.getRow())
        {
            delete [] matrix;
            matrix = new int(other.getCol()*other.getRow());
            col =other.getCol();
            row = other.getRow();
        }

        for(int i=0;i<col*row;i++)
        {
            matrix
        }
    }

    Matrix operator+(Matrix& other)
    {
        if(other.getRow() == this.row &&other.getCol()==this.col)
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    *matrix[j+i*col] = *matrix[j+i*col] +other.at(i,j);
                }
            }
            return *this;
        }
        return this;
    }
    Matrix operator*(Matrix& other)
    {

    }

    int& at(int x,int y)
    {
        return *matrix[x*col+y];
    }

    int getRow()
    {
        return this.row;
    }
    int getCol()
    {
        return this.col;
    }

    ~Matrix()
    {
        delete [] matrix;
    }


    //chocolate question:
    int& at(int i,int j)const {return matrix[i*col+j];}

    /*
    const int& at(int i,int j) const {return matrix[i*col+j];}
*/

private:
    int row;
    int col;

    int* matrix;
};


struct S
{
    int i;

    int * p;
    S(){ p = &i;}
    int * g() const /*this is const, every member became constant*/{return p;}  //why is it working? ----for chocolate

    const int& f() const /*constant method: for 'this'*/ {return i;}  //constant method  //return const value
    int& f(){return i;}  //overload : if you need to change the value.
};

void g(const S& s)
{
    cout<<s.f()<<endl; // error  s.f() return reference so can modify it
}


int main()
{
    S s;
    s.i =42;
   // s.f() = 5; //error: copy value do not have memory address, can not store value
   //if you want assign a value, you need reference return type


   /*

    Matrix m1(10,10);
    Matrix m2(10,10);
    Matrix m3(m1);
    m1 = m2;
    m1 = m2 + m3;
    m1.at(1, 2) = 42;
    cout<<m1.at(1,2)<<endl;

    */
    return 0;
}
