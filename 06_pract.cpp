#include<iostream>
using namespace std;

int numItem;
float wtKnap, maxProfit = 0.0;

float *wt = new float [numItem];
float *profit = new float [numItem];

class fractKnap                                     // Max-profit (fractional Knapsack)
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
    cout<<"Enter the size of knapsack : ";
    cin>>wtKnap;

    cout<<"\nEnter the number of items : ";
    cin>>numItem;

    cout<<"\nEnter the weight and profit of each item\n";

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
            if (profit[j] < profit[j+1])
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
    for (int i = 0; i < numItem-1; i++)
    {
        if (wtKnap == 0.0)
        {
            break;
        }

        if (wt[i] <= wtKnap)
        {
            maxProfit += profit[i];
            wtKnap -= wt[i];
        }
        else 
        {
            // cout<<profit[i]<<endl;
            // cout<<wtKnap<<endl;
            // cout<<wt[i];

            maxProfit += (profit[i] * wtKnap / wt[i]);
            wtKnap = 0.0;
        }
    }
}

void fractKnap :: displayData()
{
    cout<<"\nMAX PROFIT : "<<maxProfit;
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