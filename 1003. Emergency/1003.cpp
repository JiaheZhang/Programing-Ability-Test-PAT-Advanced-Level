/*
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/ 

#include<iostream>
#include<vector>
#include<stdio.h> 

#define INF 999999999
#define MAXNUM 500

using namespace std;

int N;
int dist[MAXNUM];//储存v0到i的最短距离
int handAmount[MAXNUM]; //从v0到i能获得的最多的营救队
int roadAmount[MAXNUM]; //最短路径的条数 
int v[MAXNUM][MAXNUM];//地图 边 
int hand[MAXNUM];//the number of rescue teams
bool S[MAXNUM];//集合 

void Dijkstra(int v0)
{
    S[v0] = true;
    handAmount[v0] = hand[v0];
    dist[v0] = 0;
    
    
    for(int i = 0;i < N;i++)
    {
        dist[i] = v[v0][i];
        if(dist[i] != INF && i != v0)
        {
            handAmount[i] = hand[i] + handAmount[v0];//若连同 则可获得i和v0 
        }
    } 
    
    
    
    for(int k = 0;k < N;k++)
    {
        int minDist = MAXNUM;
        int u; 
    
        for(int i = 0;i < N;i++)//找到dist中最小的 
        {
            if(!S[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }
        S[u] = true;//将u放入S集合 
        for(int i = 0;i < N;i++)//更新dist中其余的 
        {
            if(!S[i] && dist[u] + v[u][i] < dist[i])
            {
                dist[i] = dist[u] + v[u][i];//更新路径
                handAmount[i] = hand[i] + handAmount[u]; //更新从v0到i的营救队
                roadAmount[i] = roadAmount[u];//更新路径条数
            }
            else if(!S[i] && dist[u] + v[u][i] == dist[i])//存在相等的路径 
            {
                roadAmount[i] += roadAmount[u];
                if(hand[i] + handAmount[u] > handAmount[i])//如果能获得更多的营救队 
                {
                    handAmount[i] = hand[i] + handAmount[u];
                }
            } 
             
        } 
    }
    
    
    
}

int main()
{

    scanf("%d",&N);
    
    for(int i = 0;i < N;i++) //initialize
    {
    	for(int j = 0;j < N;j++)
    	{
            v[i][j] = INF;
            v[j][i] = INF;
        }
        dist[i] = INF;
        roadAmount[i] = 1;
    	
    }
    
    int m;
    scanf("%d",&m);
    int orig,dest;//出发地与目的地 
    scanf("%d%d",&orig,&dest);
    
    int temp;
    for(int i = 0;i < N;i++)
    {
    	scanf("%d",&temp);
    	hand[i] = temp;
    }
    
    int i,j;
    for(int k = 0;k < m;k++)
    {
    	scanf("%d%d%d",&i,&j,&temp);
    	v[i][j] = temp;
    	v[j][i] = temp;
    }
    
    Dijkstra(orig);
    cout<<roadAmount[dest]<<" "<<handAmount[dest];
    
    cin.get();
    cin.get();
    return 0;
}


 
 
 
 
 
