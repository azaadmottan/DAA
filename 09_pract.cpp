#include<iostream>
using namespace std;

const int INFINITE = 10000;
int **matrix, nodes;

void dijkstra(int startNode)
{
    int **cost = new int *[nodes];
    for (int i = 0; i < nodes; i++)
    {
        cost[i] = new int[nodes]; 
    }
    
    int count, mindistance, nextnode; 
    int  *distance = new int [nodes], *predicisor = new int [nodes], *visited = new int [nodes];
    
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            if (matrix[i][j] == 0)
            {
                cost[i][j] = INFINITE;
            }
            else 
            {
                cost[i][j] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < nodes; i++)
    {
        distance[i] = cost[startNode][i];
        predicisor[i] = startNode;
        visited[i] = 0;
    }
    distance[startNode] = 0;
    visited[startNode] = 1;
    count = 1;

    while (count < nodes - 1)
    {
        mindistance = INFINITE;

        for (int i = 0; i < nodes; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
                
            }
        }

        visited[nextnode] = 1;

        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i])
            {
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    predicisor[i] = nextnode;
                }
            }
            // cout<<distance[i];
        }
        
        count++;
    }

    for (int i = 1; i < nodes; i++)
    {
        if (i != startNode)
        {
            cout<<"\nDistance of node ("<<i<<") : "<<distance[i];
            cout<<"\nPath : "<<i;

            int j = i;
            do
            {
                j = predicisor[j];
                cout<<"<--"<<j;
            } while (j != startNode);
            
            cout<<endl;
        }
    }
    
}



int main()
{
    system("cls");

    int fnode;

    cout<<"Enter the number of vertices : ";
    cin>>nodes;

    matrix =  new int *[nodes];
    for (int i = 0; i < nodes; i++)
    {
            matrix[i] = new int[nodes];
    }

    cout<<"\nEnter the elements of adjacency matrix\n";
    for (int i = 0; i < nodes; i++)
    {
        cout<<"\nEnter the element of row ("<<i+1<<") : ";
        for (int j = 0; j < nodes; j++)
        {
            cin>>matrix[i][j];
        }
    }

    cout<<"\nEnter the starting node : ";
    cin>>fnode;
    
    dijkstra(fnode);

    return 0;
}