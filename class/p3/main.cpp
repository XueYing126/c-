#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    //----------String operations----//

    cout<<lengh("hello")<<endl; //5
    cout<<position("hello",'e')<<endl; //1

    const char* p = Reverse("hello");
    cout<<p << endl; //"olleh"
    delete[] p; // because it allocated on heap, you need to deallocated it manually

    char a[12] = "Hello World";  //last character is \0
    cout<<lengh(a)<<endl;
    reverse_inline(a);
    cout<<a << endl;


    return 0;
}
