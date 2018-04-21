#include <iostream>
#include <string>

using namespace std;

const string string_map[10] = {"zero","one","two","three","four",
"five","six","seven","eight","nine"};

int main()
{
    string s;
    string result_s;
    unsigned int sum = 0;
    getline(cin,s);
    for(unsigned int i = 0;i < s.size();i++)
    {
        sum += (s[i] - '0');
    }
    result_s = to_string(sum);
    cout<<string_map[result_s[0] - '0'];
    for(unsigned int i = 1;i < result_s.size();i++)
    {
        cout<<" "<<string_map[result_s[i] - '0'];
    }
    return 0;
}