#include "header.h"

int lengh(const char c[]){
    int counter = 0;
    for(counter =0 ; c[counter] != '\0' ; ++counter);
                // equal *(c+counter) != '\0'
    return counter;
}
int position(const char c[], char b){
    int pos =0;
    for (pos=0;c[pos]!='\n';pos++){
        if(c[pos] ==b){
            return pos;
        }
    }
    return -1;
}
char*  Reverse(const char c[]){  //return pointer is dangerous, may got garbage value
    int len = lengh(c);
    //const char result[len]
    /*
    ----this is local variable will allocate on the stack,
     when the function returned .
     it will deallocated automatically.
     */
    char* result = new  char[len+1]; //now it is allocate on heap. you can access it after the function
    result[len]='\0';
    for(int i = 0; i < len; ++i){
        result[len-i-1] = c[i];
    }
    return result;
}
void my_swap(char &a, char &b){
     char c = a;
     a = b ;
     b = c;
}

void reverse_inline(char c[]){
    int len = lengh(c);
    /*
    for(int i = 0; i < len/2; ++i){
        char t = c[i];
        c[i] = c[len-i-1];
        result[len-i-1] = t;
    }*/

    for(int i = 0; i < len/2; ++i){
        my_swap(c[i] , c[len-i-1]);
    }
}
