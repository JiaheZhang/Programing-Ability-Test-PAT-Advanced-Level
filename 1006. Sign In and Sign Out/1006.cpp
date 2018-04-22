/*
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct person
{
    string name;
    string start_time;
    string end_time;
};

bool  cmp_start(person a, person b)
{
    return a.start_time < b.start_time;
}
bool cmp_end(person a, person b)
{
    return a.end_time > b.end_time;
}

int main()
{
    int M;//m lines input
    vector<person> v;
    scanf("%d",&M);
    for(int i = 0;i < M; i++)
    {
        string a,b,c;
        cin>>a>>b>>c;
        person p;
        p.name = a;
        p.start_time = b;
        p.end_time = c;
        v.push_back(p);
    }
    sort(v.begin(),v.end(),cmp_start);
    cout<<v[0].name<<" ";
    sort(v.begin(),v.end(),cmp_end);
    cout<<v[0].name;
    return 0;
}