#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)                                 
{
    int largest = i;                                                 
    int left = 2 * i;                                                
    int right = 2 * i + 1;                                             

    if (left <= n and arr[largest] < arr[left])
    {
        largest = left;                                                                   
    }
    else if (right <= n and arr[largest] < arr[right])
    {
        largest = right;                                                
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);                               
        heapify(arr, n, largest);                    
    }
}


void heapSort(int arr[], int n)
{
    int size = n;

    

    while(size>1)
    {
        swap(arr[n], arr[1]);
        size--;

        heapify(arr, n, 1);
    }
}


int main()
{
    int n = 5;
    int arr[6] = {-1, 57, 53, 55, 52, 56};

    for (int i = n / 2; i >0; i--)
    {
        heapify(arr, n, i);
    }

    heapSort(arr, n);

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}