#include<iostream>
using namespace std;

// int arr[10][10], completed[10], n, cost = 0;
int n, cost = 0;
int **arr, *completed;

void input()
{
    cout<<"Enter the number of items : ";
    cin>>n;

    arr = new int*[n];
    completed = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i] = new int[n];
        }
        
    }
    
    cout<<"\n\tEnter the cost of matrix\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"\nEnter the element of row ("<<i+1<<") : ";
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        completed[i] = 0;
    }   

    cout<<"\nThe cost of matrix : \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"\t";
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;        
    }
    
}

int least(int p)
{
    int i, nc = 999, min = 999, kmin;

    for (int i = 0; i < n; i++)
    {
        if ((arr[p][i] != 0) && (completed[i] == 0))
        {
            if ((arr[p][i] + arr[i][p]) < min)
            {
                min = arr[i][0] + arr[p][i];
                kmin = arr[p][i];
                nc = i;
            }
        }
    }

    if (min != 999)
    {
        cost += kmin;
    }
    
    return nc;
}

void minCost(int city)
{
    int i, nCity;

    completed[city] = 1;

    cout<<city+1<<"-->";

    nCity = least(city);

    if (nCity == 999)
    {
        nCity = 0;
        cout<<nCity+1;

        cost += arr[city][nCity];
        return;
    }
    minCost(nCity);    
}

int main()
{
    input();

    cout<<"\nThe Shortest Path : ";
    minCost(0);

    cout<<"\nMinimum Cost : "<<cost;

    return 0;
}