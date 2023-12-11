#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int *arr, int element, int begg, int end)
{
    int mid = (begg + end)/2;

    if (arr[mid] == element)
    {
        return mid;
    }
    else if (arr[mid] < element)
    {
        begg = mid + 1;
    }
    else if (arr[mid] > element)
    {
        end = mid - 1;
    }

    if (begg > end)
    {
        return -1;
    }
        
    return binarySearch(arr, element, begg, end);
    
}

int main()
{
    int size, search, begg = 0, end;

    cout<<"Enter the size of an array : ";
    cin>>size;

    int *arr = new int[size];
    
    cout<<"\nEnter the elements of an array : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"\nEneter element you want to search : ";
    cin>>search;

    std :: sort(arr, arr+size);

    cout<<"\nSorted array : ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    end = size-1;

    int position = binarySearch(arr, search, begg, end);

    if (position == -1)
    {
        cout<<"\n\nElement ("<<search<<") is not found !";
    }
    else
    {
        cout<<"\n\nElement ("<<search<<") is found at "<<position+1<<" position.";
    }
    

    return 0;
}