/*
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/

#include <iostream>
#include <string>

using namespace std;

int my_map(char a)
{
    if('0'<= a && a <= '9')
    {
        return a - '0';
    }
    else
    {
        return a - 'a' + 10;
    }
}
//求字符串中的最大值 进制不可能小于数值
int my_max(string a)
{
    int len = a.size();
    char max = '0';
    for(int i = 0;i < len;i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    return my_map(max) + 1;
}

long long convert_to_int(string a,long long redx)
{
    int lens = a.size();
    long long base1 = 1;
    long long result = 0;
    for(int i = lens - 1;i >= 0;i--)
    {
        result += (my_map(a[i]) * base1);
        base1 *= redx;
    }
    return result;
}

int main()
{
    string N1,N2;
    long long flag,radix;
    long long n1 = 0;
    long long n2 = 0;//N1 和 N2 的十进制
    cin>>N1>>N2>>flag>>radix;
    int len1 = N1.size();
    int len2 = N2.size();
    long long base = 1;
    /*******根据flag将N1或N2转化成整数********/
    if(flag == 1)
    {
        for(int i = len1 - 1;i >= 0;i--)
        {
            n1 += my_map(N1[i]) * base;
            base *= radix;
        }
        //cout<<n1<<endl;
    }
    else
    {
        for(int i = len2 - 1;i >= 0;i--)
        {
            n2 += my_map(N2[i]) * base;
            base *= radix;
        }
        //cout<<n2<<endl;
    }

    long long result_radix;
    bool is_equal = false;
    if(flag == 1)
    {
        long long left = my_max(N2);
        long long right = n1 + 1;
        long long temp;
        while(left <= right)
        {
            result_radix = (left + right) >> 1;
            temp = convert_to_int(N2,result_radix);
            if(temp == n1)
            {
                is_equal = true;
                break;
            }
            else if(temp > n1 || temp < 0)
            {
                right = result_radix - 1;
                cout<<temp<<" "<<result_radix<<endl;
            }
            else
            {
                left = result_radix + 1;
            }
        }
    }
    else
    {
        long long left = my_max(N1);
        long long right = n2 + 1;
        long long temp;
        while(left <= right)
        {
            result_radix = (left + right) >> 1;
            temp = convert_to_int(N1,result_radix);
            if(temp == n2)
            {
                is_equal = true;
                break;
            }
            else if(temp > n2 || temp < 0)
            {
                right = result_radix - 1;
            }
            else
            {
                left = result_radix + 1;
            }
        }
    }

    if(is_equal)
    {
        cout<<result_radix;
    }
    else
    {
        cout<<"Impossible";
    }
    system("pause");

    return 0;
}