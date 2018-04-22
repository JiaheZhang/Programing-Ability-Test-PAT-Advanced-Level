/*
People on Mars count their numbers with base 13:

Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (< 100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.

Output Specification:

For each number, print in a line the corresponding number in the other language.

Sample Input:
4
29
5
elo nov
tam
Sample Output:
hel mar
may
115
13
*/



#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

string digit_map[13] = {"tret","jan", "feb", "mar", "apr", 
"may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string digit_map_high[12] = {"tam", "hel", "maa", "huh", 
"tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void earth_to_mars(string str)
{
    int num = atoi(str.c_str());
    int fir;
    int sec;
    fir = num / 13;
    sec = num % 13;
    if(fir != 0) 
    {
        cout<<digit_map_high[fir - 1];
        if(sec == 0)
        {
            cout<<endl;
            return;
        }
        else
        cout<<" ";
    }
    cout<<digit_map[sec]<<endl;
}
void mars_to_earth(string str)
{
    int len = str.size();
    if(len <= 4)
    {
        for(int i = 0;i < 13;i++)
        {
            if(str == digit_map[i])
            {
                cout<<i<<endl;
                break;
            }
            if(str == digit_map_high[i])
            {
                cout<<(i + 1) * 13<<endl;
                break;
            }
        }
    }
    else
    {
        string fir,sec;
        int sum = 0;
        fir = str.substr(0,3);
        sec = str.substr(4,len - 4);
        for(int i = 0;i < 12;i++)
        {
            if(fir == digit_map_high[i])
            {
                sum += ((i + 1) * 13);
                break;
            }
        }
        for(int i = 0;i < 13;i++)
        {
            if(sec == digit_map[i])
            {
                sum += i;
                break;
            }
        }
        cout<<sum<<endl;
    }
}

int main()
{
    int N;//N lines input
    scanf("%d",&N);
    getchar();
    for(int i = 0; i < N;i++)
    {
        string str;
        getline(cin,str);
        if(isdigit(str[0]))
        {
            earth_to_mars(str);
        }
        else
        {
            mars_to_earth(str);
        }
    }

    system("pause");
    return 0;
}