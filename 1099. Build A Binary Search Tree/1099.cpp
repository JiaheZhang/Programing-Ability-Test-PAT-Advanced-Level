/*
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.


Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.

Output Specification:

For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    int data = 0;
    int left_child = -1;
    int right_child = -1;
};

//中序搜索 递归
void mid_search(vector<node>& tree,int index,vector<int>& data,int& data_index)
{
    if(tree[index].left_child != -1)
    {
        mid_search(tree,tree[index].left_child,data,data_index);
    }

    tree[index].data = data[data_index++];

    if(tree[index].right_child != -1)
    {
        mid_search(tree,tree[index].right_child,data,data_index);
    }
    
}

//BFS
void bfs(vector<node>& tree,vector<int>& order,queue<int>& que)
{
    vector<int> temp;
    int a;
    if(que.empty())  return;
    while(!que.empty())
    {
        a = que.front();
        que.pop();
        order.push_back(a);
        temp.push_back(a);
    }
    for(unsigned int i = 0;i < temp.size();i++)
    {
        if(tree[temp[i]].left_child != -1)  que.push(tree[temp[i]].left_child);
        if(tree[temp[i]].right_child != -1)  que.push(tree[temp[i]].right_child);
    }
    bfs(tree,order,que);
}

int main()
{
    int N;
    cin>>N;
    vector<node> tree_meb(N);
    vector<int> num(N);
    int num_index = 0;
    vector<int> bfs_order;
    queue<int> bfs_que;
    for(int i = 0;i < N;i++)
    {
        cin>>tree_meb[i].left_child>>tree_meb[i].right_child;
    }
    for(int i = 0;i < N;i++)
    {
        cin>>num[i];
    }
    sort(num.begin(),num.end());

    //中序遍历
    mid_search(tree_meb,0,num,num_index);

    //BFS
    bfs_que.push(0);
    bfs(tree_meb,bfs_order,bfs_que);

    cout<<tree_meb[bfs_order[0]].data;
    for(int i = 1;i < N;i++)
    {
        cout<<" "<<tree_meb[bfs_order[i]].data;
    }


    system("pause");
    return 0;
}
