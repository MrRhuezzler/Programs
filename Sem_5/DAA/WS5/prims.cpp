#include <iostream>
#include <climits>
#define V 5

int *MST(int graph[][V], int &cost)
{

    int *result = new int[V];
    int resultIndex = 0;
    cost = 0;

    int *minDistance = new int[V];
    int *hasBeenAdded = new int[V];

    for (int i = 0; i < V; i++)
    {
        minDistance[i] = INT_MAX;
        hasBeenAdded[i] = false;
    }
    minDistance[0] = 0;

    while (resultIndex < V)
    {
        // Get the vertex with the minimum distance
        int min = INT_MAX;
        int minIndex = -1;
        for (int j = 0; j < V; j++)
        {
            if (!hasBeenAdded[j] && minDistance[j] < min)
            {
                min = minDistance[j];
                minIndex = j;
            }
        }

        result[resultIndex++] = minIndex;
        hasBeenAdded[minIndex] = true;
        cost += min;

        // Update the distance of the adjacent vertices
        for (int k = 0; k < V; k++)
        {
            if (graph[minIndex][k] && !hasBeenAdded[k] && graph[minIndex][k] < minDistance[k])
            {
                minDistance[k] = graph[minIndex][k];
            }
        }
    }

    return result;
}

int main()
{

    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    
    int cost = 0;
    int* result = MST(graph, cost);
    for(int i = 0; i < V; i++)
    {
        std::cout << result[i] << " ";
    }

    std::cout << std::endl << cost << std::endl;

    return 0;
}