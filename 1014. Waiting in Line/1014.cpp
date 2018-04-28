/*
Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:

The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
Customer[i] will take T[i] minutes to have his/her transaction processed.
The first N customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 customers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer1 is served at window1 while customer2 is served at window2. Customer3 will wait in front of window1 and customer4 will wait in front of window2. Customer5 will wait behind the yellow line.

At 08:01, customer1 is done and customer5 enters the line in front of window1 since that line seems shorter now. Customer2 will leave at 08:02, customer4 at 08:06, customer3 at 08:07, and finally customer5 at 08:10.

Input

Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (<=20, number of windows), M (<=10, the maximum capacity of each line inside the yellow line), K (<=1000, number of customers), and Q (<=1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.

Output

For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output "Sorry" instead.

Sample Input
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output
08:07
08:06
08:10
17:00
Sorry
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int N,M,K,Q;
vector<int> T;//time cost of each customer

int search_min_line(vector<queue<int> >& q)
{
    int min_line = -1;
    unsigned int min = M;
    for(int i = 0;i < N;i++)
    {
        if(q[i].size() < min)//当队列排满时 size等于min
        {
            min = q[i].size();
            min_line = i;
        }
    }
    return min_line;//-1代表都满了
}
int search_min_wait(vector<queue<int> >& q)//寻找排队中最先完成的
{
    int min = 999999;
    int min_wait_line = 0;
    for(int i = 0;i < N;i++)
    {
        if(!q[i].empty())
        {
            if(T[q[i].front()] < min)
            {
                min = T[q[i].front()];
                min_wait_line = i;
            }
        }
        
    }
    return min_wait_line;
}

string transfer_time(int time)
{
    int hour = 8 + time / 60;
    int minute = time % 60;
    string str_hour,str_min;
    if(hour < 10) str_hour = "0"+to_string(hour);
    else str_hour = to_string(hour);

    if(minute < 10) str_min = "0"+to_string(minute);
    else str_min = to_string(minute);

    return str_hour + ":" + str_min;
}

int main()
{
    cin>>N>>M>>K>>Q;
    vector<int> cost_time(K);
    queue<int> wait_que;
    vector<queue<int> > vq(N);//N个窗口
    int temp_t;
    int Q_id;
    vector<int> line_cost(N);
    for(int i = 0;i < K;i++)
    {
        cin>>temp_t;
        T.push_back(temp_t);
        wait_que.push(i);
    }
    vector<int> T2(T);
    int line;
    int customer;
    int finsh_num = 0;
    while(true)
    {
        if(finsh_num >= K) break;
        while(!wait_que.empty())
        {
            line = search_min_line(vq);
            if(line >= 0)//黄色内有人可以进去排队
            {
                customer = wait_que.front();
                wait_que.pop();
                vq[line].push(customer);//进去排队
            }
            else break;//直到队列排满
        }
        line = search_min_wait(vq);
        customer = vq[line].front();
        temp_t = T[customer];
        for(int i = 0;i < N;i++)
        {
            line_cost[i] += temp_t;
        }
        for(int i = 0;i < N;i++)
        {
            if(!vq[i].empty())
            {
                T[vq[i].front()] -= temp_t;
            }
        }
        vq[line].pop();
        cost_time[customer] = line_cost[line];
        finsh_num++;
    }
    for(int i = 0;i < Q;i++)
    {
        cin>>Q_id;
        if(cost_time[Q_id - 1] -  T2[Q_id - 1] >= 540) cout<<"Sorry"<<endl;
        else cout<<transfer_time(cost_time[Q_id - 1])<<endl;
    }
    system("pause");


    return 0;
}