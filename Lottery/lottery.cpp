/*
Lottery
-------
The lottery.txt file contains the lottery results back to 1957. The first line of the file contains a number which gives the number of further lines. Each line contains the numbers of a week in ascending order. The following tasks have to be solved based on this input file:

- Read 5 numbers from the user, all of them should be between 1 and 90. Check if all numbers are from this interval.
- Print these numbers in ascending order.
- Determine based on the input file which number was pulled most times.
- Create a function which requires two vectors of length 5. The function should return how many elements of the two vectors match.
- Based on the input file let's determine how many times the user has 1, 2, 3, 4 or 5 matches if he or she played every week.
- Print the winning numbers of the next week :)

*/

#include <iostream>
#include <vector>
#include <algorithm>    // std::sort,find,count
#include <fstream>

using namespace std;


int match_element(const vector<int> v1,const vector<int> v2)
{
    int cnt = 0;
    for(unsigned int i =0 ; i<5;++i)
    {
        if(v1.at(i) == v2.at(i))
        {
            cnt++;
        }
    }
    return cnt;
}

vector<int> input()
{
    vector<int> nums;
    int num;
    cout << "Give me five numbers!" << endl;
    int i=0;
    while(i<5)
    {
        cout<<i+1<<": ";
        cin>>num;
        if(num<=90&&num>=1)
            nums.push_back(num);
        else
        {
            cout<<"should between 1 and 90"<<endl;
            --i;
        }

        ++i;
    }

    return nums;
}
void sortIt(const vector<int> nums)
{
     vector<int> so(nums.begin(),nums.end());
    sort(so.begin(),so.end());
    cout<<"in ascending order: ";
    for(int i = 0; i< so.size();++i)
        cout<<so.at(i)<<" ";
    cout<<endl;
}
vector<int> readFromFile(int &lines)
{
    ifstream f("lottery.txt");
    vector<int> lotterys;
    int num;
    if(f.is_open())
    {

        f>>lines;
        for(int i=0;i<lines*5;++i)
        {
            f>>num;
            lotterys.push_back(num);
        }
    }else{
        cout<<"Error opening the file"<<endl;
    }
    f.close();

    return lotterys;
}

int MostTime(const vector<int> lotterys,const vector<int> nums)
{
    int Maxi = count(lotterys.begin(),lotterys.end(),nums.at(0));
    int Maxnum = nums.at(0);
    for(int i = 1; i< nums.size();++i)
    {
        int cnt = count(lotterys.begin(),lotterys.end(),nums.at(i));
        if(cnt > Maxi)
        {
            Maxnum = nums.at(i);
            Maxi = cnt;
        }
    }
}
int main()
{
    vector<int> nums = input();

    sortIt(nums);
    //read from file
    int lines;
    vector<int> lotterys = readFromFile(lines);

    //- Determine based on the input file which number was pulled most times.
    int Maxnum = MostTime(lotterys,nums);
    cout<<"Number pulled most times is: "<<Maxnum<<endl;

    //- Create a function which requires two vectors of length 5.
    //The function should return how many elements of the two vectors match.
    int mnum = match_element(lotterys,nums);
    cout<<"match number: "<<mnum<<endl;

    // Based on the input file let's determine how many times the user has 1, 2, 3, 4 or 5 matches
    // if he or she played every week.
   int a[5] = {0,0,0,0,0};

    for(int i = 0; i< lines;++i)
    {
        vector<int> tmp;
        tmp.push_back(lotterys.at(5*i));
        tmp.push_back(lotterys.at(5*i+1));
        tmp.push_back(lotterys.at(5*i+2));
        tmp.push_back(lotterys.at(5*i+3));
        tmp.push_back(lotterys.at(5*i+4));

        int ccnt = match_element(tmp,nums);
        if(ccnt>0)
        a[ccnt-1]++;
        tmp.clear();
    }

    cout<<"here"<<endl;
    for(int i = 0; i<5;++i)
    {
        cout<<a[i]<<" times for "<<i+1<<" matches"<<endl;
    }


    return 0;
}
