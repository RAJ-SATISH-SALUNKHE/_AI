#include <stdio.h>
#include <vector>
#include <algorithm>


std::vector<int>opened;
std::vector<int>path;

std::vector<int>mini;

int vertex = 0;
int parentVertex;
int i=0, j=0;
int minVertex;

int heuristic[] = {10,8,5,7,3,6,5,3,1,0};
//int visited[] = {0,0,0,0,0,0,0,0,0,0};

int lookUpTable[] = {0,0,0,0,0,0,0,0,0,0};
//                   0 1 2 3 4 5 6 7 8 9
int graph[][10] =  {{0,6,0,0,0,3,0,0,0,0}, //0
                    {0,0,3,2,0,0,0,0,0,0}, //1
                    {0,0,0,1,5,0,0,0,0,0}, //2
                    {0,0,0,0,8,0,0,0,0,0}, //3
                    {0,0,0,0,0,0,0,0,5,5}, //4
                    {0,0,0,0,0,0,1,7,0,0}, //5
                    {0,0,0,0,0,0,0,0,3,0}, //6
                    {0,0,0,0,0,0,0,0,2,0}, //7
                    {0,0,0,0,0,0,0,0,0,3}, //8
                    {0,0,0,0,0,0,0,0,0,0}}; //9

int vertexCost(int vert)
{
    int initVertex = vert;
    int vCost=0;
    int parentVertex;
    while(vert != 0)
    {
        parentVertex = lookUpTable[vert];
        vCost += graph[parentVertex][vert];
        vert = parentVertex;
    }

    return vCost + heuristic[initVertex];
}

int findMinVertex(std::vector<int> vec)
{

    int minVertex = vec[0];
    int Vert;
    int minVertexCost = vertexCost(vec[0]);
    for(i=1; i<vec.size(); i++)
    {
        Vert = vertexCost(vec[i]);
        if(Vert < minVertexCost)
        {
            minVertexCost = Vert;
            minVertex = vec[i];
        }
    }
    return minVertex;
}

void aStar(int vertex)
{
    //printf("%d\n", vertex);
    if(vertex==9)return;

    auto it = std::find(opened.begin(), opened.end(), vertex);
    opened.erase(it);

    for(i=0; i<10; i++)
    {
        if(graph[vertex][i])
        {
            opened.push_back(i);
            lookUpTable[i] = vertex;
        }
    }

    /*
    printf("For expansion of vertex %d,  the opened list is : ", vertex);
    for(i=0; i<opened.size(); i++)
    {
        printf("%d-%d\t", opened[i], vertexCost(opened[i]));
    }
    */

    minVertex = findMinVertex(opened);
    //printf("Min vertex is %d \n", minVertex);
    aStar(minVertex);

}

int main()
{
    opened.push_back(vertex);
    aStar(vertex);

    printf("The optimum shortest path is : \n");

    vertex=9;
    while(vertex!=0)
    {
        path.push_back(vertex);
        vertex = lookUpTable[vertex];
    }
    path.push_back(0);
    for(i=0; i<path.size(); i++)
    {
        printf("%d\t", path[path.size()-i-1]);
    }
    printf("\n");
}

