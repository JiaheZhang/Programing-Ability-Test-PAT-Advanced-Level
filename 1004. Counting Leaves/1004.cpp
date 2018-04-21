/*
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1
*/



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int num = 0;
    vector<int> child;
};

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    if(N == 1)
    {
        cout<<1;
        return 0;
    }
    vector<node>  v(N + 1);
    for(int i = 0;i < M;i++)//M lines input
    {
        int temp_id,k;
        scanf("%d%d",&temp_id,&k);
        v[temp_id].num = k;
        for(int j = 0;j < k;j++)//k children input
        {
            int temp_child_id;
            scanf("%d",&temp_child_id);
            v[temp_id].child.push_back(temp_child_id);
        }
    }

    queue<int>  q;
    int level = 0;
    vector<int> level_num(1);
    for(unsigned int i = 0;i < v[1].child.size();i++)//第一个人的孩子先入队列
    {
        q.push(v[1].child[i]);
    }
    while(!q.empty())
    {
        vector<int> children;
        while(!q.empty())//把队列中的孩子取出来
        {
            children.push_back(q.front());
            q.pop();
        }
        level++;//级别
        level_num.push_back(0);
        for(unsigned int i = 0;i < children.size();i++)
        {
            if(v[children[i]].num == 0)//判断是否有孩子
            {
                level_num[level]++;
            }
            for(unsigned int j = 0;j < v[children[i]].child.size();j++)//若有孩子 压入队列
            {
                q.push(v[children[i]].child[j]);
            }
            
        }
    }
    cout<<level_num[0];
    for(unsigned int i = 1;i < level_num.size();i++)
    {
        cout<<" "<<level_num[i];
    }
    /*
    int aa;
    cin>>aa;
    */
    return 0;
}