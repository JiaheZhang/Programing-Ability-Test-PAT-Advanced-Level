/*
1007. Maximum Subsequence Sum (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int K;
    scanf("%d",&K);
    vector<int> num(K);
    int sum = 0;
    int max_sum = -1;
    int left_index = 0;
    int right_index = K - 1;
    int temp_index = 0;
    for(int i = 0; i < K;i++)//K lines input
    {
        scanf("%d",&num[i]);
        sum += num[i];
        if(sum < 0)
        {
            sum = 0;
            temp_index = i + 1;
        }
        else if(sum > max_sum)
        {
            max_sum = sum;
            left_index = temp_index;
            right_index = i;
        }
    }
    if(max_sum < 0)
    {
        max_sum = 0;
    }
    cout<<max_sum<<" "<<num[left_index]<<" "<<num[right_index];
    system("pause");
    return 0;
}