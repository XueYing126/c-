#include <iostream>

using namespace std;

int sum(int* arr,int n){
    int s = 0;

    for(int i = 0;i<n;i++){
        s += arr[i];
    }
    return s;
}

int main()
{

    int arr1[6]={1,2,3,4,5,6};

    cout <<sum(arr1,6) << endl;


    //an exception:
    char c[6]="hello";
    char* p =c;
    cout<<c<<endl;
    cout<<p+2<<endl;
    cout<<*p<<endl;
    cout<<*p+2<<endl;
cout<<*(p+2)<<endl;


    int i = 42;
    int* t = &i;
    int x[4];
    t=x;
    cout<<t<<endl;
    cout<<x<<endl; //array can be convert to pointer.


    return 0;
}
