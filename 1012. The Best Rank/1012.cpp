/*
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output

For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output "N/A".

Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const char my_map[4] = {'A','C','M','E'};

int main()
{
    int N,K;
    vector<int> grade(4);
    string ID;
    cin>>N>>K;
    map<string,vector<int> > stu;
    for(int i = 0;i < N;i++)
    {
        cin>>ID>>grade[1]>>grade[2]>>grade[3];
        grade[0] = (grade[1] + grade[2] + grade[3]) / 3;
        stu[ID] = grade;
    }

    auto it = stu.begin();
    auto iter = stu.begin();
    int rank = N + 1;//初试一个大于人数的值
    int prior;//等级
    int temp_rank = 1;
    for(int i = 0;i < K;i++)
    {
        cin>>ID;
        it = stu.find(ID);
        if(it != stu.end())
        {
            rank = N + 1;
            for(int j = 0;j < 4;j++)
            {
                temp_rank = 1;
                for(iter = stu.begin();iter != stu.end();iter++)
                {
                    if(iter->second[j] > it->second[j])
                    {
                        temp_rank++;
                    }
                }
                if(temp_rank < rank)
                {
                    rank = temp_rank;
                    prior = j;
                }
            }
            cout<<rank<<" "<<my_map[prior]<<endl;
            
        }
        else//不存在这个学生
        {
            cout<<"N/A"<<endl;
        }
    }
    system("pause");
    return 0;
}