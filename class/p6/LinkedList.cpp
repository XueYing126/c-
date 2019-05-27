#include <iostream>

using namespace std;

class List
{
    struct Element
    {
        Element(int value,Element* next = 0,Element* prev = 0) :value(value),next(next),prev(prev)
        {

        }
        int value;
        Element* next;
        Element* prev;
    };

public:
    List()
    {
        first =0;
        last = 0;
        size = 0;

    }
    List(const List& other)
    {
        for(Element* n = other.first;n!=0;n = n->next)
        {
            push(n->value);
        }
    }
    ~List()
    {
        while(!empty())
            remove(0);
    }

    List& operator=(const List& other) //assignment operator
    {
        for(Element* n = other.first;n!=0;n = n->next)

            push(n->value);

        return *this;
    }

    bool empty()
    {
        return first == 0;
    }

    void push(int val)
    {
        Element* n = new Element(val);
       //!!! n->value = val; // or (n*).value = val
       n->prev = last;
       if(empty())
       {
           first = n;
       }
       else
       last->next = n;

       last = n;
       //!consider insertion to empty list
       size++;
    }

    int length()
    {
        return size;
    }

    void remove (int pos)
    {
       Element* n =elementAt(pos);

       Element* next = n->next;
       Element* prev = n->prev;

       if(next!=0)
        next->prev = prev;
       if(prev!=0)
        prev->next = next;
       if (n==last)
       last = prev;
       if(n==first)
        first = next;

       delete n;
       --size;
    }

    int getElement(int pos)
    {
        Element* n = first;
        for(int i =0 ; i< pos; i++)
         n = n->next;

        return n->value;

    }


private:
    Element* elementAt(int pos)
    {
        Element* n = first;
        for(int i =0 ; i< pos; i++)
         n = n->next;

        return n;
    }


    Element* first;
    Element* last;
    int size;
};


int main()
{
    List l;

    l.push(1);
    l.push(2);
    l.push(3);

    for(int i = 0 ; i< l.length();i++)
    {
        cout<<l.getElement(i)<<endl;
    }

    return 0;
}
