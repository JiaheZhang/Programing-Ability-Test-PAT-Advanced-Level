/*
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/

#include <iostream>
#include <string>

using namespace std;

bool is_prime(int num)
{
    if(num <= 1) return false;
    for(int i = 2;i < num;i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int convert(int num,int radix)//输入十进制的num 输出radix的num
{
    int get_num = 0;
    int re_num[100];
    int len = 0;
    while(num != 0)
    {
        re_num[len++] = num % radix;
        num /= radix;
    }
    for(int i = 0;i < len;i++)
    {
        get_num = get_num * radix + re_num[i];
    }
    return get_num;
}

int main()
{
    int N,D;
    int temp_N;
    while(cin>>N)
    {
        if(N < 0) break;
        cin>>D;
        if(!is_prime(N))
        {
            cout<<"No"<<endl;
            continue;
        }
        temp_N = convert(N,D);
        if(is_prime(temp_N)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    system("pause");
    return 0;
}
