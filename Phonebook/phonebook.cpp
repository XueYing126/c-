/*
Create a Person type in which you can store a first name and a family name as
two strings.

Create a Phonebook type. Create an insert() function which expects a person and
a phone number. These information should be stored in the phonebook.

Create a function in the Phonebook class which prints the entries of the
phonebook sorted by the persons' names.

Modify the Phonebook class so multiple phone numbers can be stored for a person.

Create a function which removes the entry from the phone book which belongs to
the given person.


*/

#include <iostream>
#include <map>
#include <vector>
//#include <algorithm>    // std::find
using namespace std;


class Person
{
public:
    Person(string first,string second)
    {
        firstName = first;
        familyName = second;
    }
    friend bool operator<(const Person& p1,const Person& p2) //so important!
    {
        return p1.firstName<p2.firstName;
    }

    friend std::ostream& operator<<(std::ostream &out, const Person &person)
    {
        out << person.firstName << " " << person.familyName;
        return out;
    }
private:
    string firstName;
    string familyName;
};

class Phonebook
{
public:
    void Insert(Person p,int number)
    {

        if ( phonebook.find(p) != phonebook.end())
        {
            phonebook.find(p)->second.push_back(number);
        }
        else
        {
            vector<int> numbers;
            numbers.push_back(number);
            phonebook.insert( pair<Person,vector<int> >(p,numbers) ) ;
        }

    }

    vector<int> Find(Person p)
    {
        if ( phonebook.find(p) != phonebook.end())
        {
            return phonebook.find(p)->second;
        }
        else
        {
            vector<int> numbers;
            numbers.push_back(0);
            return numbers;
        }
    }

    void Remove(Person p)
    {
         if ( phonebook.find(p) != phonebook.end())
        {
            phonebook.erase(phonebook.find(p));
        }
    }
    void print() {  //auto sort?
        for( map<Person, vector<int> >::const_iterator it = phonebook.begin(); it != phonebook.end(); ++it)
        for (unsigned int i=0; i<it->second.size(); i++)
            std::cout << it->first << "'s phone number is " << it->second.at(i) << std::endl;
    }

private:
    map<Person,vector<int> > phonebook;
};
int main()
{
    Person p1("Ying","Xue");
    Phonebook phonebook;
    phonebook.Insert( Person("Ying","Xue"),1234567);
    phonebook.Insert( Person("Apple","Xue"),432123);
    phonebook.Insert( Person("Ying","Xue"),1324567);
    phonebook.Insert( Person("Banana","Xue"),9875543);

    cout<<"get numbers of Ying Xue: "<<endl;
    vector<int> v = phonebook.Find(p1);
    for(int i = 0; i< v.size();++i)
    {
        cout<<v.at(i)<<endl;
    }

    cout<<"Print: "<<endl;
    phonebook.print();
    cout<<endl;

    phonebook.Remove(Person("Ying","Xue"));

    cout<<"Print: "<<endl;
    phonebook.print();
    cout<<endl;

    return 0;
}
