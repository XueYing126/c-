#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
#include <cstdlib>
#include <math.h>
class Date
{
public:
    Date(int a,int b,int c):year(a),month(b),day(c)
    {
        const int day_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        if (( 0 > year ) ||( month < 1 || month > 12 )||( day < 1 || day > day_in_month[month-1] ))
        cerr << "not valid date." << endl;
    }

    friend bool operator<(const Date& d1, const Date& d2)
    {
        if (d1.year<d2.year) return true;
        if (d1.year>d2.year) return false;
        if (d1.month<d2.month) return true;
        if (d1.month>d2.month) return false;
        return (d1.day<d2.day);
    }

    friend std::ostream& operator<<(std::ostream &out, const Date &d)
    {
        out <<d.year<<"/"<<d.month<<"/"<<d.day<<endl;
        return out;
    }

    void print()
    {
        cout<<this->year<<"/"<<this->month<<"/"<<this->day<<endl;
    }


    virtual Date& next()
    {
        const int day_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
         ++day;

    if ( day-1 == day_in_month[month-1])
    {
        day = 1;
        ++month;
    }
    if ( 13 == month )
    {
        month = 1;
        ++year;
    }
    return *this; // return reference to *this object

    }


protected:
    int year;
    int month;
    int day;
};

class Workday :public Date
{
public:
    Workday(int a,int b,int c):Date(a,b,c)
    {

    }
    Workday& next()
    {
          const int day_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    do{
		++day;

		if ( day-1 == day_in_month[month-1])
		{
			day = 1;
			++month;
		}
		if ( 13 == month )
		{
			month = 1;
			++year;
		}
	 }
    while(!work());

		return *this;
    }

    bool work()
    {
        //2019,1,1  Thu
        const int day_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int num=365*year;
        for(int i = 0;i<month-1;++i)
        {
            num += day_in_month[i];
        }
        num+=day;

        return num % 7 !=1 && num % 7!=2;
    }
};


class Calendar
{
public:
    Calendar(){}

    void printEvent(Date d)
    {
        if(cal.find(d)!=cal.end())
        {
            for(int i = 0; i<cal.at(d).size();++i)
            {
                cout<<cal.at(d).at(i)<<endl;
            }
        }

    }
    void insert_cal(string s,Date d)
    {
        if(cal.find(d)==cal.end())
        {
            vector<string> v;
            v.push_back(s);
            cal.insert ( pair<Date,vector<string> >(d,v) );
        }
        else
        {
            cal.find(d)->second.push_back(s);
        }
    }

    vector<string> getEvents(Date d)
    {
        string events = "on this day: ";
        if(cal.find(d)!=cal.end())
        {
            return cal.at(d);
        }
        else
        {
            string s = "nothing on this day.";
            vector<string> v;
            v.push_back(s);
            return v;
        }

    }

    void ordered()
    {
        map <Date,vector<string> > cal2(cal.begin(),cal.end());
        while(!cal2.empty()){
            map<Date,vector<string> >::iterator earlist = cal2.begin();
            for (map<Date,vector<string> >::iterator  it=cal2.begin(); it!=cal2.end(); ++it)
            {
               if(it->first < earlist->first)
                earlist = it;
            }

            //cout<<earlist->first;
            printEvent(earlist->first);
            cal2.erase(earlist);
        }
    }
private:
    map <Date,vector<string> > cal;

};

int main()
{
    Calendar calen;

    calen.insert_cal("5.31 event",Date(2019,5,31));
    calen.insert_cal("8.15 event 1",Date(2019,8,15));
    calen.insert_cal("6.1 event ",Date(2019,6,1));
    calen.insert_cal("3.31 event 1",Date(2019,3,31));
    calen.insert_cal("3.31 event 2",Date(2019,3,31));
    calen.insert_cal("2.23 event",Date(2019,2,23));
    calen.insert_cal("8.15 event 2",Date(2019,8,15));

    vector<string> v = calen.getEvents(Date(2019,8,15));
    cout<<"on this date: "<<endl;
    for(int i = 0;i<v.size();++i)
    {
        cout<<v.at(i)<<endl;
    }
    cout<<endl;


    cout<<"Orders: "<<endl;
    calen.ordered();
    cout<<endl;


    cout<<Date(2019,5,31) <<"the next day of it: " <<Date(2019,5,31).next();
    cout<<Workday(2019,5,24) <<"the next day of it: " <<Workday(2019,5,24).next();

    return 0;
}
