/*
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.

Input

Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output

For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1000
int N,M,K;
bool v[MAX][MAX];//i到j是否连通
int set_v[MAX];

void bfs(int occupy,queue<int>& q,int num)
{
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        set_v[temp] = num;//入集合
        for(int i = 0;i < N;i++)
        {
            if(i != occupy && set_v[i] != num)//没有堵塞 也没有进集合
            {
                if(v[temp][i]) 
                {
                    q.push(i);//若连通 则入队列
                    //一开始最后一个测试超时 加了这句就过了
                    set_v[i] = num;//入集合
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&N,&M,&K);
    int a,b;
    queue<int> que;
    int set_num = 0;
    for(int i = 0;i < M;i++)
    {
        scanf("%d%d",&a,&b);
        v[a-1][b-1] = true;
        v[b-1][a-1] = true;
    }
    for(int i = 0;i < K;i++)
    {
        for(int i = 0;i < N;i++)
        {
            set_v[i] = -1;//初始化为-1 代表没进入集合
        }
        scanf("%d",&a);
        set_num = 0;
        --a;
        for(int i = 0;i < N;i++)
        {
            if(i != a && set_v[i] == -1)//没有被堵塞 并且还没有进集合
            {
                que.push(i);
                bfs(a,que,set_num++);
            }
        }
        cout<<set_num - 1<<endl;
        
    }
    system("pause");
    return 0;
}
