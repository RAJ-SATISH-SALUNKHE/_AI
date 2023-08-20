#include <stdio.h>
#include <iostream>
#include <vector>

int i,j;
int visited[] = {0,0,0,0,0,0};
int graph[][6] = {{0,1,1,1,0,0},{0,0,0,0,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1},{0,0,0,0,0,0},{0,0,1,0,0,0}};
std::vector<int> vec;
int vertex = 0;



void BFS()
{
    visited[vertex] = 1;
    for(int i=0; i<6; i++)
    {
        if(!visited[i] && graph[vertex][i]==1)
        {
            vec.push_back(i);
        }
    }
    printf("%d\t", vec.front());
    vec.erase(vec.begin());
    if(vertex<5)
    {
        vertex++;
        BFS();
    }

}

void DFS(int vertex)
{
    while(!vec.empty())
    {
        printf("%d\t", vec.back());
        vec.erase(vec.end());
        for(int i=0; i<6; i++)
        {
            if(!visited[i] && graph[vertex][i]==1)
            {
                vec.push_back(i);
                visited[i]=1;
            }
        }
        DFS(vec.back());
    }
}

void DFS2(int vertex)
{
    visited[vertex]=1;
    printf("%d\t", vertex);

    for (int i = 0; i < 6; i++)
    {
        if (!visited[i] && graph[vertex][i] == 1)
        {
            vec.push_back(i);
            DFS2(i);
        }
    }
}

int main()
{
    printf
    printf("The DFS search for the given graph is : \n");
    vec.push_back(vertex);
    DFS2(0);
    return 0;
}
