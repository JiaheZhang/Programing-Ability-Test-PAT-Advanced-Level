/*
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    pair<int,float> p;
    vector<pair<int,float> > v1,v2;
    vector<float> result(1000000);
    int len1;
    int len2;
    int temp_exp;
    float temp_coef;
    scanf("%d",&len1);
    for(int i = 0;i < len1;i++)
    {
        scanf("%d%f",&p.first,&p.second);
        v1.push_back(p);
    }
    scanf("%d",&len2);
    for(int i = 0; i < len2;i++)
    {
        scanf("%d%f",&p.first,&p.second);
        v2.push_back(p);
    }
    for(int i = 0;i < len1;i++)
    {
        for(int j = 0;j < len2;j++)
        {
            temp_exp = v1[i].first + v2[j].first;
            temp_coef = v1[i].second * v2[j].second;
            result[temp_exp] +=  temp_coef;
        }
    }
    int len_result = 0;
    for(int i = 0;i < 1000000;i++)
    {
        if(result[i] != 0)
        {
            len_result++;
        }
    }
    cout<<len_result;
    for(int i = 1000000 - 1;i >= 0;i--)
    {
        if(result[i] != 0)
        {
            printf(" %d %.1f",i,result[i]);
        }
    }
    system("pause");
    return 0;
}