#include<iostream>
using namespace std;

int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int knapSack(int n, int knapwight, int wt[], int profit[])      // 0/1 Knapsack
{
    int j, p = 0;

    int **knaprofit = new int *[n];
    for (int i = 0; i <= n; i++)
    {
        knaprofit[i] = new int [knapwight];
    }
    for (int i = 0; i <= n; i++)
    {
        for (j = 0; j <= knapwight; j++)
        {
            if (i == 0 || j == 0)
            {
                knaprofit[i][j] = 0;
            }
            else if (wt[i-1] <= j)
            {
                knaprofit[i][j] = max((profit[i - 1] + knaprofit[i - 1][j - wt[i - 1]]), (knaprofit[i - 1][j]));
            // cout<<"hello";
            }
            else 
            {
                knaprofit[i][j] = knaprofit[i - 1][j];
            }
        }
    }

    cout<<"\nKnapsack Table : \n\n";
    cout<<"|W P|";
    for (int i = 0; i <= n; i++)
    {
        if (i > 0 )
        {
            cout<<"|"<<wt[p]<<" "<<profit[p]<<"|";
            p++;
        }
        for (int k = 0; k <= knapwight; k++)
        {
            
            cout<<"\t"<<knaprofit[i][k]<<" ";
        }
        cout<<endl;
    }
    

    return knaprofit[n][knapwight];    
}

int main()
{
    system("cls");
    int n, knapWeight;

    cout<<"Enter the number of items: ";
    cin>>n;

    cout<<"\nEnter the weight of knapsack: ";
    cin>>knapWeight;

    int *wt = new int [n];
    int *profit = new int [n];

    cout<<"\nEnter the weight of items: ";
    for (int i = 0; i < n; i++)
    {
        cin>>wt[i];
    }
    cout<<"\nEnter the profit of items: ";
    for (int i = 0; i < n; i++)
    {
        cin>>profit[i];
    }

    int result = knapSack(n, knapWeight, wt, profit);
    cout<<"\nMaximum profit: "<<result;

    return 0;
}