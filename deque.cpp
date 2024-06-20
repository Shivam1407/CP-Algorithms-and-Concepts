// deque (double-ended queue)

#include <deque>
using namespace std;

deque<int> myDeque; // Declaration of a deque of integers


//push_back: Adds an element to the end of the deque.
myDeque.push_back(10); // adds at the back 
myDeque.push_front(20); // adds at the front
myDeque.pop_back(); // Removes the last element from the deque.
myDeque.pop_front(); // removes first element of deque



int firstElement = myDeque.front(); // access first element 

int lastElement = myDeque.back(); // access lat element

int size = myDeque.size();


bool isEmpty = myDeque.empty();



