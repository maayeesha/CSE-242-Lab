#include<bits/stdc++.h>
using namespace std;

struct listNode
{
    int dest;
    listNode* next;
};

struct adjList
{
    listNode* head;
};

struct Graph
{
    int v;
    adjList* arr;
};

listNode* newAdjListNode(int dest)
{
    listNode* newNode = new listNode;
    newNode->dest = dest;
    newNode->next = nullptr;
    return newNode;
}

Graph* createGrap(int v)
{
    Graph* graph = new Graph;
    graph->v = v;
    graph->arr = new adjList;
    int i;
    for(i=0; i<v; i++)
    {
        graph->arr[i].head = nullptr;
    }
}

int main()
{

}
