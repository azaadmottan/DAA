#include<iostream>
using namespace std;

// int **graph, edge[10][2];
int **graph, **edge;

int bellman(int vertex, int k)
{
    int flag = 1, source;
    int *distance = new int [vertex];
    int *parent = new int [vertex];

    for (int i = 0; i < vertex; i++)
    {
        distance[i] = 10000;
        parent[i] = -1;
    }
    
    cout<<"\nEnter source vertex : ";
    cin>>source;

    distance[source] = 0;

    for (int i = 0; i < vertex - 1; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int u = edge[j][0], v = edge[j][1];
            if (distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        int u = edge[i][0], v = edge[i][1];

        if (distance[u] + graph[u][v] < distance[v])
        {
            flag = 0;
        }
    }

    if (flag)        
    {
        for (int i = 0; i < vertex; i++)
        {
            cout<<"\nVertex "<<i<<" --> cost : "<<distance[i]<<"\tParent : "<<parent[i];
        }
    }

    return flag;
}

int main()
{
    system("cls");
    int vertex, E, k = 0;

    cout<<"Enter the number of vertex : ";
    cin>>vertex;

    graph = new int *[vertex];
    for (int i = 0; i < vertex; i++)
    {
        graph[i] = new int [vertex];
    }
    cout<<"\nEnter the number of edges : ";
    cin>>E;

    edge = new int *[E];
    for (int i = 0; i < E; i++)
    {
        edge[i] = new int [2];
    }

    cout<<"Enter the adjacency matrix\n";
    for (int i = 0; i < vertex; i++)
    {
        cout<<"\nEnter the elements of row ("<<i+1<<") : ";
        for (int j = 0; j < vertex; j++)
        {
            cin>>graph[i][j];
            if (graph[i][j] != 0)
            {
                edge[k][0] = i;
                edge[k++][1] = j; 
            }
            
        }
    }

    if (bellman(vertex, k))
    {
        cout<<"\n\nNo negative weight cycle exist !";
    }
    else 
    {
        cout<<"\nNegative weight cycle exist !";
    }
       

    
    return 0;
}