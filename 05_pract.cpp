#include<iostream>
using namespace std;

// float numItem, wtKnap, items, w, wt[20], profit[20], p[20], maxProfit = 0.0;
int items;
float numItem, wtKnap, w, maxProfit = 0.0;

float *wt = new float [items];
float *profit = new float [items];
float *p = new float [items];

class fractKnap                                 // Profit-weight ratio (fractional Knapsack)
{
    public : 
        void getData();
        void sortData();
        void calculation();
        void displayData();
};

void fractKnap :: getData()
{
    system("cls");
    
    cout<<"Enter the weight of knapsack : ";
    cin>>wtKnap;

    cout<<"\nEnter the number of items : ";
    cin>>numItem;

    cout<<"\nEnter the weight and profit of each item of knapsack\n";

    cout<<endl;
    for (int i = 0; i < numItem; i++)
    {
        cout<<"Enter the weight of ("<<i+1<<") item : ";
        cin>>wt[i];
    }
    cout<<endl;
    for (int i = 0; i < numItem; i++)
    {
        cout<<"Enter the profit of ("<<i+1<<") item : ";
        cin>>profit[i];
    }

}

void fractKnap :: sortData()
{
    for (int i = 0; i < numItem; i++)
    {
        for (int j = 0; j < numItem-1; j++)
        {
            if ((profit[j] / wt[j]) < (profit[j+1] / wt[j+1]))
            {
                int temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                temp = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = temp;
            }
        }
    }
}

void fractKnap :: calculation()
{
    for (int i = 0; i < numItem; i++)
    {
        p[i] = 0.0;
    }
    w = wtKnap;

    int r;
    for (r = 0; r < numItem; r++)
    {
        if (wt[r] > w)
        {
            break;
        }
        p[r] = 1.0;
        w -= wt[r];
        
    }

    if (r < numItem)
    {
        p[r] = w / wt[r];
    }

    for (int i = 0; i < numItem; i++)
    {
        maxProfit += profit[i] * p[i];
    }
}

void fractKnap :: displayData()
{
    cout<<"\nMax Profit : "<<maxProfit;
}

int main()
{
    fractKnap obj;

    obj.getData();
    obj.sortData();
    obj.calculation();
    obj.displayData();

    return 0;
}