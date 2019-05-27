#include <iostream>
#include <math.h>
using namespace std;

void f(int* arr){  //runtime efficiency
    cout<<arr<<endl;
    cout<<"sizeof(arr)"<<sizeof(arr)<<endl;//4

}
void g(int arr[]){  //runtime efficiency
    cout<<arr<<endl;
    cout<<"sizeof(arr)"<<sizeof(arr)<<endl;   //4
}

int fib(int num){
    if (num == 0 || num == 1){return 1;}
    if (num > 1){
    return (fib(num -1)+fib(num - 2));}

}
int fib2(int num){
    int a = 0;
    int b = 0;
    int c = 1;
    for(int i =0;i<num;i++){
        a = b;
        b = c;
        c= a + b;
    }
    return c;
}
int collatz(int num){
    int times = 1;

    while (num!=1){
        if (num % 2 == 1){
        num = num*3 + 1;
        }else{
            num = num/2;
        }
        times++;
    }
    return times;
}

//return the pointer of array
//double* solve(double a, double b, double c){}

void solve(double a, double b, double c, double* x1, double* x2){
    double d = b*b - 4*a*c;
    *x1 = ( -b + sqrt(d))/(2*a); //dereference  this * is different with double* x1
    *x2 = ( -b - sqrt(d))/(2*a);


}


int main()
{



    int a[10];
    a[0]=1;
    a[2]=222;
    int* p = a; //conversion to the address first element in the array
    cout<<p<<endl; //get address
    cout<<p+1<<endl; //difference is 4 bytes
    cout<<*p<<endl;  //dereferencing
    cout<<*(p+2)<<endl;  //dereferencing

    cout<<endl;
    const char s[6] = "hello";   //const???
    const char*q = s;
    const char*qq = "hello";

    cout<<"s: "<<s<<endl; //s: hello
    cout<<"*q: "<<*q<<endl;  //*q: h
    cout<<"q: "<<q<<endl;  //q: hello
    /*Why we get the entire char array ?
    Because the creator of cout decided so.
     to print a char* as a string.
      If you want to print a pointer address,
      do a << static_cast<void*>(p1) ...
    */
    cout<<q+1<<endl;//print until /0  //ello
    cout<<*(q+1)<<endl;  //e

    cout<<endl;
    cout<<"*qq: "<<*qq<<endl;//0
    cout<<"qq: "<<qq<<endl;
    cout<<qq+1<<endl;//print until /0
    cout<<*(qq+1)<<endl;

    cout<<endl;
    const char s2[7] = "hello2";   //const???
    q = s2;   //the pointer itself can be modified, but the variable it pointed to can not.
    cout<<q<<endl;  //hello2


    //int* const p2 = s2;  //in this way pointer can ? be changed.

    cout<<endl;

    int t[10] = {1,2,3,4,56,7,8,9,10};
    cout<<"sizeof(t)"<<sizeof(t)<<endl;  //40
    f(t);
    g(t);
    cout<<endl;


    cout<<"here: "<<endl;
    cout<<"hello"+42<<endl;  // !!!!!!!!!
    cout<<string("hello"+42)<<endl;
    cout<<"end here"<<endl;

    //first 10 fibonacci numbers //
    cout<<"first 10 fibonacci numbers"<<endl;
    for(int i =0;i < 10; ++i){
        cout<<fib2(i)<<endl;
    }

     cout<<"first 10 fibonacci numbers"<<endl;
    for(int i =0;i < 10; ++i){
        cout<<fib(i)<<endl;
    }
    cout<<endl;

    // -- Collatz ---//
    /*
    3..10..5...16...8...4...2...1
    */
    cout<<collatz(3)<<endl;
    if (collatz(3) == 8){
        cout<<"Collatz works fine too."<<endl;
    }

    cout<<endl;
    //Quadratic
    //double* solutions = solve( 1, -1, 6); //3, -2
    double x1,x2;
    solve( 1, -1, -6, &x1, &x2);
    cout<<x1<<endl;
    cout<<x2<<endl;

    cout<<endl;

    //reference
    int i =42;
    int &r = i; //i and r reference to same place
    //&..is not address of in this place. but means reference to same place


    return 0;
}
