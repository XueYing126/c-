#include <iostream>

using namespace std;


//it work because 'const': there is no assignment
//pass by reference need memory location
const int& max(const int&a,const int & b){ //should not return pointer of temporary
    return a<b?b:a;
}
int main()
{
    const int& x = max(3,4);  //3 do not have an "memory address", should not refer by reference
    //temporary object will be created as this function runs.
    //it will be undefined behavior, very dangerous

    cout<<x<<endl;

    int i = 42;
    // 43 = 42; it do not have memory location
    int&r = i;
    //which not good: int& r = 5;


    cout << "Hello world!" << endl;
    return 0;
}
