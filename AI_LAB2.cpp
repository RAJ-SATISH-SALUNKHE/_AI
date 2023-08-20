#include <stdio.h>
#include <iostream>
#include <vector>

int i,j;
int visited[] = {0,0,0,0,0,0};
//int graph[][6] = {{0,1,1,1,0,0},{0,0,0,0,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1},{0,0,0,0,0,0},{0,0,1,0,0,0}};
/*
int graph[][8] = {{0,1,1,0,0,0,0,1},
                  {0,0,0,0,1,0,0,0},
                  {0,0,0,1,1,0,0,0},
                  {0,0,0,0,0,1,1,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,1,0}};
*/


int graph[][8] = {{0,1,0,1,0,0,0,0},
                  {0,0,1,0,0,0,0,0},
                  {0,0,0,1,0,1,0,0},
                  {0,0,0,0,1,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,1,0,1,0},
                  {0,0,0,0,0,0,0,1},
                  {0,0,0,0,0,0,0,0}};
std::vector<int> vec;
std::vector<int> vec2;
std::vector<int> vec3;
int vertex = 0;



void BFS2()
{
    while(!vec.empty())
    {
        //visited[vertex] = 1;
        for(int i=0; i<8; i++)
        {
            if(!visited[i] && graph[vertex][i]==1)
            {
                vec.push_back(i);
                visited[i] = 1;
            }
        }
        printf("%d\t", vec.front());
        vec.erase(vec.begin());
        vertex = vec.front();
        BFS2();
    }
}

void DFS(int vertex)
{
    while(!vec2.empty())
    {
        printf("%d\t", vec2.back());
        vertex = vec2.back();
        vec2.pop_back();
        for(int i=0; i<8; i++)
        {
            if(!visited[i] && graph[vertex][i]==1)
            {
                vec2.push_back(i);
                visited[i]=1;
            }
        }
        DFS(vec2.back());
    }
}

void DFS2(int vertex)
{
    visited[vertex]=1;
    printf("%d\t", vertex);

    for (int i = 0; i < 8; i++)
    {
        if (!visited[i] && graph[vertex][i] == 1)
        {
            vec2.push_back(i);
            DFS2(i);
        }
    }
}

int main()
{
    printf("The BFS search for the given graph is : \n");
    vec.push_back(vertex);
    visited[0]=1;
    BFS2();
    //****************************************************************************************
    vertex = 0;
    printf("\n");
    for(i=0; i<8; i++)
    {
        visited[i] = 0;
    }
    printf("The DFS search for the given graph is : \n");
    vec2.push_back(vertex);
    visited[0]=1; //for DFS()
    DFS(0); //for DFS

    return 0;
}

