#include <bits/stdc++.h>
using namespace std;

class heap
{
    int arr[100]; // _ _ _ _ _ _  _ _  _ _ _ _  upto 100
    int size;

public:
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    void insert(int val)
    {
        size++;           // size = 1;   size = 2                size = 3             size = 4                                                               size = 5
        int index = size; // index = 1    index = 2              index = 3             index = 4                                                             index = 5
        arr[index] = val; // -1 0 _ _ _ _ _ _ _    // -1 0 1     // -1 1 0 2           // -1 2 0 1 3                                                          //-1 3 2 0 1 4
        while (index > 1) // as index = 1
        {
            int parent = index / 2;       // parent = 1         parent = 1                                 parent = 2          // parent = 1                          // parent = 2      parent = 1
            if (arr[index] > arr[parent]) // 1 > 0              2>1                                        3>0                   3>2                                 4>2                4>3
            {
                swap(arr[index], arr[parent]); // -1 1 0          // -1 2 0 1                         // -1 2 3 1 0         // -1 3 2 1 0                        -1 3 4 1 0 2            -1 4 3 1 0 2
                index = parent;                // index = 1       // index = 1                        index = 2             index = 1                              index = 2              index = 1
            }
            else
            {
                return;
            }
        }
    }
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    void deleteFromHeap()
    // whenever i am talking abot deleting a value from priority code it is the root->val.
    {
        if (size == 0)
            cout << "nothing to delete" << endl;

        // step 1: we will replace root val with last node value
        arr[1] = arr[size];

        // step2 : remove the last element
        size--;
        int i = 1; // TC ------    step 1 O(1)
        //                step 2 O(1)
        //                step 3 O(logN);

        // take root node to its correct positoion
        while (i < size)
        {
            int right = 2 * i + 1;
            int left = 2 * i;
            if (right < size and arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else if (left < size and arr[i] < arr[left])
            {
                swap(arr[i], arr[right]);
                i = left;
            }
            else
            {
                return;
            }

            // 4 3 1 0 2
            // 1 3 2 0
        }
    }
};
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
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
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, n, 1);
    }
}
int main()
{
    heap h;
    h.insert(0); // time complexity = O(logN)
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.print();

    h.deleteFromHeap();
    h.print();

    int n = 5;
    int arr[6] = {-1, 1, 2, 4, 0, 100};

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the Array:" << " ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    return 0;
}

//        

