#include <bits/stdc++.h>
using namespace std;





int main()
{
    priority_queue<int> maxHeap;
    maxHeap.push(4);
    maxHeap.push(45); //log(n)
    maxHeap.push(9);  
    maxHeap.push(3);
    maxHeap.push(0);

    cout << maxHeap.top() << endl; // log(n)
    maxHeap.pop();   //O(1)
    cout << maxHeap.top() << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(45); // log(n)
    minHeap.push(9);
    minHeap.push(3);
    minHeap.push(0);

    cout << minHeap.top() << endl; // log(n)
    minHeap.pop();                 // O(1)
    cout << minHeap.top() << endl;

    return 0;
}