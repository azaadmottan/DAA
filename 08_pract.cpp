#include<iostream>
using namespace std;

int matrixChainMultiplication(int *arr, int n)
{
    int order[50][50], MAX = 200000;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            order[i][j] = 0;
        }
        
        // order[i][i] = 0;
    }
    

    for (int m = 2; m < n; m++) 
    {
        for (int i = 1; i < (n - m) + 1; i++)
        {
            int k = i + m - 1;
            order[i][k] = MAX;

            for (int j = i; j <= k-1; j++)
            {
                int ans = order[i][j] + order[j + 1][k] + arr[i - 1] * arr[j] * arr[k];

                if (ans < order[i][k])
                {
                    order[i][k] = ans;
                }
            }
        }
    }

    cout<<"\nGiven Matrix : \n\n";
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout<<"\t"<<order[i][j];
        }
        cout<<endl;
    }
        

    return order[1][n - 1];
}

int main()
{
    system("cls");

    int size;

    cout<<"Enter the number of matrix : ";
    cin>>size;
    size++;

    int *arr = new int[size];

    cout<<"\nEnter the order of matrix : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    int order = matrixChainMultiplication(arr, size);

    cout<<"\nMinimum number of matrix multiplications: "<<order;

    return 0;
}