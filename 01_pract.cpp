#include<iostream>
using namespace std;

int linearSearch(int *arr, int size, int element)
{
    size--;

    if (size < 0)
    {
        return -1;
    }
    

    if (arr[size] == element)
    {
        return size;
    }
    
    return linearSearch(arr, size, element);
}

int main()
{
    int size, search;

    cout<<"Enter the size of an array : ";
    cin>>size;

    int *arr = new int[size];

    cout<<"\nEnter the elemets of an array : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    cout<<"\nEnter element you want to search : ";
    cin>>search;
    
    int position = linearSearch(arr, size, search);

    if (position == -1)
    {
        cout<<"\nElement not found !";
    }
    else 
    {
        cout<<"\nElement ("<<search<<") found at "<<position+1<<" position.";
    }
    

    return 0;
}