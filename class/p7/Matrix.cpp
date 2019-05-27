#include <iostream>

using namespace std;

class Matrix
{
public:
    Matrix(int a, int b)
    {
        row = a;
        col = b;
        matrix =new int[row*col];
    }

    Matrix& operator=(const Matrix& other)
    {
        if(col!=other.col || row != other.row)
        {
            delete [] matrix;
            matrix = new int(other.col*other.row);
            col =other.col;
            row = other.row;
        }

        for(int i=0;i<col*row;i++)
        {
            matrix[i] = other.matrix[i];
        }
        return *this;
    }

    Matrix& operator+(const Matrix& other)
    {
        if(other.row == this->row &&other.col==this->col)
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    matrix[j+i*col] = matrix[j+i*col] + other.matrix[j+i*col];
                }
            }
        }
        return *this;
    }
    Matrix operator*(Matrix& other)
    {

    }

    int& at(int x,int y)
    {
        return matrix[x*col+y];
    }
    int& at(int x)
    {
        return matrix[x];
    }

    int getRow()
    {
        return this->row;
    }
    int getCol()
    {
        return this->col;
    }

    ~Matrix()
    {
        delete [] matrix;
    }
private:
    int row;
    int col;

    int* matrix;
};


int main()
{
    Matrix m1(10,10);
    Matrix m2(10,10);
    Matrix m3(m1);
    m1 = m2;
    m1 = m2 + m3;
    m1.at(1, 2) = 42;
    cout<<m1.at(1,2)<<endl;
    return 0;
}
